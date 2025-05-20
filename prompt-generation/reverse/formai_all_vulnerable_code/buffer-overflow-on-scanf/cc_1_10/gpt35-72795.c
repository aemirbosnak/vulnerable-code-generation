//FormAI DATASET v1.0 Category: Digital signal processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    int i, j, k, N, M;
    double x[1024], y[1024], z[1024];
    double fft[2048], temp, mag;

    // Initialize input signal x[n]
    printf("Enter the length of input signal: ");
    scanf("%d", &N);
    printf("Enter the input signal:\n");
    for(i=0; i<N; i++)
        scanf("%lf", &x[i]);

    // Compute FFT of input signal
    M = ceil(log2(N));
    for(i=0; i<N; i++)
    {
        fft[2*i] = x[i];
        fft[2*i+1] = 0;
    }

    for(i=1; i<=M; i++)
    {
        k = pow(2,i);

        for(j=0; j<k/2; j++)
        {
            double re = fft[2*j*k/k];
            double im = fft[2*j*k/k+1];

            double twid_re = cos(-2*PI*j/k);
            double twid_im = sin(-2*PI*j/k);

            double temp_re = fft[2*j*k/k+k/2];
            double temp_im = fft[2*j*k/k+k/2+1];

            double temp_twiddled_re = temp_re*twid_re - temp_im*twid_im;
            double temp_twiddled_im = temp_re*twid_im + temp_im*twid_re;

            fft[2*j*k/k] = re + temp_twiddled_re;
            fft[2*j*k/k+1] = im + temp_twiddled_im;

            fft[2*j*k/k+k/2] = re - temp_twiddled_re;
            fft[2*j*k/k+k/2+1] = im - temp_twiddled_im;
        }
    }

    // Compute magnitude and phase spectrum
    for(i=0; i<N; i++)
    {
        mag = sqrt(fft[2*i]*fft[2*i] + fft[2*i+1]*fft[2*i+1]);
        temp = atan2(fft[2*i+1], fft[2*i]);
        y[i] = mag;
        z[i] = temp * 180.0 / PI; // Convert to degrees
    }

    // Print input signal, magnitude spectrum, and phase spectrum
    printf("*** Input signal:\n");
    for(i=0; i<N; i++)
        printf("%lf\n", x[i]);

    printf("*** Magnitude spectrum:\n");
    for(i=0; i<N; i++)
        printf("%lf\n", y[i]);

    printf("*** Phase spectrum:\n");
    for(i=0; i<N; i++)
        printf("%lf\n", z[i]);

    // Exit program
    return 0;
}