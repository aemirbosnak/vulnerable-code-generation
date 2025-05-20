//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  // Define variables
  int n, i, j, k;
  float sum, mean, variance, stddev;
  float *data;

  // Read input
  printf("Enter the number of data points: ");
  scanf("%d", &n);

  // Allocate memory for data
  data = (float *)malloc(n * sizeof(float));
  if (data == NULL) {
    printf("Error: cannot allocate memory.\n");
    return EXIT_FAILURE;
  }

  // Read data
  printf("Enter the data points:\n");
  for (i = 0; i < n; i++) {
    scanf("%f", &data[i]);
  }

  // Calculate sum
  sum = 0;
  for (i = 0; i < n; i++) {
    sum += data[i];
  }

  // Calculate mean
  mean = sum / n;

  // Calculate variance
  variance = 0;
  for (i = 0; i < n; i++) {
    variance += pow(data[i] - mean, 2);
  }
  variance /= (n - 1);

  // Calculate standard deviation
  stddev = sqrt(variance);

  // Print results
  printf("Sum: %.2f\n", sum);
  printf("Mean: %.2f\n", mean);
  printf("Variance: %.2f\n", variance);
  printf("Standard deviation: %.2f\n", stddev);

  // Free memory
  free(data);

  return EXIT_SUCCESS;
}