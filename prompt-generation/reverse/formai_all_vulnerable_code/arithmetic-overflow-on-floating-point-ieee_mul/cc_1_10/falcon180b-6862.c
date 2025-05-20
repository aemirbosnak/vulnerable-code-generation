//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    double x[1024], y[1024];
    int i, n;
    double freq, amp, phase;
    double theta, omega, t;
    double real, imag;

    printf("Enter the number of samples: ");
    scanf("%d", &n);

    printf("Enter the frequency of the signal (in Hz): ");
    scanf("%lf", &freq);

    printf("Enter the amplitude of the signal: ");
    scanf("%lf", &amp);

    printf("Enter the phase of the signal (in degrees): ");
    scanf("%lf", &phase);

    theta = phase * PI / 180.0;
    omega = 2.0 * PI * freq;

    for (i = 0; i < n; i++)
    {
        t = (double)i / (double)n * 2.0 * PI;
        real = amp * cos(omega * t + theta);
        imag = 0.0;
        x[i] = real;
        y[i] = imag;
    }

    for (i = 0; i < n; i++)
    {
        real = x[i];
        imag = y[i];
        x[i] = real * cos(theta) - imag * sin(theta);
        y[i] = real * sin(theta) + imag * cos(theta);
    }

    printf("The generated signal is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%lf + %lfi\n", x[i], y[i]);
    }

    return 0;
}