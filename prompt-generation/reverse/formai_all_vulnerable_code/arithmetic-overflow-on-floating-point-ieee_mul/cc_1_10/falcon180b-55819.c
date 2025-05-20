//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024
#define PI 3.14159265358979323846

int main() {
  double x[N], y[N];
  double freq, amp, phase;
  int i;

  printf("Enter the frequency of the signal: ");
  scanf("%lf", &freq);

  printf("Enter the amplitude of the signal: ");
  scanf("%lf", &amp);

  printf("Enter the phase of the signal: ");
  scanf("%lf", &phase);

  for (i = 0; i < N; i++) {
    x[i] = amp * sin(2 * PI * freq * i / (N / 2) + phase);
  }

  printf("Original Signal:\n");
  for (i = 0; i < N; i++) {
    printf("%lf ", x[i]);
  }

  printf("\n");

  double real[N], imag[N];

  for (i = 0; i < N; i++) {
    real[i] = x[i];
    imag[i] = 0;
  }

  double fft_real[N], fft_imag[N];

  for (i = 0; i < N; i++) {
    double sum_real = 0, sum_imag = 0;
    for (int j = 0; j < N; j++) {
      double term_real = real[j] * cos(2 * PI * i * j / N) - imag[j] * sin(2 * PI * i * j / N);
      double term_imag = real[j] * sin(2 * PI * i * j / N) + imag[j] * cos(2 * PI * i * j / N);
      sum_real += term_real;
      sum_imag += term_imag;
    }
    fft_real[i] = sum_real;
    fft_imag[i] = sum_imag;
  }

  printf("FFT of Signal:\n");
  for (i = 0; i < N; i++) {
    printf("%lf ", fft_real[i]);
  }

  printf("\n");

  return 0;
}