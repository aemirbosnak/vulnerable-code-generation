//Gemma-7B DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Define variables
    int n, i, j, k, l, m, f, g;
    double a, b, c, d, e, f_avg, f_max, f_min, x, y, z;

    // Read input data
    scanf("Enter the number of data points: ", &n);

    // Allocate memory for data
    double *data = (double *)malloc(n * sizeof(double));

    // Read data from file
    printf("Enter the data points: ");
    for (i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
    }

    // Calculate the average, maximum, and minimum values
    f_avg = 0.0;
    for (i = 0; i < n; i++) {
        f_avg += data[i];
    }
    f_avg /= n;

    f_max = data[0];
    for (i = 0; i < n; i++) {
        if (data[i] > f_max) {
            f_max = data[i];
        }
    }

    f_min = data[0];
    for (i = 0; i < n; i++) {
        if (data[i] < f_min) {
            f_min = data[i];
        }
    }

    // Calculate other statistics
    x = f_avg - 2 * f_min;
    y = 3 * f_max - 2 * f_avg;
    z = (f_max - f_min) / f_avg;

    // Print results
    printf("The average value is: %.2lf\n", f_avg);
    printf("The maximum value is: %.2lf\n", f_max);
    printf("The minimum value is: %.2lf\n", f_min);
    printf("The value of x is: %.2lf\n", x);
    printf("The value of y is: %.2lf\n", y);
    printf("The value of z is: %.2lf\n", z);

    // Free memory
    free(data);

    return 0;
}