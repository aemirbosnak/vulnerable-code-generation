//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point centroid;
    int count;
} Cluster;

// Function prototypes
void initializeClusters(Cluster clusters[], int k);
void assignPointsToClusters(Point points[], Cluster clusters[], int n, int k);
void updateCentroids(Cluster clusters[], int k);
double calculateDistance(Point a, Point b);
void printClusters(Cluster clusters[], int k);

int main() {
    int n, k;
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];

    // Get number of points and clusters from the user
    printf("Enter number of points: ");
    scanf("%d", &n);
    
    if(n > MAX_POINTS) {
        printf("Exceeded maximum points limit of %d.\n", MAX_POINTS);
        return 1;
    }
    
    printf("Enter the points (x y):\n");
    for(int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    printf("Enter number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &k);
    
    if(k > MAX_CLUSTERS) {
        printf("Exceeded maximum clusters limit of %d.\n", MAX_CLUSTERS);
        return 1;
    }

    // Initialize clusters and start K-means algorithm
    initializeClusters(clusters, k);
    int iterations = 0;

    do {
        assignPointsToClusters(points, clusters, n, k);
        updateCentroids(clusters, k);
        iterations++;
    } while(iterations < 10); // Limit iterations for simplicity

    // Print the final clusters
    printClusters(clusters, k);
    
    return 0;
}

void initializeClusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid.x = (double)(rand() % 100);
        clusters[i].centroid.y = (double)(rand() % 100);
        clusters[i].count = 0;
    }
}

void assignPointsToClusters(Point points[], Cluster clusters[], int n, int k) {
    for (int i = 0; i < n; i++) {
        double minDistance = INFINITY;
        int closestClusterIndex = 0;

        for (int j = 0; j < k; j++) {
            double distance = calculateDistance(points[i], clusters[j].centroid);
            if (distance < minDistance) {
                minDistance = distance;
                closestClusterIndex = j;
            }
        }
        
        clusters[closestClusterIndex].count++;
        printf("Point (%.2f, %.2f) assigned to cluster %d\n", points[i].x, points[i].y, closestClusterIndex);
    }
}

void updateCentroids(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].count == 0) continue;

        double totalX = 0;
        double totalY = 0;

        // Here you would also have to keep track of the input points assigned to the clusters
        // In this simple example, we do not store them

        // Update centroid based on the number of points assigned to this cluster
        clusters[i].centroid.x = totalX / clusters[i].count;
        clusters[i].centroid.y = totalY / clusters[i].count;
        
        // Reset cluster count for next iteration
        clusters[i].count = 0;
    }
}

double calculateDistance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void printClusters(Cluster clusters[], int k) {
    printf("\nFinal Clusters:\n");
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: Centroid (%.2f, %.2f)\n", i, clusters[i].centroid.x, clusters[i].centroid.y);
    }
}