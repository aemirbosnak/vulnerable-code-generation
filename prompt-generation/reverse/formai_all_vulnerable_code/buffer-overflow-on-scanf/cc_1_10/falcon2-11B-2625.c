//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

void kmeans(float *data, int n, int k, float *centroids, int *clusters) {
    int i, j;
    float bestdist, min_dist;
    float *distances = malloc(k * sizeof(float));
    int *members = malloc(k * sizeof(int));

    // Initialize centroids randomly
    for (i = 0; i < k; i++) {
        centroids[i] = data[rand() % n];
    }

    // Calculate initial distances
    for (i = 0; i < k; i++) {
        distances[i] = 0.0;
        for (j = 0; j < n; j++) {
            distances[i] += (data[j] - centroids[i]) * (data[j] - centroids[i]);
        }
        distances[i] = sqrt(distances[i]);
    }

    // Assign data points to clusters
    for (i = 0; i < n; i++) {
        min_dist = distances[0];
        for (j = 0; j < k; j++) {
            if (distances[j] < min_dist) {
                min_dist = distances[j];
                members[i] = j;
            }
        }
    }

    // Update centroids
    for (i = 0; i < k; i++) {
        bestdist = 0.0;
        for (j = 0; j < n; j++) {
            if (members[j] == i) {
                bestdist += (data[j] - centroids[i]) * (data[j] - centroids[i]);
            }
        }
        centroids[i] = (bestdist / n);
    }

    // Free memory
    free(distances);
    free(members);
}

int main() {
    int n, k;
    float *data, *centroids;
    int *clusters;

    printf("Enter the number of data points: ");
    scanf("%d", &n);
    data = (float *)malloc(n * sizeof(float));
    printf("Enter the data points:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &data[i]);
    }
    printf("Enter the number of clusters: ");
    scanf("%d", &k);
    centroids = (float *)malloc(k * sizeof(float));
    clusters = (int *)malloc(n * sizeof(int));
    kmeans(data, n, k, centroids, clusters);

    printf("Centroids:\n");
    for (int i = 0; i < k; i++) {
        printf("%f\n", centroids[i]);
    }
    printf("Clusters:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", clusters[i]);
    }
    printf("\n");

    return 0;
}