//FormAI DATASET v1.0 Category: Digital signal processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512 // Max buffer size

int main(void) {
  int i, j, k, N, M;
  double h[BUFFER_SIZE], x[BUFFER_SIZE], y[BUFFER_SIZE];

  // Get filter coefficients
  printf("Enter filter coefficients (N taps) separated by spaces: ");
  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    scanf("%lf", &h[i]);
  }

  // Get input buffer size
  printf("Enter input buffer size (M samples): ");
  scanf("%d", &M);

  // Initialize input buffer
  for (i = 0; i < M; i++) {
    x[i] = 0.0;
  }

  // Process input data
  while (1) {
    // Get new input data
    printf("Enter %d input samples separated by spaces (or 0 to exit): ", M);
    for (i = 0; i < M; i++) {
      scanf("%lf", &x[i]);
      if (x[i] == 0.0) {
        exit(0);
      }
    }

    // Process input data with FIR filter
    for (i = 0; i < M + N - 1; i++) {
      y[i] = 0.0;
      for (j = 0; j < N; j++) {
        k = i - j;
        if (k >= 0 && k < M) {
          y[i] += h[j] * x[k];
        }
      }
    }

    // Print filtered output data
    printf("Filtered output data:\n");
    for (i = 0; i < M + N - 1; i++) {
      printf("%lf ", y[i]);
    }
    printf("\n");
  }

  return 0;
}