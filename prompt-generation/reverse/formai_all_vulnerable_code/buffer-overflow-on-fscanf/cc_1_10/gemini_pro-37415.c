//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Romeo and Juliet: A Digital Signal Processing Tale

int main() {
  // Declare our star-crossed lovers, Romeo and Juliet
  float romeo[100];
  float juliet[100];

  // Read in Romeo's signal from a file
  FILE *romeo_file = fopen("romeo.txt", "r");
  for (int i = 0; i < 100; i++) {
    fscanf(romeo_file, "%f", &romeo[i]);
  }
  fclose(romeo_file);

  // Read in Juliet's signal from a file
  FILE *juliet_file = fopen("juliet.txt", "r");
  for (int i = 0; i < 100; i++) {
    fscanf(juliet_file, "%f", &juliet[i]);
  }
  fclose(juliet_file);

  // Perform a cross-correlation between Romeo and Juliet's signals
  float cross_correlation[200];
  for (int i = 0; i < 200; i++) {
    cross_correlation[i] = 0;
    for (int j = 0; j < 100; j++) {
      if (i - j >= 0 && i - j < 100) {
        cross_correlation[i] += romeo[j] * juliet[i - j];
      }
    }
  }

  // Find the peak of the cross-correlation
  int peak_index = 0;
  float peak_value = 0;
  for (int i = 0; i < 200; i++) {
    if (cross_correlation[i] > peak_value) {
      peak_index = i;
      peak_value = cross_correlation[i];
    }
  }

  // Print the peak of the cross-correlation
  printf("The peak of the cross-correlation is at index %d, with a value of %f.\n", peak_index, peak_value);

  return 0;
}