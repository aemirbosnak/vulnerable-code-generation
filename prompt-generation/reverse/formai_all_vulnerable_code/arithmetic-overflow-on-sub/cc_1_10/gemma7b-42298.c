//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int main() {
    int i, j, n, m, k, l, data[MAX], min_dist, max_dist;
    float avg_dist, std_dev, anomaly_score;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the data points: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // Calculate the average distance between data points
    avg_dist = 0.0f;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                min_dist = abs(data[i] - data[j]);
                max_dist = abs(data[i] - data[j]) * 2;
                avg_dist += (min_dist + max_dist) / 2.0f;
            }
        }
    }
    avg_dist /= (n * (n - 1));

    // Calculate the standard deviation of the distance between data points
    std_dev = 0.0f;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                min_dist = abs(data[i] - data[j]);
                max_dist = abs(data[i] - data[j]) * 2;
                std_dev += (min_dist - avg_dist) * (min_dist - avg_dist) / (n * (n - 1));
            }
        }
    }
    std_dev = sqrt(std_dev);

    // Calculate the anomaly score
    anomaly_score = 0.0f;
    for (i = 0; i < n; i++) {
        min_dist = abs(data[i] - avg_dist);
        max_dist = abs(data[i] - avg_dist) * 2;
        anomaly_score += (min_dist - max_dist) / std_dev;
    }

    // Print the anomaly score
    printf("The anomaly score is: %.2f", anomaly_score);

    return 0;
}