//Code Llama-13B DATASET v1.0 Category: Math exercise ; Style: scalable
/*
 * C Math Exercise
 * Program: Unique C Math Exercise
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Variables declaration
  int n, i, j;
  float x, y, z;

  // Input
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  float arr[n];

  // Initialize the array
  for (i = 0; i < n; i++) {
    arr[i] = i;
  }

  // Sort the array
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        x = arr[i];
        arr[i] = arr[j];
        arr[j] = x;
      }
    }
  }

  // Print the sorted array
  printf("Sorted array: ");
  for (i = 0; i < n; i++) {
    printf("%f ", arr[i]);
  }
  printf("\n");

  // Find the minimum and maximum elements
  float min = arr[0];
  float max = arr[n - 1];
  for (i = 1; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  // Calculate the mean and standard deviation
  float mean = 0;
  float sd = 0;
  for (i = 0; i < n; i++) {
    mean += arr[i];
  }
  mean /= n;
  for (i = 0; i < n; i++) {
    sd += pow(arr[i] - mean, 2);
  }
  sd /= n;
  sd = sqrt(sd);

  // Print the results
  printf("Minimum: %f\n", min);
  printf("Maximum: %f\n", max);
  printf("Mean: %f\n", mean);
  printf("Standard Deviation: %f\n", sd);

  return 0;
}