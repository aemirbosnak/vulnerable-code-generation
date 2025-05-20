//FormAI DATASET v1.0 Category: Digital signal processing ; Style: realistic
/* 
This program takes an input signal and applies a low-pass filter using the Direct-Form II Transposed structure.

The filter coefficients are calculated using a Blackman windowed-sinc function for a cutoff frequency of 500 Hz, assuming a 1000 Hz sampling rate.

The signal is read from a text file "input_signal.txt" and the filtered signal is written to a text file "output_signal.txt".
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void)
{
  // Declare variables
  FILE *input_file, *output_file;
  float input_buffer[512], output_buffer[512], x[3], y[3], b[51], w[51];
  int i, j, k, n, m;
  float fc, wc, M, a;

  // Read input signal from file
  input_file = fopen("input_signal.txt", "r");
  if (input_file == NULL) {
    printf("Error: Could not open input file.\n");
    exit(EXIT_FAILURE);
  }

  // Read file into input buffer
  for (i = 0; i < 512; i++) {
    if (fscanf(input_file, "%f", &input_buffer[i]) != 1) {
      printf("Error: Invalid input file format.\n");
      exit(EXIT_FAILURE);
    }
  }
  fclose(input_file);

  // Calculate filter coefficients
  fc = 500; // Cutoff frequency
  M = 50; // Filter order
  wc = 2 * PI * fc / 1000; // Cutoff frequency in radians
  for (i = 0; i <= M; i++) {
    if (i == M / 2) {
      b[i] = wc / PI;
    } else {
      b[i] = sin(wc * (i - M / 2)) / (PI * (i - M / 2));
    }
    b[i] = b[i] * 0.42 - 0.5 + 0.08 * cos(2 * PI * i / M);
  }

  // Initialize state variables
  for (i = 0; i < 3; i++) {
    x[i] = 0;
    y[i] = 0;
  }

  // Filter signal with Direct-Form II Transposed structure
  for (i = 0; i < 512; i++) {
    // Shift input and output buffers
    for (j = 2; j >= 1; j--) {
      x[j] = x[j-1];
      y[j] = y[j-1];
    }
    x[0] = input_buffer[i];

    // Calculate output sample
    y[0] = 0;
    for (k = 0; k <= M; k++) {
      if (i < k) {
        w[k] = 0; // Zero-padding
      } else {
        w[k] = x[i-k];
      }
      y[0] += b[k] * w[k];
    }
    output_buffer[i] = y[0];
  }

  // Write output signal to file
  output_file = fopen("output_signal.txt", "w");
  if (output_file == NULL) {
    printf("Error: Could not open output file.\n");
    exit(EXIT_FAILURE);
  }
  for (i = 0; i < 512; i++) {
    fprintf(output_file, "%f\n", output_buffer[i]);
  }
  fclose(output_file);

  return 0;
}