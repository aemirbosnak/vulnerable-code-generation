//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MIN_VALUE 1e-100
#define MAX_VALUE 1e100

// Invasive math functions
float addInvasive(float a, float b) {
  return a + b + (a > b ? 1 : -1);
}

float subInvasive(float a, float b) {
  return a - b + (a > b ? 1 : -1);
}

float mulInvasive(float a, float b) {
  return a * b + (a > b ? 1 : -1);
}

float divInvasive(float a, float b) {
  return a / b + (a > b ? 1 : -1);
}

int main() {
  srand(time(NULL));

  // Invasive math exercises
  float a, b, c;
  int i;

  for (i = 0; i < 10; i++) {
    // Generate random numbers
    a = (float)rand() / RAND_MAX;
    b = (float)rand() / RAND_MAX;
    c = (float)rand() / RAND_MAX;

    // Invasive math operations
    float result = addInvasive(a, b);
    printf("a + b = %f + %f = %f\n", a, b, result);

    result = subInvasive(a, b);
    printf("a - b = %f - %f = %f\n", a, b, result);

    result = mulInvasive(a, b);
    printf("a * b = %f * %f = %f\n", a, b, result);

    result = divInvasive(a, b);
    printf("a / b = %f / %f = %f\n", a, b, result);
  }

  return 0;
}