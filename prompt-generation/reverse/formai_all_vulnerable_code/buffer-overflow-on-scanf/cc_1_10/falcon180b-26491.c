//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define N 256
#define M 16
#define PI 3.14159265358979323846

float x[N], h[M], y[N];

void fir_filter(float x[], float h[], float y[], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        y[i] = 0;
        for (j = 0; j < M; j++)
        {
            y[i] += h[j] * x[i - j];
        }
    }
}

void main()
{
    int i;
    float f, t;

    printf("Enter the sampling frequency: ");
    scanf("%f", &f);

    printf("Enter the time duration: ");
    scanf("%f", &t);

    for (i = 0; i < N; i++)
    {
        x[i] = sin(2 * PI * i * f * t);
    }

    printf("Enter the filter coefficients:\n");
    for (i = 0; i < M; i++)
    {
        scanf("%f", &h[i]);
    }

    fir_filter(x, h, y, N);

    printf("Output:\n");
    for (i = 0; i < N; i++)
    {
        printf("%f\n", y[i]);
    }
}