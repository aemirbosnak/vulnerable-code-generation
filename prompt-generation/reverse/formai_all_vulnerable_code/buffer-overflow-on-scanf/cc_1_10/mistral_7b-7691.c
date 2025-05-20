//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct { double real, imag; } complex;

void print_complex(complex z) {
  char sign[2];
  if (z.imag >= 0.0) {
    strcpy(sign, "");
  } else {
    strcpy(sign, "-");
  }
  printf("%s%.2f + %.2fi", sign, z.real, z.imag);
}

complex add_complex(complex a, complex b) {
  complex c = {a.real + b.real, a.imag + b.imag};
  return c;
}

complex sub_complex(complex a, complex b) {
  complex c = {a.real - b.real, a.imag - b.imag};
  return c;
}

complex mul_complex(complex a, complex b) {
  complex c = {
      a.real * b.real - a.imag * b.imag,
      a.real * b.imag + a.imag * b.real,
  };
  return c;
}

complex pow_complex(complex a, int p) {
  complex result = {1.0, 0.0};
  for (int i = 0; i < p; i++) {
    result = mul_complex(result, a);
  }
  return result;
}

int main() {
  complex a = {2.0, 3.0};
  complex b = {1.0, -2.0};
  complex c, d;

  printf("a = ");
  print_complex(a);
  printf("\nb = ");
  print_complex(b);

  c = add_complex(a, b);
  printf("\nSum: ");
  print_complex(c);

  d = sub_complex(a, b);
  printf("\nDifference: ");
  print_complex(d);

  c = mul_complex(a, b);
  printf("\nProduct: ");
  print_complex(c);

  int pow_num;
  printf("\nEnter the power of a: ");
  scanf("%d", &pow_num);

  c = pow_complex(a, pow_num);
  printf("\nResult: ");
  print_complex(c);

  return 0;
}