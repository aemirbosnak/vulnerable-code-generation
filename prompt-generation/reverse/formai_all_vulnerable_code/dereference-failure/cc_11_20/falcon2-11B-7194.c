//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed random number generator

    // Define the number of data points and the number of clusters
    int num_points = 1000;
    int num_clusters = 3;

    // Generate random data points
    int *data_points = (int *)malloc(num_points * sizeof(int));
    for (int i = 0; i < num_points; i++) {
        data_points[i] = rand() % 100; // Generate a random integer between 0 and 99
    }

    // Initialize the centroids randomly
    int *centroids = (int *)malloc(num_clusters * sizeof(int));
    for (int i = 0; i < num_clusters; i++) {
        centroids[i] = rand() % 100; // Generate a random integer between 0 and 99
    }

    // Run k-means algorithm to cluster the data points
    for (int iteration = 0; iteration < 100; iteration++) {
        // Assign each data point to the closest centroid
        for (int i = 0; i < num_points; i++) {
            int closest_index = 0;
            double closest_distance = abs(data_points[i] - centroids[0]);
            for (int j = 1; j < num_clusters; j++) {
                double distance = abs(data_points[i] - centroids[j]);
                if (distance < closest_distance) {
                    closest_index = j;
                    closest_distance = distance;
                }
            }
            data_points[i] = closest_index;
        }

        // Update the centroids based on the assigned data points
        for (int i = 0; i < num_clusters; i++) {
            int count = 0;
            for (int j = 0; j < num_points; j++) {
                if (data_points[j] == i) {
                    count++;
                }
            }
            centroids[i] = count * centroids[i];
        }
    }

    // Print the clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i + 1);
        for (int j = 0; j < num_points; j++) {
            if (data_points[j] == i) {
                printf("%d\n", data_points[j]);
            }
        }
    }

    // Plot the clusters
    for (int i = 0; i < num_clusters; i++) {
        for (int j = 0; j < num_points; j++) {
            if (data_points[j] == i) {
                printf("%d ", data_points[j]);
            }
        }
        printf("\n");
    }

    free(data_points);
    free(centroids);

    return 0;
}