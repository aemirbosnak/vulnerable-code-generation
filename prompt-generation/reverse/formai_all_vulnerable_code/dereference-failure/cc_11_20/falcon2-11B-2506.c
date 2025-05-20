//Falcon2-11B DATASET v1.0 Category: Digital signal processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Input signal length
    int N = 512;

    // Input signal array
    float* x = (float*)malloc(sizeof(float) * N);
    for (int i = 0; i < N; i++) {
        x[i] = (float)(rand() % 100);
    }

    // Initialize FFT variables
    int n = (int)sqrt(N);
    float* w = (float*)malloc(sizeof(float) * N);
    for (int i = 0; i < N; i++) {
        w[i] = 2.0 * M_PI * (float)i / (float)N;
    }
    float* x_f = (float*)malloc(sizeof(float) * n);
    float* y_f = (float*)malloc(sizeof(float) * n);
    for (int i = 0; i < n; i++) {
        x_f[i] = 0.0;
        y_f[i] = 0.0;
    }

    // FFT algorithm
    for (int k = 0; k < N; k++) {
        for (int m = 0; m <= k; m++) {
            float tmp = x[k - m] * w[m];
            x[k - m] = x[k + m] - tmp;
            x[k + m] = x[k - m] + tmp;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int m = 0; m <= k; m++) {
            float tmp = x_f[k - m] * w[m];
            x_f[k - m] = x_f[k + m] - tmp;
            x_f[k + m] = x_f[k - m] + tmp;
        }
    }

    // Compute inverse FFT
    for (int k = 0; k < N; k++) {
        for (int m = 0; m <= k; m++) {
            float tmp = x_f[k - m] * w[m];
            x[k - m] = x[k + m] - tmp;
            x[k + m] = x[k - m] + tmp;
        }
    }

    // Compute DFT
    float* dft = (float*)malloc(sizeof(float) * N);
    for (int i = 0; i < N; i++) {
        dft[i] = 0.0;
        for (int j = 0; j < N; j++) {
            dft[i] += x[j] * cos(w[i - j]);
        }
    }

    // Output DFT
    printf("DFT of x:\n");
    for (int i = 0; i < N; i++) {
        printf("%.3f ", dft[i]);
    }
    printf("\n");

    // Free memory
    free(x);
    free(w);
    free(x_f);
    free(y_f);
    free(dft);

    return 0;
}