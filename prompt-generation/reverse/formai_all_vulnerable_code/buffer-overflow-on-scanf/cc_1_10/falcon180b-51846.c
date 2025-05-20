//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: Cryptic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    double x[100], y[100], h[100], s[100];

    // read input signal
    printf("Enter the length of the input signal: ");
    scanf("%d", &n);

    printf("Enter the input signal:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }

    // compute hamming window
    for (i = 0; i < n; i++)
    {
        h[i] = 0.54 - 0.46 * cos(2 * M_PI * i / (n - 1));
    }

    // apply windowing
    for (i = 0; i < n; i++)
    {
        x[i] *= h[i];
    }

    // compute DFT
    for (i = 0; i < n; i++)
    {
        s[i] = 0;
        for (j = 0; j < n; j++)
        {
            s[i] += x[j] * cos(2 * M_PI * i * j / n);
        }
    }

    // display DFT
    printf("DFT:\n");
    for (i = 0; i < n; i++)
    {
        printf("%lf ", s[i]);
    }

    return 0;
}