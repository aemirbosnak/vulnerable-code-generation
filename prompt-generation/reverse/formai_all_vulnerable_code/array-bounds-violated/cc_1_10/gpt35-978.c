//FormAI DATASET v1.0 Category: Data mining ; Style: Ada Lovelace
// Ada Lovelace Style C Program for Data Mining

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int main(void) {

  int dataset[ARRAY_SIZE] = { 3, 6, 9, 12, 15, 18, 21, 24, 27, 30 }; // Define a dataset of 10 elements
  int min = dataset[0], max = dataset[0]; // Set minimum and maximum values to the first element of the dataset

  // Find the minimum and maximum values in the dataset
  for (int i = 1; i < ARRAY_SIZE; i++) {
    if (dataset[i] < min) {
      min = dataset[i];
    }
    if (dataset[i] > max) {
      max = dataset[i];
    }
  }

  // Calculate the mean, median, and mode of the dataset
  float sum = 0;
  int median, mode, modeCount = 0, count = 0;
  for (int i = 0; i < ARRAY_SIZE; i++) {
    sum += dataset[i];
    if (dataset[i] > median && count <= ARRAY_SIZE / 2) {
      median = dataset[i];
    }
    if (dataset[i] == dataset[i+1]) {
      count++;
    } else {
      if (count > modeCount) {
        mode = dataset[i];
        modeCount = count;
      }
      count = 0;
    }
  }
  float mean = sum / ARRAY_SIZE;

  // Print the results
  printf("Minimum value: %d\n", min);
  printf("Maximum value: %d\n", max);
  printf("Mean value: %f\n", mean);
  printf("Median value: %d\n", median);
  printf("Mode value: %d\n", mode);

  return 0;
}