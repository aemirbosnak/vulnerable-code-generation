//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA 100
#define MAX_CLUSTERS 10

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_DATA];
    int count;
} Cluster;

double euclideanDistance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void initializeClusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid.x = rand() % 100; // Random x in [0, 100)
        clusters[i].centroid.y = rand() % 100; // Random y in [0, 100)
        clusters[i].count = 0; // Initialize point count
    }
}

void assignClusters(Point points[], int n, Cluster clusters[], int k) {
    // Reset cluster points count
    for (int i = 0; i < k; i++) {
        clusters[i].count = 0;
    }

    for (int i = 0; i < n; i++) {
        double minDist = 1e9; // Start with a large number
        int assignedCluster = 0;

        for (int j = 0; j < k; j++) {
            double dist = euclideanDistance(points[i], clusters[j].centroid);
            if (dist < minDist) {
                minDist = dist;
                assignedCluster = j;
            }
        }

        clusters[assignedCluster].points[clusters[assignedCluster].count++] = points[i];
    }
}

void updateCentroids(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        double sumX = 0, sumY = 0;
        if (clusters[i].count == 0) continue; // Avoid division by zero

        for (int j = 0; j < clusters[i].count; j++) {
            sumX += clusters[i].points[j].x;
            sumY += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sumX / clusters[i].count;
        clusters[i].centroid.y = sumY / clusters[i].count;
    }
}

void displayClusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        printf(" Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf(" Points:\n");

        for (int j = 0; j < clusters[i].count; j++) {
            printf("  (%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

int main() {
    int n, k;

    printf("Enter number of data points: ");
    scanf("%d", &n);
    printf("Enter number of clusters: ");
    scanf("%d", &k);

    if (k > MAX_CLUSTERS || n > MAX_DATA) {
        printf("Exceeded maximum data or cluster limits.\n");
        return 1;
    }

    Point points[MAX_DATA];
    Cluster clusters[MAX_CLUSTERS];

    printf("Enter the data points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    // Initialize clusters
    initializeClusters(clusters, k);

    // Perform K-Means clustering
    for (int iteration = 0; iteration < 10; iteration++) {
        assignClusters(points, n, clusters, k);
        updateCentroids(clusters, k);
    }

    // Display clustered results
    displayClusters(clusters, k);

    return 0;
}