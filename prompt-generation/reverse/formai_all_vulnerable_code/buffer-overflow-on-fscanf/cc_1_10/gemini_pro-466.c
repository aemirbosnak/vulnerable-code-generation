//GEMINI-pro DATASET v1.0 Category: System administration ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA 100000

int main() {
  // Open the data file
  FILE *fp = fopen("data.txt", "r");
  if (fp == NULL) {
    perror("Error opening data file");
    return EXIT_FAILURE;
  }

  // Read the data into an array
  int data[MAX_DATA];
  int i = 0;
  while (fscanf(fp, "%d", &data[i]) != EOF) {
    i++;
  }
  fclose(fp);

  // Calculate the mean
  double mean = 0.0;
  for (i = 0; i < MAX_DATA; i++) {
    mean += data[i];
  }
  mean /= MAX_DATA;

  // Calculate the standard deviation
  double stddev = 0.0;
  for (i = 0; i < MAX_DATA; i++) {
    stddev += pow(data[i] - mean, 2);
  }
  stddev /= MAX_DATA;
  stddev = sqrt(stddev);

  // Calculate the median
  double median;
  if (MAX_DATA % 2 == 0) {
    // Even number of data points
    median = (data[MAX_DATA / 2] + data[MAX_DATA / 2 - 1]) / 2.0;
  } else {
    // Odd number of data points
    median = data[MAX_DATA / 2];
  }

  // Calculate the mode
  int mode;
  int max_count = 0;
  int count;
  for (i = 0; i < MAX_DATA; i++) {
    count = 0;
    for (int j = 0; j < MAX_DATA; j++) {
      if (data[i] == data[j]) {
        count++;
        if (count > max_count) {
          max_count = count;
          mode = data[i];
        }
      }
    }
  }

  // Print the results
  printf("Mean: %.2f\n", mean);
  printf("Standard deviation: %.2f\n", stddev);
  printf("Median: %.2f\n", median);
  printf("Mode: %d\n", mode);

  return EXIT_SUCCESS;
}