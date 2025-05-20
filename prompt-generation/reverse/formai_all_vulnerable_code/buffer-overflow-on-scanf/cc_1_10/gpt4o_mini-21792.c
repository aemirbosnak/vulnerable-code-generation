//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: beginner-friendly
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
    Point points[MAX_POINTS];
    int size;
} Cluster;

// Function prototypes
double distance(Point a, Point b);
void assignPointsToClusters(Cluster clusters[], int numClusters, Point points[], int numPoints);
void updateCentroids(Cluster clusters[], int numClusters);
void printClusters(Cluster clusters[], int numClusters);

int main() {
    int numPoints, numClusters, iterations, i, j;
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];
    
    // Input the number of points and number of clusters
    printf("Enter the number of points (max %d): ", MAX_POINTS);
    scanf("%d", &numPoints);
    
    if (numPoints > MAX_POINTS) {
        printf("Exceeded maximum points limit.\n");
        return 1;
    }
    
    printf("Enter the number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &numClusters);
    
    if (numClusters > MAX_CLUSTERS || numClusters > numPoints) {
        printf("Invalid number of clusters.\n");
        return 1;
    }
    
    // Generate random points
    for (i = 0; i < numPoints; i++) {
        points[i].x = (double)(rand() % 100); // Random X coordinates
        points[i].y = (double)(rand() % 100); // Random Y coordinates
    }
    
    // Initialize clusters
    for (i = 0; i < numClusters; i++) {
        clusters[i].centroid = points[rand() % numPoints]; // Randomly select initial centroids
        clusters[i].size = 0;
    }
    
    // K-Means algorithm
    printf("K-Means clustering...\n");
    for (iterations = 0; iterations < 10; iterations++) {
        // Reset cluster points count for new assignment
        for (i = 0; i < numClusters; i++) {
            clusters[i].size = 0;
        }
        
        // Step 1: Assign points to the nearest cluster
        assignPointsToClusters(clusters, numClusters, points, numPoints);
        
        // Step 2: Update centroids
        updateCentroids(clusters, numClusters);
    }
    
    // Print final clusters
    printClusters(clusters, numClusters);
    
    return 0;
}

// Function to calculate distance
double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Function to assign points to the closest cluster
void assignPointsToClusters(Cluster clusters[], int numClusters, Point points[], int numPoints) {
    int i, j;
    
    for (i = 0; i < numPoints; i++) {
        double minDistance = distance(points[i], clusters[0].centroid);
        int clusterIndex = 0;
        
        for (j = 1; j < numClusters; j++) {
            double dist = distance(points[i], clusters[j].centroid);
            if (dist < minDistance) {
                minDistance = dist;
                clusterIndex = j;
            }
        }
        
        // Add point to the closest cluster
        clusters[clusterIndex].points[clusters[clusterIndex].size++] = points[i];
    }
}

// Function to update centroid of each cluster
void updateCentroids(Cluster clusters[], int numClusters) {
    int i, j;
    
    for (i = 0; i < numClusters; i++) {
        if (clusters[i].size == 0) {
            continue; // No points assigned to this cluster
        }
        
        double sumX = 0.0, sumY = 0.0;
        
        for (j = 0; j < clusters[i].size; j++) {
            sumX += clusters[i].points[j].x;
            sumY += clusters[i].points[j].y;
        }
        
        // Update centroid
        clusters[i].centroid.x = sumX / clusters[i].size;
        clusters[i].centroid.y = sumY / clusters[i].size;
    }
}

// Function to print clusters
void printClusters(Cluster clusters[], int numClusters) {
    int i, j;
    
    for (i = 0; i < numClusters; i++) {
        printf("Cluster %d:\n", i + 1);
        printf(" Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf(" Points:\n");
        
        for (j = 0; j < clusters[i].size; j++) {
            printf("  (%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}