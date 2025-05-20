#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Complex {
  int real;
  int img;
} Complex;

Complex complex_add(Complex a, Complex b) {
  Complex c;
  c.real = a.real + b.real;
  c.img = a.img + b.img;
  return c;
}

int main() {
  Complex a, b, c;
  a.real = 1000000000;
  a.img = 1000000000;
  b.real = 1000000000;
  b.img = 1000000000;

  c = complex_add(a, b);

  printf("The result is: %.2lf + %.2lfi\n", c.real, c.img);

  return 0;
}
