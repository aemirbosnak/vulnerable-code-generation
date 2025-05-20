//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_TAPS 5
typedef struct {
    float b[NUM_TAPS];
    float a[NUM_TAPS];
} butterworth_filter;

butterworth_filter filter;

void butterworth_filter_coefs(float cutoff_freq, float sample_rate) {
    float Q, K, K1, K2, denominator, z0_real, z0_imag, z1_real, z1_imag;

    Q = sqrt(2.0);
    K = tan(M_PI * cutoff_freq / sample_rate);
    K1 = 1.0 / (2.0 * K);
    K2 = K * K1;

    z0_real = 1.0;
    z0_imag = 0.0;

    denominator = 1.0;
    for (int i = 0; i < NUM_TAPS; i++) {
        z1_real = z0_real - 2.0 * i * K1 * z0_real + i * i * K2;
        z1_imag = z0_imag - (i + 0.5) * K1 * z0_imag;

        filter.b[i] = z1_real / (2.0 * NUM_TAPS);
        filter.a[i] = z1_real / (2.0 * (NUM_TAPS - i));
        denominator *= z1_real;
    }

    filter.a[0] += 1.0 / denominator;
}

void butterworth_filter_process(float input, float *output) {
    float sum = 0.0;

    for (int i = 0; i < NUM_TAPS; i++) {
        sum += filter.b[i] * input;
        input = input - filter.a[i] * sum;
    }

    *output = sum;
}

int main() {
    float input = 1.0;
    float output;

    butterworth_filter_coefs(0.5, 1000.0);

    for (int i = 0; i < 10; i++) {
        butterworth_filter_process(input, &output);
        printf("Input: %f, Output: %f\n", input, output);
        input = output;
    }

    return 0;
}