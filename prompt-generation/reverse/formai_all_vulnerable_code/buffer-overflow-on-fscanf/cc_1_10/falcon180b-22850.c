//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 512 // Length of signal
#define M 256 // Length of filter
#define FS 44100 // Sampling frequency

int main()
{
    float x[N], y[N], h[M], X[N], Y[N];
    int i, j, k;
    FILE *fp;

    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }

    // Read input signal from file
    for (i = 0; i < N; i++)
    {
        fscanf(fp, "%f", &x[i]);
    }
    fclose(fp);

    // Apply low-pass filter
    for (i = 0; i < M; i++)
    {
        h[i] = 0.0;
        for (j = 0; j < M; j++)
        {
            h[i] += 1.0 / M;
        }
    }
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            X[i] += h[j] * x[i - j];
        }
    }
    for (i = 0; i < N; i++)
    {
        X[i] = X[i] / M;
    }

    // Write filtered signal to output file
    fp = fopen("output.txt", "w");
    if (fp == NULL)
    {
        printf("Error: Cannot open output file.\n");
        exit(1);
    }
    for (i = 0; i < N; i++)
    {
        fprintf(fp, "%f\n", X[i]);
    }
    fclose(fp);

    return 0;
}