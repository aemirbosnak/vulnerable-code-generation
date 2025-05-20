//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_POINTS 1000

void calculate_mean(float data[], int n, float *mean) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    *mean = sum / n;
}

void calculate_median(float data[], int n, float *median) {
    // First, we need to sort the data to find the median
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                float temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    // Now find the median
    if (n % 2 == 0) {
        *median = (data[n / 2 - 1] + data[n / 2]) / 2.0;
    } else {
        *median = data[n / 2];
    }
}

void find_max_min(float data[], int n, float *max, float *min) {
    *max = data[0];
    *min = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > *max) {
            *max = data[i];
        }
        if (data[i] < *min) {
            *min = data[i];
        }
    }
}

int main() {
    FILE *file;
    float data[MAX_DATA_POINTS];
    int n = 0;

    // Open the file for reading
    file = fopen("data.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    // Read data from the file
    while (fscanf(file, "%f", &data[n]) != EOF && n < MAX_DATA_POINTS) {
        n++;
    }
    fclose(file);

    if (n == 0) {
        fprintf(stderr, "No data found in file.\n");
        return 1;
    }

    float mean, median, max, min;
    calculate_mean(data, n, &mean);
    calculate_median(data, n, &median);
    find_max_min(data, n, &max, &min);

    // Display the results
    printf("Data Analysis Results:\n");
    printf("-----------------------\n");
    printf("Number of data points: %d\n", n);
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Max: %.2f\n", max);
    printf("Min: %.2f\n", min);

    return 0;
}