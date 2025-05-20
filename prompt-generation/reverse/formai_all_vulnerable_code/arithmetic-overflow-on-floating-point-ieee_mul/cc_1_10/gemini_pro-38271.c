//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Declare variables
  int a = 10;
  int b = 5;
  int c;

  // Perform arithmetic operations
  c = a + b; // Addition
  printf("Addition: %d + %d = %d\n", a, b, c);
  
  c = a - b; // Subtraction
  printf("Subtraction: %d - %d = %d\n", a, b, c);
  
  c = a * b; // Multiplication
  printf("Multiplication: %d * %d = %d\n", a, b, c);
  
  c = a / b; // Division
  printf("Division: %d / %d = %d\n", a, b, c);
  
  c = a % b; // Modulus
  printf("Modulus: %d %% %d = %d\n", a, b, c);
  
  c = a++; // Post-increment
  printf("Post-increment: %d++ = %d\n", a, c);
  
  c = ++a; // Pre-increment
  printf("Pre-increment: ++%d = %d\n", a, c);
  
  c = a--; // Post-decrement
  printf("Post-decrement: %d-- = %d\n", a, c);
  
  c = --a; // Pre-decrement
  printf("Pre-decrement: --%d = %d\n", a, c);
  
  // Perform bitwise operations
  c = a & b; // Bitwise AND
  printf("Bitwise AND: %d & %d = %d\n", a, b, c);
  
  c = a | b; // Bitwise OR
  printf("Bitwise OR: %d | %d = %d\n", a, b, c);
  
  c = a ^ b; // Bitwise XOR
  printf("Bitwise XOR: %d ^ %d = %d\n", a, b, c);
  
  c = ~a; // Bitwise NOT
  printf("Bitwise NOT: ~%d = %d\n", a, c);
  
  c = a << 2; // Left shift
  printf("Left shift: %d << 2 = %d\n", a, c);
  
  c = a >> 2; // Right shift
  printf("Right shift: %d >> 2 = %d\n", a, c);
  
  // Perform mathematical operations
  c = pow(a, b); // Exponentiation
  printf("Exponentiation: pow(%d, %d) = %d\n", a, b, c);
  
  c = sqrt(a); // Square root
  printf("Square root: sqrt(%d) = %d\n", a, c);
  
  c = log(a); // Logarithm
  printf("Logarithm: log(%d) = %d\n", a, c);
  
  c = sin(a); // Sine
  printf("Sine: sin(%d) = %d\n", a, c);
  
  c = cos(a); // Cosine
  printf("Cosine: cos(%d) = %d\n", a, c);
  
  c = tan(a); // Tangent
  printf("Tangent: tan(%d) = %d\n", a, c);
  
  return 0;
}