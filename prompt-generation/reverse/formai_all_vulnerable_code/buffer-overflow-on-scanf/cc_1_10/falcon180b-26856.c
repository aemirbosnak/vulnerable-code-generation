//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define TRUE 1
#define FALSE 0

// Function prototypes
void filter(double x[], int n, double y[], int m);

int main() {
    int n, m;
    double x[100], y[100];

    // Get input signal length
    printf("Enter the length of the input signal: ");
    scanf("%d", &n);

    // Get filter length
    printf("Enter the length of the filter: ");
    scanf("%d", &m);

    // Get input signal
    printf("Enter the input signal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    // Apply filter
    filter(x, n, y, m);

    // Print output signal
    printf("Output signal:\n");
    for (int i = 0; i < m; i++) {
        printf("%lf\n", y[i]);
    }

    return 0;
}

// Filter function using convolution
void filter(double x[], int n, double y[], int m) {
    int i, j, k;
    double sum = 0;

    // Initialize output signal
    for (i = 0; i < m; i++) {
        y[i] = 0;
    }

    // Apply filter
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            sum += x[j] * y[i - j];
        }
        y[i] = sum;
        sum = 0;
    }
}