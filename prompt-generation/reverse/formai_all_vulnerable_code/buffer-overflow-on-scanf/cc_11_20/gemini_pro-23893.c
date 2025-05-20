//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int n, i, j, k, l;
  float a[100], b[100], c[100], d[100];

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter the elements of the first array: ");
  for (i = 0; i < n; i++) {
    scanf("%f", &a[i]);
  }

  printf("Enter the elements of the second array: ");
  for (i = 0; i < n; i++) {
    scanf("%f", &b[i]);
  }

  // Addition of two arrays
  for (i = 0; i < n; i++) {
    c[i] = a[i] + b[i];
  }

  // Subtraction of two arrays
  for (i = 0; i < n; i++) {
    d[i] = a[i] - b[i];
  }

  // Multiplication of two arrays
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      k = i * n + j;
      l = j * n + i;
      c[k] += a[i] * b[j];
      d[l] += a[i] * b[j];
    }
  }

  // Division of two arrays
  for (i = 0; i < n; i++) {
    if (b[i] != 0) {
      c[i] /= b[i];
      d[i] /= b[i];
    }
  }

  // Printing the results
  printf("Addition of the two arrays: ");
  for (i = 0; i < n; i++) {
    printf("%f ", c[i]);
  }

  printf("\nSubtraction of the two arrays: ");
  for (i = 0; i < n; i++) {
    printf("%f ", d[i]);
  }

  printf("\nMultiplication of the two arrays: ");
  for (i = 0; i < n; i++) {
    printf("%f ", c[i]);
  }

  printf("\nDivision of the two arrays: ");
  for (i = 0; i < n; i++) {
    printf("%f ", d[i]);
  }

  return 0;
}