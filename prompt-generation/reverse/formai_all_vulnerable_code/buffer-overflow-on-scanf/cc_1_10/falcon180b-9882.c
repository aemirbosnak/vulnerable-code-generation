//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int i, j, n;
    double a, b, x, y, sum;
    double *x_array, *y_array;

    // Prompt user for number of points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Generate random data
    x_array = (double*) malloc(n * sizeof(double));
    y_array = (double*) malloc(n * sizeof(double));
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        x_array[i] = rand() % 100;
        y_array[i] = rand() % 100;
    }

    // Calculate sum of x and y
    sum = 0;
    for (i = 0; i < n; i++) {
        sum += x_array[i] + y_array[i];
    }

    // Calculate mean of x and y
    a = sum / n;

    // Calculate standard deviation of x and y
    b = 0;
    for (i = 0; i < n; i++) {
        b += pow((x_array[i] - a), 2) + pow((y_array[i] - a), 2);
    }
    b = sqrt(b / n);

    // Print results
    printf("Number of points: %d\n", n);
    printf("Mean: %.2f\n", a);
    printf("Standard deviation: %.2f\n", b);

    // Free memory
    free(x_array);
    free(y_array);

    return 0;
}