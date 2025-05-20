//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N, i, j;
    double x[100], y[100], h[100];
    double sum = 0, temp;
    double f[100], g[100];

    // Take input from user for N
    printf("Enter the value of N: ");
    scanf("%d", &N);

    // Take input from user for x[n]
    printf("Enter the values of x[n]: ");
    for (i = 0; i < N; i++) {
        scanf("%lf", &x[i]);
    }

    // Calculate h[n]
    for (i = 0; i < N; i++) {
        h[i] = (double)i / N;
    }

    // Calculate f[n]
    for (i = 0; i < N; i++) {
        f[i] = 0;
        for (j = 0; j < N; j++) {
            temp = h[j] * x[(i - j + N) % N];
            f[i] += temp;
        }
    }

    // Calculate g[n]
    for (i = 0; i < N; i++) {
        g[i] = 0;
        for (j = 0; j < N; j++) {
            temp = h[j] * f[(i - j + N) % N];
            g[i] += temp;
        }
    }

    // Calculate y[n]
    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < N; j++) {
            temp = h[j] * g[(i - j + N) % N];
            sum += temp;
        }
        y[i] = sum;
    }

    // Print the results
    printf("The values of y[n] are:\n");
    for (i = 0; i < N; i++) {
        printf("%lf\n", y[i]);
    }

    return 0;
}