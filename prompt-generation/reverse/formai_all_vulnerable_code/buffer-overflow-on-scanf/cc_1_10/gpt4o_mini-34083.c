//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA_POINTS 100
#define MAX_CLUSTERS 10

// Struct representing a data point
typedef struct {
    float x, y;
    int cluster;
} DataPoint;

// Struct representing a cluster
typedef struct {
    float x, y;
    int count; // Number of points currently in this cluster
} Cluster;

void initialize_clusters(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].x = rand() % 100; // Random initial x coordinate
        clusters[i].y = rand() % 100; // Random initial y coordinate
        clusters[i].count = 0;
    }
}

float calculate_distance(DataPoint point, Cluster cluster) {
    return sqrt(pow(point.x - cluster.x, 2) + pow(point.y - cluster.y, 2));
}

void assign_clusters(DataPoint *dataPoints, Cluster *clusters, int dataPointCount, int clusterCount) {
    for (int i = 0; i < dataPointCount; i++) {
        float minDistance = INFINITY;
        int clusterIndex = -1;

        for (int j = 0; j < clusterCount; j++) {
            float distance = calculate_distance(dataPoints[i], clusters[j]);
            if (distance < minDistance) {
                minDistance = distance;
                clusterIndex = j;
            }
        }
        dataPoints[i].cluster = clusterIndex; // Assign point to the nearest cluster
        clusters[clusterIndex].count++; // Increment count of the assigned cluster
    }
}

void update_centroids(DataPoint *dataPoints, Cluster *clusters, int dataPointCount, int clusterCount) {
    // Reset clusters
    for (int j = 0; j < clusterCount; j++) {
        clusters[j].count = 0;
        clusters[j].x = 0;
        clusters[j].y = 0;
    }

    // Calculate new centroids
    for (int i = 0; i < dataPointCount; i++) {
        int clusterIndex = dataPoints[i].cluster;
        clusters[clusterIndex].x += dataPoints[i].x;
        clusters[clusterIndex].y += dataPoints[i].y;
    }

    for (int j = 0; j < clusterCount; j++) {
        if (clusters[j].count > 0) {
            clusters[j].x /= clusters[j].count; // New x coordinate
            clusters[j].y /= clusters[j].count; // New y coordinate
        }
    }
}

int main() {
    int k; 
    DataPoint dataPoints[MAX_DATA_POINTS];
    Cluster clusters[MAX_CLUSTERS];
    int dataPointCount = 0;

    // Generate random data points for clustering
    printf("Enter number of clusters (k): ");
    scanf("%d", &k);
    
    printf("Generating %d random data points...\n", MAX_DATA_POINTS);
    for (int i = 0; i < MAX_DATA_POINTS; i++) {
        dataPoints[i].x = rand() % 100;
        dataPoints[i].y = rand() % 100;
        dataPointCount++;
    }

    initialize_clusters(clusters, k);

    int iteration = 0;
    while (iteration < 100) {
        printf("Iteration %d:\n", iteration + 1);
        assign_clusters(dataPoints, clusters, dataPointCount, k);

        for (int j = 0; j < k; j++) {
            printf("Cluster %d: (%f, %f)\n", j, clusters[j].x, clusters[j].y);
        }

        update_centroids(dataPoints, clusters, dataPointCount, k);
        iteration++;
    }

    // Display final clusters
    printf("Final clusters:\n");
    for (int j = 0; j < k; j++) {
        printf("Cluster %d center: (%f, %f)\n", j, clusters[j].x, clusters[j].y);
    }

    return 0;
}