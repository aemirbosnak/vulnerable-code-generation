//FormAI DATASET v1.0 Category: Data mining ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i, j, k, n, m;
    float **data, **centroids, *distances, min_distance;
    int *assignments, *counts;
    float change, threshold = 0.01;
    int iterations = 100;

    // Load data from file
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error: cannot open file.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(file, "%d,%d", &n, &m);
    data = (float **) malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        data[i] = (float *) malloc(m * sizeof(float));
        for (j = 0; j < m; j++) {
            fscanf(file, ",%f", &data[i][j]);
        }
    }
    fclose(file);

    // Initialize centroids randomly
    centroids = (float **) malloc(k * sizeof(float *));
    for (i = 0; i < k; i++) {
        centroids[i] = (float *) malloc(m * sizeof(float));
        for (j = 0; j < m; j++) {
            centroids[i][j] = data[rand() % n][j];
        }
    }

    // Allocate memory for other variables
    distances = (float *) malloc(k * sizeof(float));
    assignments = (int *) malloc(n * sizeof(int));
    counts = (int *) malloc(k * sizeof(int));

    // Run K-means algorithm
    for (i = 0; i < iterations; i++) {
        // Assign data points to nearest centroids
        change = 0;
        for (j = 0; j < n; j++) {
            min_distance = HUGE_VALF;
            for (k = 0; k < k; k++) {
                distances[k] = 0;
                for (m = 0; m < m; m++) {
                    distances[k] += pow(data[j][m] - centroids[k][m], 2);
                }
                if (distances[k] < min_distance) {
                    min_distance = distances[k];
                    assignments[j] = k;
                }
            }
            change += distances[assignments[j]];
        }
        if (change / n < threshold) {
            break;
        }

        // Recompute centroids for each group of data points
        for (k = 0; k < k; k++) {
            for (m = 0; m < m; m++) {
                centroids[k][m] = 0;
            }
            counts[k] = 0;
        }
        for (j = 0; j < n; j++) {
            for (m = 0; m < m; m++) {
                centroids[assignments[j]][m] += data[j][m];
            }
            counts[assignments[j]]++;
        }
        for (k = 0; k < k; k++) {
            for (m = 0; m < m; m++) {
                if (counts[k] > 0) {
                    centroids[k][m] /= counts[k];
                }
            }
        }
    }

    // Print final results
    for (k = 0; k < k; k++) {
        printf("Centroid %d: [ ", k);
        for (m = 0; m < m; m++) {
            printf("%f ", centroids[k][m]);
        }
        printf("]\n");
    }
    for (j = 0; j < n; j++) {
        printf("Data point %d assigned to centroid %d.\n", j, assignments[j]);
    }

    // Free memory
    for (i = 0; i < n; i++) {
        free(data[i]);
    }
    free(data);
    for (i = 0; i < k; i++) {
        free(centroids[i]);
    }
    free(centroids);
    free(distances);
    free(assignments);
    free(counts);

    return 0;
}