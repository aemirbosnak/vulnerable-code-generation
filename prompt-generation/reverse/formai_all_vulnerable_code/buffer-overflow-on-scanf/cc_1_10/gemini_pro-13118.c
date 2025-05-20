//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main() {
    int n, i, j, k, l, m, x, y, z;
    double mean, stddev, median, iqr, skewness, kurtosis;
    int *data;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    data = (int *)malloc(n * sizeof(int));

    printf("Enter the data points:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // Calculate the mean
    mean = 0.0;
    for (i = 0; i < n; i++) {
        mean += data[i];
    }
    mean /= n;

    // Calculate the standard deviation
    stddev = 0.0;
    for (i = 0; i < n; i++) {
        stddev += (data[i] - mean) * (data[i] - mean);
    }
    stddev /= n;
    stddev = sqrt(stddev);

    // Calculate the median
    median = 0.0;
    if (n % 2 == 0) {
        median = (data[n / 2] + data[n / 2 - 1]) / 2.0;
    } else {
        median = data[n / 2];
    }

    // Calculate the interquartile range
    iqr = 0.0;
    if (n % 2 == 0) {
        iqr = data[n / 2 + n / 4 - 1] - data[n / 2 - n / 4];
    } else {
        iqr = data[n / 2 + n / 4] - data[n / 2 - n / 4];
    }

    // Calculate the skewness
    skewness = 0.0;
    for (i = 0; i < n; i++) {
        skewness += (data[i] - mean) * (data[i] - mean) * (data[i] - mean);
    }
    skewness /= n;
    skewness /= (stddev * stddev * stddev);

    // Calculate the kurtosis
    kurtosis = 0.0;
    for (i = 0; i < n; i++) {
        kurtosis += (data[i] - mean) * (data[i] - mean) * (data[i] - mean) * (data[i] - mean);
    }
    kurtosis /= n;
    kurtosis /= (stddev * stddev * stddev * stddev);

    // Print the results
    printf("Mean: %.2f\n", mean);
    printf("Standard deviation: %.2f\n", stddev);
    printf("Median: %.2f\n", median);
    printf("Interquartile range: %.2f\n", iqr);
    printf("Skewness: %.2f\n", skewness);
    printf("Kurtosis: %.2f\n", kurtosis);

    free(data);

    return 0;
}