//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: happy
// Data mining example program in a happy style

#include <stdio.h>

int main() {
    // Define variables
    int data[100];
    int i, j, k, l, m;
    int min_index, max_index;
    int min_value, max_value;

    // Get user input
    for (i = 0; i < 100; i++) {
        printf("Enter a number: ");
        scanf("%d", &data[i]);
    }

    // Find the minimum and maximum values
    min_value = data[0];
    max_value = data[0];
    for (j = 0; j < 100; j++) {
        if (data[j] < min_value) {
            min_index = j;
            min_value = data[j];
        }
        if (data[j] > max_value) {
            max_index = j;
            max_value = data[j];
        }
    }

    // Print the minimum and maximum values
    printf("The minimum value is %d, which is at index %d\n", min_value, min_index);
    printf("The maximum value is %d, which is at index %d\n", max_value, max_index);

    // Find the mean and median
    float mean = 0.0;
    for (k = 0; k < 100; k++) {
        mean += data[k];
    }
    mean /= 100.0;
    printf("The mean is %f\n", mean);

    // Find the median
    int median = 0;
    if (100 % 2 == 0) {
        median = (data[49] + data[50]) / 2;
    } else {
        median = data[49];
    }
    printf("The median is %d\n", median);

    // Find the standard deviation
    float std_dev = 0.0;
    for (l = 0; l < 100; l++) {
        std_dev += (data[l] - mean) * (data[l] - mean);
    }
    std_dev /= 100.0;
    std_dev = sqrt(std_dev);
    printf("The standard deviation is %f\n", std_dev);

    // Find the quartiles
    float q1 = 0.0;
    float q3 = 0.0;
    if (100 % 2 == 0) {
        q1 = (data[24] + data[25]) / 2;
        q3 = (data[75] + data[76]) / 2;
    } else {
        q1 = data[24];
        q3 = data[75];
    }
    printf("The first quartile is %f\n", q1);
    printf("The third quartile is %f\n", q3);

    // Find the IQR
    float iqr = q3 - q1;
    printf("The interquartile range is %f\n", iqr);

    // Find the outliers
    for (m = 0; m < 100; m++) {
        if (data[m] < q1 - 1.5 * iqr || data[m] > q3 + 1.5 * iqr) {
            printf("Outlier at index %d: %d\n", m, data[m]);
        }
    }

    return 0;
}