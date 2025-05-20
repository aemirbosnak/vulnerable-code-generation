//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024
#define PI 3.14159265358979323846

int main()
{
    int i, k;
    float x[N], y[N], w[N], sum = 0.0;
    float freq, fs, t;
    FILE *fp;

    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    for (i = 0; i < N; i++)
    {
        fscanf(fp, "%f", &x[i]);
    }

    fclose(fp);

    // Calculate the frequency of the signal
    freq = 1.0 / (2.0 * PI * (double)N);

    // Calculate the sampling frequency
    fs = 1.0 / (2.0 * PI);

    // Calculate the time vector
    for (i = 0; i < N; i++)
    {
        t = (float)i / fs;
        w[i] = 2.0 * PI * freq * t;
    }

    // Calculate the FFT
    for (k = 0; k < N; k++)
    {
        for (i = 0; i < N; i++)
        {
            sum = 0.0;
            for (int j = 0; j < N; j++)
            {
                sum += x[j] * cos(w[i * N + j] + 2.0 * PI * k * j / N);
            }
            y[k * N + i] = sum;
        }
    }

    // Print the results
    printf("Frequency: %f Hz\n", freq);
    printf("Sampling frequency: %f Hz\n", fs);
    printf("Time vector:\n");
    for (i = 0; i < N; i++)
    {
        printf("%f\n", t);
    }
    printf("FFT:\n");
    for (i = 0; i < N; i++)
    {
        for (k = 0; k < N; k++)
        {
            printf("%f ", y[k * N + i]);
        }
        printf("\n");
    }

    return 0;
}