//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2

typedef struct {
    double coordinates[DIMENSIONS];
    int cluster;
} Point;

typedef struct {
    double center[DIMENSIONS];
    int size;
} Cluster;

void initializePoints(Point points[], int n);
void initializeClusters(Cluster clusters[], int k);
void assignClusters(Point points[], int n, Cluster clusters[], int k);
void updateClusters(Point points[], int n, Cluster clusters[], int k);
double calculateDistance(double a[], double b[]);
void printClusters(Point points[], int n, Cluster clusters[], int k);

int main() {
    int n, k;

    printf("Welcome to the peaceful K-Means Clustering Algorithm!\n");
    printf("Please enter the number of data points (max %d): ", MAX_POINTS);
    scanf("%d", &n);

    if (n > MAX_POINTS) {
        printf("Too many points. Please restart the program.\n");
        return 1;
    }

    Point points[n];
    initializePoints(points, n);

    printf("Enter the number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &k);

    if (k > MAX_CLUSTERS) {
        printf("Too many clusters. Please restart the program.\n");
        return 1;
    }

    Cluster clusters[k];
    initializeClusters(clusters, k);

    int iterations = 0;
    while (1) {
        assignClusters(points, n, clusters, k);
        updateClusters(points, n, clusters, k);
        
        // Simple stopping condition based on cluster sizes
        if (++iterations > 10) break; 
    }

    printf("Final Clusters:\n");
    printClusters(points, n, clusters, k);

    return 0;
}

void initializePoints(Point points[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter coordinates for point %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].coordinates[0], &points[i].coordinates[1]);
        points[i].cluster = -1; // Initialize cluster as unassigned
    }
}

void initializeClusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        printf("Enter initial center for cluster %d (x y): ", i + 1);
        scanf("%lf %lf", &clusters[i].center[0], &clusters[i].center[1]);
        clusters[i].size = 0;
    }
}

void assignClusters(Point points[], int n, Cluster clusters[], int k) {
    for (int i = 0; i < n; i++) {
        double minDistance = INFINITY;
        int bestCluster = -1;

        for (int j = 0; j < k; j++) {
            double distance = calculateDistance(points[i].coordinates, clusters[j].center);
            if (distance < minDistance) {
                minDistance = distance;
                bestCluster = j;
            }
        }

        points[i].cluster = bestCluster;
        clusters[bestCluster].size++;
    }
}

void updateClusters(Point points[], int n, Cluster clusters[], int k) {
    for (int j = 0; j < k; j++) {
        double sum[DIMENSIONS] = {0};
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (points[i].cluster == j) {
                sum[0] += points[i].coordinates[0];
                sum[1] += points[i].coordinates[1];
                count++;
            }
        }

        if (count > 0) {
            clusters[j].center[0] = sum[0] / count;
            clusters[j].center[1] = sum[1] / count;
            clusters[j].size = count;
        }
    }
}

double calculateDistance(double a[], double b[]) {
    return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
}

void printClusters(Point points[], int n, Cluster clusters[], int k) {
    for (int j = 0; j < k; j++) {
        printf("Cluster %d: (Center: (%.2f, %.2f), Points: ", j + 1, clusters[j].center[0], clusters[j].center[1]);
        for (int i = 0; i < n; i++) {
            if (points[i].cluster == j) {
                printf("(%.2f, %.2f) ", points[i].coordinates[0], points[i].coordinates[1]);
            }
        }
        printf(")\n");
    }
}