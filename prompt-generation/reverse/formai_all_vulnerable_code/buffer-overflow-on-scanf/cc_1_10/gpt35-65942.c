//FormAI DATASET v1.0 Category: Audio processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int main() {
  int num_samples, sample_rate, freq;
  double duration, amplitude, phase, time_step, sample;
  double *signal;
  FILE *file;

  // Get user input
  printf("Enter the number of samples: ");
  scanf("%d", &num_samples);

  printf("Enter the sample rate: ");
  scanf("%d", &sample_rate);

  printf("Enter the frequency of the sine wave: ");
  scanf("%d", &freq);

  printf("Enter the duration of the signal in seconds: ");
  scanf("%lf", &duration);

  printf("Enter the amplitude of the signal: ");
  scanf("%lf", &amplitude);

  printf("Enter the phase of the signal in degrees: ");
  scanf("%lf", &phase);

  // Convert phase from degrees to radians
  phase *= PI / 180;

  // Allocate memory for the signal
  signal = (double *) malloc(num_samples * sizeof(double));

  // Calculate time step
  time_step = 1.0 / sample_rate;

  // Calculate signal values
  for (int i = 0; i < num_samples; i++) {
    sample = amplitude * sin(2 * PI * freq * i * time_step + phase);
    signal[i] = sample;
  }
  
  // Write signal to file
  file = fopen("signal.txt", "w");
  fprintf(file, "%d %d\n", num_samples, sample_rate);
  for (int i = 0; i < num_samples; i++) {
    fprintf(file, "%f\n", signal[i]);
  }
  fclose(file);

  // Free memory
  free(signal);

  printf("Signal generated and saved as signal.txt.\n");
  
  return 0;
}