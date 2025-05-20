//FormAI DATASET v1.0 Category: Arithmetic ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Defining constants
#define N 10000
#define MIN -1000
#define MAX 1000

// Defining external functions
extern int add(int a, int b);
extern int subtract(int a, int b);
extern int multiply(int a, int b);
extern double divide(int a, int b);
extern int square(int a);
extern double square_root(int a);

int main() {
  int a, b;
  int result;
  double dresult;

  // Seed the random number generator with system time
  srand(time(NULL));

  // Generate two random numbers a and b
  a = rand() % (MAX - MIN + 1) + MIN;
  b = rand() % (MAX - MIN + 1) + MIN;
  
  // Perform addition
  result = add(a, b);
  printf("Addition of %d and %d is %d\n", a, b, result);
  
  // Perform subtraction
  result = subtract(a, b);
  printf("Subtraction of %d and %d is %d\n", a, b, result);
  
  // Perform multiplication
  result = multiply(a, b);
  printf("Multiplication of %d and %d is %d\n", a, b, result);
  
  // Perform division
  dresult = divide(a, b);
  printf("Division of %d by %d is %.2f\n", a, b, dresult);
  
  // Perform square of a
  result = square(a);
  printf("Square of %d is %d\n", a, result);
  
  // Perform square root of b
  dresult = square_root(b);
  printf("Square root of %d is %.2f\n", b, dresult);
  
  return 0;
}

// Addition function
int add(int a, int b) {
  return a + b;
}

// Subtraction function
int subtract(int a, int b) {
  return a - b;
}

// Multiplication function
int multiply(int a, int b) {
  return a * b;
}

// Division function
double divide(int a, int b) {
  return (double) a / b;
}

// Square function
int square(int a) {
  return a * a;
}

// Square root function
double square_root(int a) {
  return sqrt(a);
}