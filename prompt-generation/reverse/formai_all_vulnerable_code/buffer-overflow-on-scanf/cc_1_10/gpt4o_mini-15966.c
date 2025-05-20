//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculate_statistics(float *data, int n, float *mean, float *median, float *mode, float *std_dev, float *variance) {
    float sum = 0.0;
    int i, j;
    int count[100] = {0}; // assuming a maximum of 100 different numbers for mode

    // Calculate mean
    for (i = 0; i < n; i++) {
        sum += data[i];
    }
    *mean = sum / n;

    // Calculate median
    // Sort the data for median calculation
    float temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (data[j] > data[j+1]) {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
    if (n % 2 == 0) {
        *median = (data[n/2 - 1] + data[n/2]) / 2;
    } else {
        *median = data[n/2];
    }

    // Calculate mode
    for (i = 0; i < n; i++) {
        count[(int)data[i]]++;
    }
    int max_count = 0;
    for (i = 0; i < 100; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
            *mode = i;
        }
    }

    // Calculate variance
    *variance = 0.0; // Reset variance
    for (i = 0; i < n; i++) {
        *variance += pow(data[i] - *mean, 2);
    }
    *variance /= n;

    // Calculate standard deviation
    *std_dev = sqrt(*variance);
}

int main() {
    int n, i;
    float *data;
    float mean, median, mode, std_dev, variance;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Number of elements must be positive.\n");
        return 1;
    }

    // Dynamically allocate memory for data
    data = (float *)malloc(n * sizeof(float));
    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &data[i]);
    }

    // Compute statistics
    calculate_statistics(data, n, &mean, &median, &mode, &std_dev, &variance);

    // Print statistics
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode: %.0f\n", mode);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", std_dev);

    // Free allocated memory
    free(data);
    return 0;
}