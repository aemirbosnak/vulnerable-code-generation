//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct { double real, imag; } complex;

void square_complex(complex *z) {
  complex result;
  result.real = pow(z->real, 2) - pow(z->imag, 2);
  result.imag = 2 * z->real * z->imag;
  *z = result;
}

void print_complex(complex z) {
  char str[100];
  if (z.imag >= 0) {
    sprintf(str, "%.2f + %.2fi", z.real, z.imag);
  } else {
    sprintf(str, "%.2f - %.2fi", z.real, fabs(z.imag));
  }
  printf("%s\n", str);
}

int main(int argc, char *argv[]) {
  complex z1 = {3.0, 4.0};
  complex z2 = {1.0, 2.0};
  complex z3;

  printf("First complex number: ");
  print_complex(z1);

  printf("\nSquare of first complex number: ");
  square_complex(&z1);
  print_complex(z1);

  printf("\nAdding two complex numbers: ");
  z3.real = z1.real + z2.real;
  z3.imag = z1.imag + z2.imag;
  print_complex(z3);

  printf("\nSubtracting second complex number from first: ");
  z3.real = z1.real - z2.real;
  z3.imag = z1.imag - z2.imag;
  print_complex(z3);

  printf("\nMultiplying two complex numbers: ");
  complex z4 = {0.0, 0.0};
  z4.real = z1.real * z2.real - z1.imag * z2.imag;
  z4.imag = z1.real * z2.imag + z1.imag * z2.real;
  print_complex(z4);

  printf("\nEnter two complex numbers (format: real part space imag part): ");
  complex z5, z6;
  scanf("%lf %lf %lf %lf", &z5.real, &z5.imag, &z6.real, &z6.imag);
  complex z7 = {z5.real + z6.real, z5.imag + z6.imag};
  print_complex(z7);

  printf("\nEnter a complex number (format: real part space imag part or real part followed by i for imaginary part): ");
  complex z8;
  scanf("%lf %*s %*c", &z8.real);
  if (scanf("%lf", &z8.imag) != 1) {
    z8.imag = 0;
  }
  print_complex(z8);

  return EXIT_SUCCESS;
}