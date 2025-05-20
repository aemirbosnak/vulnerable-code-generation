//FormAI DATASET v1.0 Category: Digital signal processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void)
{
    int sampling_rate = 44100;  // sampling rate in Hz
    int num_samples = 100000;   // total number of samples
    double freq = 1000;         // signal frequency in Hz
    double amplitude = 0.5;     // signal amplitude
    double phase = 0;           // signal phase
    double *signal = malloc(num_samples * sizeof(double));  // allocate memory for signal

    // Generate sinusoidal signal
    for(int i = 0; i < num_samples; i++)
    {
        signal[i] = amplitude * sin(2 * PI * freq * i / sampling_rate + phase);
    }

    // Apply Hamming window
    double *window = malloc(num_samples * sizeof(double));  // allocate memory for window
    for(int i = 0; i < num_samples; i++)
    {
        window[i] = 0.54 - 0.46 * cos(2 * PI * i / (num_samples - 1));
        signal[i] *= window[i];
    }

    // Compute FFT
    double *real = malloc(num_samples * sizeof(double));   // allocate memory for real part
    double *imag = malloc(num_samples * sizeof(double));   // allocate memory for imaginary part
    for(int i = 0; i < num_samples; i++)
    {
        real[i] = signal[i];
        imag[i] = 0;
    }

    int num_bits = log2(num_samples);                      // number of bits for binary reordering
    for(int i = 0; i < num_samples; i++)
    {
        int reversed_i = 0;
        for(int j = 0; j < num_bits; j++)
        {
            reversed_i = (reversed_i << 1) | ((i >> j) & 1);   // reverse bit order
        }
        if(reversed_i > i)
        {
            double temp = real[i];
            real[i] = real[reversed_i];
            real[reversed_i] = temp;
            temp = imag[i];
            imag[i] = imag[reversed_i];
            imag[reversed_i] = temp;
        }
    }

    for(int n = 2; n <= num_samples; n <<= 1)             // Cooley-Tukey radix-2 FFT
    {
        double angle = 2 * PI / n;
        for(int i = 0; i < num_samples; i += n)
        {
            double w_real = 1;
            double w_imag = 0;
            for(int j = 0; j < n / 2; j++)
            {
                double t_real = w_real * real[i + j + n / 2] - w_imag * imag[i + j + n / 2];
                double t_imag = w_real * imag[i + j + n / 2] + w_imag * real[i + j + n / 2];
                double u_real = real[i + j];
                double u_imag = imag[i + j];
                real[i + j] = u_real + t_real;
                imag[i + j] = u_imag + t_imag;
                real[i + j + n / 2] = u_real - t_real;
                imag[i + j + n / 2] = u_imag - t_imag;
                double next_w_real = cos(angle * (j + 1));
                double next_w_imag = sin(angle * (j + 1));
                double temp_real = w_real;
                w_real = next_w_real * w_real - next_w_imag * w_imag;
                w_imag = next_w_real * w_imag + next_w_imag * temp_real;
            }
        }
    }

    // Compute magnitude spectrum
    double *magnitude = malloc(num_samples / 2 * sizeof(double));  // allocate memory for magnitude
    for(int i = 0; i < num_samples / 2; i++)
    {
        magnitude[i] = sqrt(real[i] * real[i] + imag[i] * imag[i]);
    }

    // Find peak magnitude and corresponding frequency
    double peak_magnitude = 0;
    double peak_frequency = 0;
    for(int i = 0; i < num_samples / 2; i++)
    {
        double frequency = i * (double)sampling_rate / num_samples;
        if(magnitude[i] > peak_magnitude)
        {
            peak_magnitude = magnitude[i];
            peak_frequency = frequency;
        }
    }

    // Print results
    printf("Signal frequency: %.2f Hz\n", freq);
    printf("Peak magnitude: %.2f\n", peak_magnitude);
    printf("Peak frequency: %.2f Hz\n", peak_frequency);

    // Free memory
    free(signal);
    free(window);
    free(real);
    free(imag);
    free(magnitude);

    return 0;
}