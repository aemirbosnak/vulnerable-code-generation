#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM_PIXELS 28

int main() {
  // Read data from file
  FILE *fp = fopen("mnist_data.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Allocate memory for data
  char **data = (char**)malloc(MAX_NUM_PIXELS * MAX_NUM_PIXELS * 10 * sizeof(char));
  if (data == NULL) {
    perror("Error allocating memory");
    fclose(fp);
    return 1;
  }

  // Read data from file
  int num_pixels = 0;
  char line[MAX_NUM_PIXELS * 10];
  while (fgets(line, MAX_NUM_PIXELS * 10, fp) != NULL) {
    // Convert line to pixel data
    int i = 0;
    for (char *pixel = line; pixel != NULL; pixel++) {
      data[num_pixels++] = atoi(pixel);
    }
  }

  // Close file
  fclose(fp);

  // Train neural network
  // (code for training neural network would go here)

  // Free memory
  free(data);

  return 0;
}
