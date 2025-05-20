//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 500
#define MAX_ITERATIONS 1000
#define MAX_CLUSTERS 5

struct Point {
    float x, y;
    int cluster;
};

struct Cluster {
    float centroidX, centroidY;
    int size;
};

int main() {
    struct Point points[MAX_POINTS];
    struct Cluster clusters[MAX_CLUSTERS];

    int numPoints, numClusters, numIterations = 0;
    float minX = INFINITY, maxX = -INFINITY, minY = INFINITY, maxY = -INFINITY;

    // get input from user
    printf("Enter the number of points: ");
    scanf("%d", &numPoints);

    printf("Enter the number of clusters: ");
    scanf("%d", &numClusters);

    // get points from user
    for (int i = 0; i < numPoints; i++) {
        printf("Enter the x and y coordinates of point %d: ", i+1);
        scanf("%f %f", &points[i].x, &points[i].y);

        // update min and max values for later use in initialization of clusters
        if (points[i].x < minX) minX = points[i].x;
        if (points[i].x > maxX) maxX = points[i].x;
        if (points[i].y < minY) minY = points[i].y;
        if (points[i].y > maxY) maxY = points[i].y;

        points[i].cluster = -1; // mark as unassigned initially
    }

    // initialize clusters randomly within range of points
    for (int i = 0; i < numClusters; i++) {
        clusters[i].centroidX = ((float)rand() / RAND_MAX) * (maxX - minX) + minX;
        clusters[i].centroidY = ((float)rand() / RAND_MAX) * (maxY - minY) + minY;
        clusters[i].size = 0;
    }

    // perform clustering
    int changed = 1;
    while (changed && numIterations < MAX_ITERATIONS) {
        changed = 0;
        numIterations++;

        // assign each point to nearest cluster
        for (int i = 0; i < numPoints; i++) {
            float minDistance = INFINITY;
            int nearestCluster = -1;

            for (int j = 0; j < numClusters; j++) {
                float distance = sqrt(pow(points[i].x - clusters[j].centroidX, 2) + pow(points[i].y - clusters[j].centroidY, 2));
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestCluster = j;
                }
            }

            if (points[i].cluster != nearestCluster) {
                points[i].cluster = nearestCluster;
                changed = 1;
            }
        }

        // recalculate centroid of each cluster
        for (int i = 0; i < numClusters; i++) {
            float sumX = 0, sumY = 0;
            int size = 0;

            for (int j = 0; j < numPoints; j++) {
                if (points[j].cluster == i) {
                    sumX += points[j].x;
                    sumY += points[j].y;
                    size++;
                }
            }

            if (size > 0) {
                clusters[i].centroidX = sumX / size;
                clusters[i].centroidY = sumY / size;
                clusters[i].size = size;
            }
        }
    }

    // print results
    printf("Final clustering:\n");
    for (int i = 0; i < numClusters; i++) {
        printf("Cluster %d:\n", i+1);
        printf("Centroid: (%.2f, %.2f)\n", clusters[i].centroidX, clusters[i].centroidY);
        printf("Size: %d\n", clusters[i].size);

        printf("Points: [");
        for (int j = 0; j < numPoints; j++) {
            if (points[j].cluster == i) {
                printf("(%d, %.2f, %.2f) ", j+1, points[j].x, points[j].y);
            }
        }
        printf("]\n");
    }

    // done
    return 0;
}