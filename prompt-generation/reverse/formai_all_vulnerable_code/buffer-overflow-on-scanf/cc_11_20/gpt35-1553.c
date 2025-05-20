//FormAI DATASET v1.0 Category: Digital signal processing ; Style: happy
#include<stdio.h>
#include<math.h>

int main()
{
    printf("Wooohoooo! Time for some happy Digital Signal Processing!\n");

    int i, j, k, n;
    float x[100], hn[100], yn[100], h[100], y[100];
    float pi=3.14, sum = 0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the value of x[%d]: ", i);
        scanf("%f", &x[i]);
    }

    for(i = 0; i < n; i++)
    {
        printf("Enter the value of h[%d]: ", i);
        scanf("%f", &h[i]);
    }

    // Convolution of input signal and impulse response
    for(i = 0; i < n; i++)
    {
        y[i] = 0;
        for(j = 0; j <= i; j++)
        {
            k = i - j;
            sum += x[j] * h[k];
        }
        y[i] = sum;
        sum = 0;
    }

    printf("The output of the signal after convolution is: \n");
    for(i = 0; i < n; i++)
    {
        printf("%.2f ", y[i]);
    }

    // Discrete Fourier transform of the input signal
    for(i = 0; i < n; i++)
    {
        sum = 0;
        for(j = 0; j < n; j++)
        {
            sum += x[j] * cos(2 * pi * j * i / n) - sin(2 * pi * j * i / n);
        }
        hn[i] = sum / n;
    }

    printf("\nThe Discrete Fourier Transform of the input signal is : \n");
    for(i = 0; i < n; i++)
    {
        printf("%f ", hn[i]);
    }

    // Inverse Discrete Fourier transform of the output signal
    for(i = 0; i < n; i++)
    {
        sum = 0;
        for(j = 0; j < n; j++)
        {
            sum += y[j] * cos(2 * pi * j * i / n) + sin(2 * pi * j * i / n);
        }

        yn[i] = sum / n;
    }

    printf("\nThe Inverse Discrete Fourier Transform of the output signal is : \n");
    for(i = 0; i < n; i++)
    {
        printf("%f ", yn[i]);
    }

    printf("\nYay! We have successfully completed our happy Digital Signal Processing program!\n");

    return 0;
}