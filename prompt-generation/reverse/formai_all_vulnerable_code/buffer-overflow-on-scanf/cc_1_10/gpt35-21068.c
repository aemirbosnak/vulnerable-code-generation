//FormAI DATASET v1.0 Category: Digital signal processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUT_SIZE 1000

int main() {

  int input_array[MAX_INPUT_SIZE];
  int output_array[MAX_INPUT_SIZE];

  int num_samples, i, j;
  double frequency;

  printf("Enter number of samples: ");
  scanf("%d", &num_samples);

  printf("Enter signal frequency (in Hz): ");
  scanf("%lf", &frequency);

  printf("Enter sample values: ");
  for (i = 0; i < num_samples; i++) {
    scanf("%d", &input_array[i]);
  }

  // Digital filter using a configurable window

  int window_size;
  double window[MAX_INPUT_SIZE];
  printf("Enter window size (must be odd): ");
  scanf("%d", &window_size);

  // Generate window coefficients
  for (i = 0; i < num_samples; i++) {
    if (i < window_size/2 || i > num_samples - window_size/2) {
      window[i] = 0;
    } else {
      window[i] = 1;
    }
  }

  // Apply filter
  for (i = 0; i < num_samples; i++) {
    double sum = 0;
    for (j = i - window_size/2; j <= i + window_size/2; j++) {
      if (j >= 0 && j < num_samples) {
        sum += window[j] * input_array[j] * sin(2 * M_PI * frequency * (i - j));
      }
    }
    output_array[i] = sum;
  }

  // Print output
  printf("\nFiltered signal:\n");
  for (i = 0; i < num_samples; i++) {
    printf("%d ", output_array[i]);
  }
  printf("\n");

  return 0;
}