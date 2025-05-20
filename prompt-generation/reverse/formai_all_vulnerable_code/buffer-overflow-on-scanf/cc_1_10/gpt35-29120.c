//FormAI DATASET v1.0 Category: Audio processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

typedef struct {
  double *real, *imag;
  int n;
} cplx;

// Function to initialize complex data type
cplx init_cplx(int n) {
  cplx x = {malloc(sizeof(double) * n),
            malloc(sizeof(double) * n),
            n};
  return x;
}

// Function to perform Fourier Transform
cplx fourierTransform(double *x, int n) {
  cplx X = init_cplx(n);
  for (int k = 0; k < n; k++) {
    for (int j = 0; j < n; j++) {
      X.real[k] += x[j] * cos(2 * PI * k * j / n);
      X.imag[k] -= x[j] * sin(2 * PI * k * j / n);
    }
  }
  return X;
}

int main() {
  int n;
  printf("Enter the number of samples for Fourier Transform: ");
  scanf("%d", &n);
  double *x = malloc(sizeof(double) * n);
  printf("Enter %d samples: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &x[i]);
  }
  
  cplx X = fourierTransform(x, n);
  
  printf("Real\tImaginary\n");
  for (int k = 0; k < n; k++) {
    printf("%.3lf\t%.3lf\n", X.real[k], X.imag[k]);
  }
  
  free(x);
  free(X.real);
  free(X.imag);
  return 0;
}