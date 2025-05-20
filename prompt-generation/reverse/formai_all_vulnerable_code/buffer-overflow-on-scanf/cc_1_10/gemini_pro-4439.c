//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data mining function to find patterns in data
void data_mining(int *data, int n) {
    // Initialize variables
    int i, j, k;
    double mean = 0, std_dev = 0;

    // Calculate the mean
    for (i = 0; i < n; i++) {
        mean += data[i];
    }
    mean /= n;

    // Calculate the standard deviation
    for (i = 0; i < n; i++) {
        std_dev += pow(data[i] - mean, 2);
    }
    std_dev /= n;
    std_dev = sqrt(std_dev);

    // Find patterns in the data
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            for (k = j + 1; k < n; k++) {
                // Check if the three points are collinear
                if ((data[j] - data[i]) * (data[k] - data[j]) == (data[k] - data[i]) * (data[j] - data[i])) {
                    // Print the collinear points
                    printf("Collinear points: (%d, %d), (%d, %d), (%d, %d)\n", data[i], i, data[j], j, data[k], k);
                }
            }
        }
    }
}

int main() {
    // Get the data
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    int *data = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter data point %d: ", i + 1);
        scanf("%d", &data[i]);
    }

    // Perform data mining
    data_mining(data, n);

    // Free the allocated memory
    free(data);

    return 0;
}