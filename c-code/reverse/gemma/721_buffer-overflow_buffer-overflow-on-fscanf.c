#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  // Define the file name
  char filename[] = "mnist.txt";

  // Open the file
  FILE* file = fopen(filename, "r");

  // Check if the file is open
  if (file == NULL) {
    // Handle the error
    perror("Error opening file");
    return 1;
  }

  // Get the number of rows and columns in the data
  int num_rows, num_cols;
  fscanf(file, "%d %d", &num_rows, &num_cols);

  // Allocate memory for the data
  int** data = (int**)malloc(num_rows * sizeof(int*));
  for (int i = 0; i < num_rows; i++) {
    data[i] = (int*)malloc(num_cols * sizeof(int));
  }

  // Read the data from the file
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      fscanf(file, "%d ", &data[i][j]);
    }
  }

  // Close the file
  fclose(file);

  // Free the memory
  for (int i = 0; i < num_rows; i++) {
    free(data[i]);
  }
  free(data);

  return 0;
}
