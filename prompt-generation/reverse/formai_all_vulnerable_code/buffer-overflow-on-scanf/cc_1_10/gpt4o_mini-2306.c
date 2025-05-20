//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LOVERS 100  // Maximum number of points
#define DIMENSIONS 2    // Number of dimensions
#define K 3             // Number of clusters (lovers)

typedef struct {
    float position[DIMENSIONS];
    int cluster;
} Lover;

// Function to calculate the distance between two lovers
float distance(Lover *l1, Lover *l2) {
    return sqrt(pow(l1->position[0] - l2->position[0], 2) + 
                pow(l1->position[1] - l2->position[1], 2));
}

// Function to find the nearest centroids for each lover
void assignClusters(Lover lovers[], Lover centroids[], int numLovers) {
    for (int i = 0; i < numLovers; i++) {
        float minDistance = INFINITY;
        int closestCluster = -1;

        for (int j = 0; j < K; j++) {
            float dist = distance(&lovers[i], &centroids[j]);
            if (dist < minDistance) {
                minDistance = dist;
                closestCluster = j;
            }
        }
        lovers[i].cluster = closestCluster; // Assign the closest cluster
    }
}

// Function to update centroids based on lover positions
void updateCentroids(Lover lovers[], Lover centroids[], int numLovers) {
    int counts[K] = {0}; // Count of lovers in each cluster
    for (int i = 0; i < K; i++) {
        centroids[i].position[0] = 0;
        centroids[i].position[1] = 0;
    }

    for (int i = 0; i < numLovers; i++) {
        centroids[lovers[i].cluster].position[0] += lovers[i].position[0];
        centroids[lovers[i].cluster].position[1] += lovers[i].position[1];
        counts[lovers[i].cluster]++;
    }

    for (int i = 0; i < K; i++) {
        if (counts[i] != 0) { // To avoid division by zero
            centroids[i].position[0] /= counts[i];
            centroids[i].position[1] /= counts[i];
        }
    }
}

// Function to display the lovers and their assigned clusters
void displayLovers(Lover lovers[], int numLovers) {
    printf("Lovers' positions and their clusters:\n");
    for (int i = 0; i < numLovers; i++) {
        printf("Lover %d: (%.2f, %.2f) - Cluster %d\n", 
               i + 1, lovers[i].position[0], lovers[i].position[1], lovers[i].cluster + 1);
    }
}

int main() {
    Lover lovers[MAX_LOVERS];
    Lover centroids[K] = {
        {{1.0, 1.0}, 0},
        {{5.0, 5.0}, 1},
        {{9.0, 1.0}, 2}
    };
    int numLovers;

    printf("Enter the number of lovers (max %d): ", MAX_LOVERS);
    scanf("%d", &numLovers);

    // Generate random positions for the lovers
    srand(42); // For reproducibility
    for (int i = 0; i < numLovers; i++) {
        lovers[i].position[0] = rand() % 10; // x-coordinate
        lovers[i].position[1] = rand() % 10; // y-coordinate
        lovers[i].cluster = -1; // Initially, no cluster
    }

    // Start clustering process
    int iterations = 0;
    int changed;
    do {
        changed = 0;
        assignClusters(lovers, centroids, numLovers);
        Lover oldCentroids[K] = {{0}}; // Store old centroids for comparison

        for (int i = 0; i < K; i++) {
            oldCentroids[i] = centroids[i]; // Save current centroids
        }

        updateCentroids(lovers, centroids, numLovers); // Update centroids

        // Check if centroids have changed
        for (int i = 0; i < K; i++) {
            if (distance(&oldCentroids[i], &centroids[i]) > 0.001) {
                changed = 1; // Centroids changed
            }
        }
        iterations++;
    } while (changed && iterations < 100); // Loop until convergence or max iterations

    // Display final clusters
    displayLovers(lovers, numLovers);
    return 0;
}