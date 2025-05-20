//FormAI DATASET v1.0 Category: Digital signal processing ; Style: systematic
/* This is a program for digital signal processing using C language */
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    int n, i;
    double signal[100], fft_real[100], fft_imag[100];

    printf("Enter the length of signal: ");
    scanf("%d", &n);

    printf("Enter the values of signal:\n");
    for(i=0;i<n;i++)
    {
        scanf("%lf", &signal[i]);
        fft_real[i] = signal[i];
        fft_imag[i] = 0;
    }

    // Fourier Transform
    int j, k, m;
    double temp_real, temp_imag, theta;
    int len = n / 2;

    for(i=0;i<len;i++)
    {
        temp_real = 0;
        temp_imag = 0;
        theta = 2 * PI * i / n;

        for(j=0;j<n;j++)
        {
            temp_real += fft_real[j] * cos(j * theta) + fft_imag[j] * sin(j * theta);
            temp_imag += fft_imag[j] * cos(j * theta) - fft_real[j] * sin(j * theta);
        }

        fft_real[i] = temp_real;
        fft_imag[i] = temp_imag;
        fft_real[i + len] = temp_real;
        fft_imag[i + len] = -temp_imag;
    }

    printf("\nFFT of Signal:\n");
    for(i=0;i<n;i++)
    {
        printf("FFT_Real[%d]: %lf \t FFT_Imag[%d]: %lf\n", i, fft_real[i], i, fft_imag[i]);
    }

    return 0;
}