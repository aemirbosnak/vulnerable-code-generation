//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2
#define MAX_ITERATIONS 100
#define TOLERANCE 0.0001

typedef struct {
    double coordinates[DIMENSIONS];
} DataPoint;

typedef struct {
    DataPoint centroid;
    int count;
} Cluster;

DataPoint dataPoints[MAX_DATA_POINTS];
Cluster clusters[MAX_CLUSTERS];
int dataPointCount = 0;
int clusterCount = 0;

// Function to calculate the Euclidean distance between two data points
double euclideanDistance(DataPoint a, DataPoint b) {
    double distance = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        distance += (a.coordinates[i] - b.coordinates[i]) * (a.coordinates[i] - b.coordinates[i]);
    }
    return sqrt(distance);
}

// Function to initialize clusters with random data points
void initializeClusters() {
    for (int i = 0; i < clusterCount; i++) {
        clusters[i].centroid = dataPoints[rand() % dataPointCount];
        clusters[i].count = 0;
    }
}

// Function to assign data points to the nearest cluster
void assignClusters() {
    for (int i = 0; i < clusterCount; i++) {
        clusters[i].count = 0; // Reset cluster count
    }

    for (int i = 0; i < dataPointCount; i++) {
        double minDistance = INFINITY;
        int closestClusterIdx = -1;
        for (int j = 0; j < clusterCount; j++) {
            double distance = euclideanDistance(dataPoints[i], clusters[j].centroid);
            if (distance < minDistance) {
                minDistance = distance;
                closestClusterIdx = j;
            }
        }
        clusters[closestClusterIdx].count++;
    }
}

// Function to update centroids of clusters
void updateCentroids() {
    for (int i = 0; i < clusterCount; i++) {
        for (int d = 0; d < DIMENSIONS; d++) {
            clusters[i].centroid.coordinates[d] = 0.0; // Reset centroid
        }
    }

    for (int i = 0; i < dataPointCount; i++) {
        double minDistance = INFINITY;
        int closestClusterIdx = -1;
        for (int j = 0; j < clusterCount; j++) {
            double distance = euclideanDistance(dataPoints[i], clusters[j].centroid);
            if (distance < minDistance) {
                minDistance = distance;
                closestClusterIdx = j;
            }
        }
        for (int d = 0; d < DIMENSIONS; d++) {
            clusters[closestClusterIdx].centroid.coordinates[d] += dataPoints[i].coordinates[d];
        }
    }

    for (int i = 0; i < clusterCount; i++) {
        if (clusters[i].count > 0) {
            for (int d = 0; d < DIMENSIONS; d++) {
                clusters[i].centroid.coordinates[d] /= clusters[i].count; // Calculate new centroid
            }
        }
    }
}

// Function to check for convergence
int hasConverged(double oldCentroids[MAX_CLUSTERS][DIMENSIONS]) {
    for (int i = 0; i < clusterCount; i++) {
        for (int d = 0; d < DIMENSIONS; d++) {
            if (fabs(oldCentroids[i][d] - clusters[i].centroid.coordinates[d]) > TOLERANCE) {
                return 0; // Not converged
            }
        }
    }
    return 1; // Converged
}

// Function to read data points from the user
void readDataPoints() {
    printf("Enter number of data points (max %d): ", MAX_DATA_POINTS);
    scanf("%d", &dataPointCount);
    if (dataPointCount > MAX_DATA_POINTS) {
        printf("Too many data points. Limiting to %d.\n", MAX_DATA_POINTS);
        dataPointCount = MAX_DATA_POINTS;
    }

    for (int i = 0; i < dataPointCount; i++) {
        printf("Enter coordinates for point %d (x y): ", i + 1);
        scanf("%lf %lf", &dataPoints[i].coordinates[0], &dataPoints[i].coordinates[1]);
    }
}

// Function to display clusters and centroids
void displayClusters() {
    printf("\nClusters and their centroids:\n");
    for (int i = 0; i < clusterCount; i++) {
        printf("Cluster %d centroid: (%.2f, %.2f) with %d points\n", 
            i + 1, 
            clusters[i].centroid.coordinates[0], 
            clusters[i].centroid.coordinates[1], 
            clusters[i].count);
    }
}

int main() {
    srand(time(NULL));

    printf("Enter the number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &clusterCount);
    if (clusterCount > MAX_CLUSTERS) {
        printf("Too many clusters. Limiting to %d.\n", MAX_CLUSTERS);
        clusterCount = MAX_CLUSTERS;
    }

    readDataPoints();
    initializeClusters();

    double oldCentroids[MAX_CLUSTERS][DIMENSIONS];
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        // Store old centroids for checking convergence
        for (int i = 0; i < clusterCount; i++) {
            for (int d = 0; d < DIMENSIONS; d++) {
                oldCentroids[i][d] = clusters[i].centroid.coordinates[d];
            }
        }

        assignClusters();
        updateCentroids();

        // Check for convergence
        if (hasConverged(oldCentroids)) {
            printf("Converged after %d iterations.\n", iteration + 1);
            break;
        }
    }

    displayClusters();
    return 0;
}