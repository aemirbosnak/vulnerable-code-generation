//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct complex_number {
  double real;
  double imaginary;
} complex_number;

void add_complex_numbers(complex_number *a, complex_number *b, complex_number *result) {
  result->real = a->real + b->real;
  result->imaginary = a->imaginary + b->imaginary;
}

void subtract_complex_numbers(complex_number *a, complex_number *b, complex_number *result) {
  result->real = a->real - b->real;
  result->imaginary = a->imaginary - b->imaginary;
}

void multiply_complex_numbers(complex_number *a, complex_number *b, complex_number *result) {
  double real_part = a->real * b->real - a->imaginary * b->imaginary;
  double imaginary_part = a->real * b->imaginary + a->imaginary * b->real;
  result->real = real_part;
  result->imaginary = imaginary_part;
}

void divide_complex_numbers(complex_number *a, complex_number *b, complex_number *result) {
  double denominator = b->real * b->real + b->imaginary * b->imaginary;
  result->real = (a->real * b->real + a->imaginary * b->imaginary) / denominator;
  result->imaginary = (a->imaginary * b->real - a->real * b->imaginary) / denominator;
}

void print_complex_number(complex_number *a) {
  printf("%f + %fi\n", a->real, a->imaginary);
}

int main() {
  complex_number a;
  complex_number b;
  complex_number result;

  printf("Enter the first complex number (a + bi): ");
  scanf("%lf + %lfi", &a.real, &a.imaginary);

  printf("Enter the second complex number (c + di): ");
  scanf("%lf + %lfi", &b.real, &b.imaginary);

  printf("The sum of the two complex numbers is: ");
  add_complex_numbers(&a, &b, &result);
  print_complex_number(&result);

  printf("The difference of the two complex numbers is: ");
  subtract_complex_numbers(&a, &b, &result);
  print_complex_number(&result);

  printf("The product of the two complex numbers is: ");
  multiply_complex_numbers(&a, &b, &result);
  print_complex_number(&result);

  printf("The quotient of the two complex numbers is: ");
  divide_complex_numbers(&a, &b, &result);
  print_complex_number(&result);

  return 0;
}