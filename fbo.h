#define _USE_MATH_DEFINES
#include <cmath>

#define GLEW_STATIC
#include <GL/glew.h>

#include <string>
#include <vector>
using namespace std;

#include "helper.h"
#include "textures.h"

#ifndef FBO_H_
#define FBO_H_

const int NUM_ATTACHMENTS = 3;

class FBO {
 public:
  FBO(int width, int height);
  ~FBO();

  void BindToShader(GLuint shaderProgram);
  GLuint GetFrameBuffer() const;
  Texture GetAttachment(int i) const;
  Texture GetDepth() const;
  void Render() const;

 private:
  GLuint fbo, vbo, vao;
  Texture attachments[NUM_ATTACHMENTS];
  Texture depth;

 private: // disable copying
  FBO(const FBO& that) = delete;
  FBO& operator = (const FBO &that) = delete;
};

#endif
