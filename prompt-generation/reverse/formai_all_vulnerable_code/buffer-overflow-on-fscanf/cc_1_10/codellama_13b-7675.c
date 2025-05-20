//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: random
// C Data Mining Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read data from file
void readData(char* filename, int* data, int size) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file: %s\n", filename);
    exit(1);
  }

  int i = 0;
  while (fscanf(file, "%d", &data[i]) == 1) {
    i++;
  }

  fclose(file);
}

// Function to print data
void printData(int* data, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");
}

// Function to calculate mean
float calculateMean(int* data, int size) {
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += data[i];
  }
  return sum / size;
}

// Function to calculate standard deviation
float calculateStandardDeviation(int* data, int size, float mean) {
  float sum = 0;
  for (int i = 0; i < size; i++) {
    sum += (data[i] - mean) * (data[i] - mean);
  }
  return sqrt(sum / (size - 1));
}

// Main function
int main(int argc, char* argv[]) {
  // Check for correct number of arguments
  if (argc != 2) {
    printf("Usage: %s <data file>\n", argv[0]);
    exit(1);
  }

  // Read data from file
  char* filename = argv[1];
  int data[100];
  int size = sizeof(data) / sizeof(data[0]);
  readData(filename, data, size);

  // Print data
  printf("Data: ");
  printData(data, size);

  // Calculate mean
  float mean = calculateMean(data, size);
  printf("Mean: %f\n", mean);

  // Calculate standard deviation
  float standardDeviation = calculateStandardDeviation(data, size, mean);
  printf("Standard Deviation: %f\n", standardDeviation);

  return 0;
}