//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define N 1024

int main() {
  double x[N], y[N];
  double f[N];
  int i, n;
  double fs;

  printf("Enter the sampling frequency (Hz): ");
  scanf("%lf", &fs);

  printf("Enter the signal:\n");
  for (i = 0; i < N; i++) {
    scanf("%lf", &x[i]);
  }

  for (i = 0; i < N; i++) {
    y[i] = 0.0;
  }

  for (i = 0; i < N; i++) {
    y[i] += x[i];
  }

  for (i = 0; i < N; i++) {
    y[i] *= 2.0;
  }

  for (i = 0; i < N; i++) {
    y[i] -= x[i];
  }

  for (i = 0; i < N; i++) {
    y[i] /= N;
  }

  printf("Enter the cutoff frequency (Hz): ");
  scanf("%lf", &fs);

  double b[4] = {1.0, -2.0, 1.0, -2.0};
  double a[4] = {1.0, -2.0, 1.0, -2.0};

  for (i = 0; i < N; i++) {
    f[i] = y[i];
  }

  for (i = 0; i < N; i++) {
    f[i] = f[i] - a[0]*f[i-1] - a[1]*f[i-2] + b[0]*y[i-1] + b[1]*y[i-2];
  }

  for (i = 0; i < N; i++) {
    y[i] = f[i];
  }

  for (i = 0; i < N; i++) {
    printf("%lf\n", y[i]);
  }

  return 0;
}