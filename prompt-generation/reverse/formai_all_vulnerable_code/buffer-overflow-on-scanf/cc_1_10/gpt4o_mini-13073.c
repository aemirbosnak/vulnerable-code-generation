//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute_statistics(double *data, int n, double *mean, double *median, double *stddev);
int compare(const void *a, const void *b);
void calculate_mean(double *data, int n, double *mean);
void calculate_median(double *data, int n, double *median);
void calculate_stddev(double *data, int n, double mean, double *stddev);

int main() {
    int n;
    double *data;
    
    printf("Enter the number of data points: ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        while (getchar() != '\n'); // Clear input buffer
    }

    data = (double*) malloc(n * sizeof(double));
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the data points:\n");
    for (int i = 0; i < n; i++) {
        while (scanf("%lf", &data[i]) != 1) {
            printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n'); // Clear input buffer
        }
    }

    double mean, median, stddev;
    compute_statistics(data, n, &mean, &median, &stddev);
    
    printf("\nStatistics:\n");
    printf("Mean: %.2lf\n", mean);
    printf("Median: %.2lf\n", median);
    printf("Standard Deviation: %.2lf\n", stddev);

    free(data);
    return 0;
}

void compute_statistics(double *data, int n, double *mean, double *median, double *stddev) {
    calculate_mean(data, n, mean);
    calculate_median(data, n, median);
    calculate_stddev(data, n, *mean, stddev);
}

void calculate_mean(double *data, int n, double *mean) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    *mean = sum / n;
}

void calculate_median(double *data, int n, double *median) {
    qsort(data, n, sizeof(double), compare);
    if (n % 2 == 0) {
        *median = (data[n / 2 - 1] + data[n / 2]) / 2.0;
    } else {
        *median = data[n / 2];
    }
}

void calculate_stddev(double *data, int n, double mean, double *stddev) {
    double sum_squared_diff = 0.0;
    for (int i = 0; i < n; i++) {
        sum_squared_diff += (data[i] - mean) * (data[i] - mean);
    }
    *stddev = sqrt(sum_squared_diff / n);
}

int compare(const void *a, const void *b) {
    double num1 = *(const double *)a;
    double num2 = *(const double *)b;
    if (num1 < num2) return -1;
    else if (num1 > num2) return 1;
    return 0;
}