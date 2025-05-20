//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the number of clusters
#define K 3

// Define the number of points
#define N 10

// Define a structure to store the point
struct Point {
    int x;
    int y;
};

// Define a function to calculate the distance between two points
double distance(struct Point a, struct Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    // Initialize the points
    struct Point points[N] = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}};

    // Initialize the centroids with random points
    struct Point centroids[K] = {points[0], points[5], points[9]};

    // Set the clusters for each point
    int clusters[N];

    // Repeat until convergence
    while (1) {
        // Initialize the distance to the closest centroid for each point
        double minDistances[N];
        for (int i = 0; i < N; i++) {
            minDistances[i] = distance(points[i], centroids[0]);
            clusters[i] = 0;
            for (int j = 1; j < K; j++) {
                double dist = distance(points[i], centroids[j]);
                if (dist < minDistances[i]) {
                    minDistances[i] = dist;
                    clusters[i] = j;
                }
            }
        }

        // Initialize the sum of points for each cluster
        struct Point sums[K] = {{0, 0}, {0, 0}, {0, 0}};
        int counts[K] = {0, 0, 0};

        // Calculate the sum of points for each cluster
        for (int i = 0; i < N; i++) {
            sums[clusters[i]].x += points[i].x;
            sums[clusters[i]].y += points[i].y;
            counts[clusters[i]]++;
        }

        // Calculate the new centroids
        struct Point newCentroids[K];
        for (int i = 0; i < K; i++) {
            newCentroids[i].x = counts[i] == 0 ? centroids[i].x : sums[i].x / counts[i];
            newCentroids[i].y = counts[i] == 0 ? centroids[i].y : sums[i].y / counts[i];
        }

        // Check for convergence
        int converged = 1;
        for (int i = 0; i < K; i++) {
            if (newCentroids[i].x != centroids[i].x || newCentroids[i].y != centroids[i].y) {
                converged = 0;
                break;
            }
        }
        if (converged) {
            break;
        }

        // Update the centroids
        for (int i = 0; i < K; i++) {
            centroids[i] = newCentroids[i];
        }
    }

    // Print the clusters
    printf("Clusters:\n");
    for (int i = 0; i < K; i++) {
        printf("Cluster %d: [", i);
        for (int j = 0; j < N; j++) {
            if (clusters[j] == i) {
                printf("(%d, %d) ", points[j].x, points[j].y);
            }
        }
        printf("]\n");
    }

    return 0;
}