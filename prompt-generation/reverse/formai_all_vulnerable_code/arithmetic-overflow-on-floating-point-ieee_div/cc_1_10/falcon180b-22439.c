//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024           // Number of samples
#define Fs 44100          // Sampling frequency
#define Fc 440            // Cutoff frequency
#define T 1/Fs            // Sampling period
#define PI 3.14159265358979323846

double h[N];             // Impulse response of the filter
double x[N];             // Input signal
double y[N];             // Output signal

void gen_impulse_response(double cutoff, double fs)
{
    int i;
    double wc = 2.0 * PI * cutoff / fs;
    for (i = 0; i < N; i++)
    {
        h[i] = sin(wc * i * T) / (wc * i * T);
    }
}

void apply_filter(double* input, double* output, double* impulse_response, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        output[i] = 0;
        for (int j = 0; j < length; j++)
        {
            output[i] += input[j] * impulse_response[i-j];
        }
    }
}

int main()
{
    int i;
    double t;

    // Generate impulse response
    gen_impulse_response(Fc, Fs);

    // Generate input signal
    for (i = 0; i < N; i++)
    {
        x[i] = sin(2.0 * PI * 440.0 * i / Fs);
    }

    // Apply filter
    apply_filter(x, y, h, N);

    // Print results
    for (i = 0; i < N; i++)
    {
        t = i * T;
        printf("%f %f\n", t, y[i]);
    }

    return 0;
}