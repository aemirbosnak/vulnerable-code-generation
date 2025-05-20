#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 1024;
  double x[n], y[n];

  // Generate random data
  for (int i = 0; i < n; i++) {
    x[i] = rand() / (double)RAND_MAX;
  }

  // Apply low-pass filter
  for (int i = 0; i < n; i++) {
    y[i] = 0.8 * x[i] + 0.2 * y[i-1];
  }

  // Print results
  for (int i = 0; i < n; i++) {
    printf("%f ", y[i]);
  }

  return 0;
}
