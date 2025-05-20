//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define DIMENSIONS 3

/*
 * Define the point structure
 */
typedef struct {
    double x;
    double y;
    double z;
} Point;

/*
 * Define the cluster structure
 */
typedef struct {
    Point center;
    int count;
} Cluster;

/*
 * Define the function to calculate the distance between two points
 */
double calculateDistance(Point p1, Point p2) {
    double distance = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        distance += pow((p1.x - p2.x), 2);
    }
    return sqrt(distance);
}

/*
 * Define the function to initialize the clusters
 */
void initializeClusters(Cluster clusters[], Point points[], int numPoints) {
    for (int i = 0; i < numPoints; i++) {
        clusters[i].center = points[i];
        clusters[i].count = 1;
    }
}

/*
 * Define the function to find the closest cluster to a given point
 */
int findClosestCluster(Cluster clusters[], int numClusters, Point point) {
    int closestCluster = 0;
    double minDistance = calculateDistance(clusters[0].center, point);

    for (int i = 1; i < numClusters; i++) {
        double distance = calculateDistance(clusters[i].center, point);
        if (distance < minDistance) {
            minDistance = distance;
            closestCluster = i;
        }
    }

    return closestCluster;
}

/*
 * Define the function to merge two clusters
 */
void mergeClusters(Cluster clusters[], int numClusters, int cluster1, int cluster2) {
    for (int i = 0; i < DIMENSIONS; i++) {
        clusters[cluster1].center.x += clusters[cluster2].center.x;
    }
    clusters[cluster1].count += clusters[cluster2].count;
    clusters[cluster2].count = 0;
}

/*
 * Define the function to run the k-means algorithm
 */
void kMeans(Point points[], int numPoints, int numClusters, int maxIterations) {
    Cluster clusters[numClusters];
    initializeClusters(clusters, points, numPoints);

    int numIterations = 0;
    while (numIterations < maxIterations) {
        int numPointsChanged = 0;

        for (int i = 0; i < numPoints; i++) {
            int closestCluster = findClosestCluster(clusters, numClusters, points[i]);

            if (closestCluster!= i) {
                mergeClusters(clusters, numClusters, i, closestCluster);
                points[i] = clusters[closestCluster].center;
                numPointsChanged++;
            }
        }

        if (numPointsChanged == 0) {
            break;
        }

        numIterations++;
    }
}

/*
 * Define the main function
 */
int main() {
    Point points[MAX_POINTS];
    int numPoints = 0;

    FILE *fp = fopen("points.txt", "r");
    if (!fp) {
        printf("Error: Could not open points file.\n");
        return 1;
    }

    while (fscanf(fp, "%lf %lf %lf", &points[numPoints].x, &points[numPoints].y, &points[numPoints].z)!= EOF) {
        numPoints++;
    }

    fclose(fp);

    int numClusters = 3;
    int maxIterations = 100;

    kMeans(points, numPoints, numClusters, maxIterations);

    return 0;
}