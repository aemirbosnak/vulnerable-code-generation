//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: careful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function prototypes
double sum_series(int n, double a, double d);
double average(int n, double arr[]);
void print_array(int n, double arr[]);

int main() {
    int n, i;
    double a, d, sum;
    double *arr;

    // Get user input
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Enter the first term: ");
    scanf("%lf", &a);
    printf("Enter the common difference: ");
    scanf("%lf", &d);

    // Calculate sum of series
    sum = sum_series(n, a, d);

    // Print result
    printf("The sum of the series is: %.2lf\n", sum);

    // Get array input
    printf("Enter %d integers:\n", n);
    arr = (double *)malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    // Calculate average
    printf("The average is: %.2lf\n", average(n, arr));

    // Print array
    printf("The array is:\n");
    print_array(n, arr);

    // Free memory
    free(arr);

    return 0;
}

// Function to calculate sum of series
double sum_series(int n, double a, double d) {
    double sum = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        sum += a + i * d;
    }
    return sum;
}

// Function to calculate average
double average(int n, double arr[]) {
    double sum = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to print array
void print_array(int n, double arr[]) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%.2lf ", arr[i]);
    }
    printf("\n");
}