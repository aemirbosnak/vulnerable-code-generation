//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define N 1024

// generate a sine wave of frequency f and amplitude A
void generate_sine_wave(double f, double A, double* wave, int n) {
    double t = 0;
    for (int i = 0; i < n; i++) {
        wave[i] = A * sin(2 * PI * f * t);
        t += 1 / (double) n;
    }
}

// compute the FFT of a signal
void fft(double* signal, int n) {
    double* even = malloc(n / 2 * sizeof(double));
    double* odd = malloc(n / 2 * sizeof(double));

    // copy even and odd indices to separate arrays
    for (int i = 0; i < n / 2; i++) {
        even[i] = signal[2 * i];
        odd[i] = signal[2 * i + 1];
    }

    // compute FFT of even and odd indices separately
    fft(even, n / 2);
    fft(odd, n / 2);

    // combine even and odd indices
    for (int i = 0; i < n / 2; i++) {
        signal[2 * i] = even[i];
        signal[2 * i + 1] = odd[i];
    }

    free(even);
    free(odd);
}

// compute the power spectral density of a signal
void psd(double* signal, int n) {
    fft(signal, n);

    // compute power spectral density
    for (int i = 0; i < n / 2; i++) {
        signal[i] = sqrt(signal[i] * signal[i] + signal[n - i - 1] * signal[n - i - 1]);
    }
}

int main() {
    // generate a sine wave
    double f = 10.0;
    double A = 1.0;
    double* wave = malloc(N * sizeof(double));
    generate_sine_wave(f, A, wave, N);

    // compute power spectral density
    double* signal = malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        signal[i] = wave[i];
    }
    psd(signal, N);

    // print power spectral density
    for (int i = 0; i < N / 2; i++) {
        printf("%lf ", signal[i]);
    }

    return 0;
}