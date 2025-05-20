//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

int main() {
    int i, j;
    double a, b, h;
    double x[N], y[N];

    // Prompt user for function
    printf("Enter the function in the form of y = f(x): ");
    scanf("%lf", &a);
    scanf("%lf", &b);

    // Calculate step size
    h = (b - a) / N;

    // Calculate x values
    for (i = 0; i <= N; i++) {
        x[i] = a + (i * h);
    }

    // Calculate y values
    for (i = 0; i <= N; i++) {
        y[i] = a + (i * h);
    }

    // Plot graph
    printf("x\ty\n");
    for (i = 0; i <= N; i++) {
        for (j = 0; j <= N; j++) {
            if (i == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Draw x-axis
    printf("x-axis\n");
    for (i = 0; i <= N; i++) {
        printf("%lf ", x[i]);
    }
    printf("\n");

    // Draw y-axis
    printf("y-axis\n");
    for (i = 0; i <= N; i++) {
        printf("%lf ", y[i]);
    }
    printf("\n");

    // Draw line of best fit
    double m, c;
    m = (y[N] - y[0]) / (x[N] - x[0]);
    c = y[0] - m * x[0];
    printf("Line of best fit: y = %lfx + %lf\n", m, c);

    // Plot line of best fit
    printf("*");
    for (i = 0; i <= N; i++) {
        printf(" ");
    }
    printf("\n");
    for (i = 0; i <= N; i++) {
        printf("%lf ", x[i]);
        printf("*");
    }
    printf("\n");

    return 0;
}