//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CLUSTERS 10
#define MAX_POINTS 100

typedef struct {
    int id;
    double x, y;
} Point;

typedef struct {
    int numPoints;
    Point points[MAX_POINTS];
} Cluster;

void initializeClusters(Cluster clusters[], int numClusters) {
    for (int i = 0; i < numClusters; i++) {
        clusters[i].numPoints = 0;
    }
}

int euclideanDistance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void kMeansClustering(Point points[], int numPoints, int numClusters, Cluster clusters[]) {
    int iterations = 0;
    while (iterations < 100) {
        iterations++;

        // Assign each point to the closest cluster
        for (int i = 0; i < numPoints; i++) {
            int bestCluster = -1;
            double bestDistance = INFINITY;

            for (int j = 0; j < numClusters; j++) {
                double distance = euclideanDistance(points[i], clusters[j].points[0]);

                if (distance < bestDistance) {
                    bestDistance = distance;
                    bestCluster = j;
                }
            }

            clusters[bestCluster].points[clusters[bestCluster].numPoints++] = points[i];
        }

        // Update cluster centroids
        for (int j = 0; j < numClusters; j++) {
            if (clusters[j].numPoints > 0) {
                double xSum = 0;
                double ySum = 0;

                for (int k = 0; k < clusters[j].numPoints; k++) {
                    xSum += clusters[j].points[k].x;
                    ySum += clusters[j].points[k].y;
                }

                clusters[j].points[0].x = xSum / clusters[j].numPoints;
                clusters[j].points[0].y = ySum / clusters[j].numPoints;
            }
        }
    }
}

void printClusters(Cluster clusters[], int numClusters) {
    for (int i = 0; i < numClusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].numPoints; j++) {
            printf("(%d, %d)\n", clusters[i].points[j].id, clusters[i].points[j].x);
        }
        printf("\n");
    }
}

int main() {
    Point points[MAX_POINTS];
    int numPoints = 0;

    printf("Enter the number of points:\n");
    scanf("%d", &numPoints);

    printf("Enter the coordinates of each point:\n");

    for (int i = 0; i < numPoints; i++) {
        scanf("%d %lf %lf", &points[i].id, &points[i].x, &points[i].y);
    }

    int numClusters = 3;
    Cluster clusters[MAX_CLUSTERS];

    initializeClusters(clusters, numClusters);
    kMeansClustering(points, numPoints, numClusters, clusters);

    printf("The resulting clusters are:\n");
    printClusters(clusters, numClusters);

    return 0;
}