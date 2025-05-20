//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to calculate FFT of input signal
void fft(double *input, int n) {
    int i, j, k;
    double theta, w, wr, wi, temp;
    double *even, *odd;

    even = (double *)malloc(n * sizeof(double));
    odd = (double *)malloc(n * sizeof(double));

    // Copy input signal to even and odd arrays
    for (i = 0; i < n; i++) {
        even[i] = input[i];
    }

    // Calculate FFT
    for (i = 1; i < n; i *= 2) {
        theta = PI / i;
        w = cos(theta);
        wr = -sin(theta);
        for (j = 0; j < n; j += 2 * i) {
            for (k = 0; k < i; k++) {
                temp = even[j + k] + odd[j + k + i / 2];
                even[j + k] = even[j + k] - odd[j + k + i / 2] + temp * w;
                odd[j + k + i / 2] = odd[j + k + i / 2] + temp * wr;
            }
        }
    }

    // Copy FFT result back to input array
    for (i = 0; i < n; i++) {
        input[i] = even[i];
    }

    // Free memory
    free(even);
    free(odd);
}

// Function to calculate magnitude of FFT
void magnitude(double *input, int n) {
    int i;
    double mag;

    for (i = 0; i < n; i++) {
        mag = sqrt(input[i] * input[i] + input[n - i - 1] * input[n - i - 1]);
        printf("%f\n", mag);
    }
}

int main() {
    int n;
    double *input;

    // Get input signal from user
    printf("Enter number of samples: ");
    scanf("%d", &n);
    input = (double *)malloc(n * sizeof(double));
    printf("Enter input signal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &input[i]);
    }

    // Calculate FFT of input signal
    fft(input, n);

    // Calculate magnitude of FFT
    magnitude(input, n);

    return 0;
}