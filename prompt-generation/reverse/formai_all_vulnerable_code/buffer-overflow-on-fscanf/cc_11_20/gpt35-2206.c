//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: scientific
// Unique C Clustering Algorithm Implementation Example Program 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define MAX_ITERATIONS 50
#define MAX_CLUSTERS 10

struct Point {
    float x, y;
};

struct Cluster {
    float x, y;
    float sumX, sumY;
    int count;
};

int main() {
    int i, j, k;

    // initialize points array from input file
    struct Point points[MAX_POINTS];
    FILE *inputFile;
    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }

    int numPoints = 0;
    while (fscanf(inputFile, "%f,%f\n", &points[numPoints].x, &points[numPoints].y) > 0) {
        numPoints++;
    }

    fclose(inputFile);

    // initialize clusters array
    struct Cluster clusters[MAX_CLUSTERS];
    int numClusters = 0;

    // randomly select initial cluster centers
    for (i = 0; i < MAX_CLUSTERS; i++) {
        int randomIndex = rand() % numPoints;
        clusters[i].x = points[randomIndex].x;
        clusters[i].y = points[randomIndex].y;
    }

    // run k-means algorithm
    for (i = 0; i < MAX_ITERATIONS; i++) {
        // assign points to nearest cluster
        for (j = 0; j < numPoints; j++) {
            float minDistance = INFINITY;
            int minCluster = -1;

            for (k = 0; k < numClusters; k++) {
                float distance = sqrt(pow(points[j].x - clusters[k].x, 2) + pow(points[j].y - clusters[k].y, 2));

                if (distance < minDistance) {
                    minDistance = distance;
                    minCluster = k;
                }
            }

            // add point to assigned cluster
            clusters[minCluster].sumX += points[j].x;
            clusters[minCluster].sumY += points[j].y;
            clusters[minCluster].count++;
        }

        // re-calculate cluster centers
        int numEmptyClusters = 0;

        for (j = 0; j < numClusters; j++) {
            if (clusters[j].count > 0) {
                clusters[j].x = clusters[j].sumX / clusters[j].count;
                clusters[j].y = clusters[j].sumY / clusters[j].count;
                clusters[j].sumX = 0;
                clusters[j].sumY = 0;
                clusters[j].count = 0;
            } else {
                numEmptyClusters++;
            }
        }

        // exit if no empty clusters were found
        if (numEmptyClusters == 0) {
            break;
        }

        // randomly select new centers for empty clusters
        for (j = 0; j < numClusters; j++) {
            if (clusters[j].count == 0) {
                int randomIndex = rand() % numPoints;
                clusters[j].x = points[randomIndex].x;
                clusters[j].y = points[randomIndex].y;
            }
        }
    }

    // print final cluster centers
    printf("Final Cluster Centers:\n");

    for (i = 0; i < numClusters; i++) {
        printf("Cluster %d: (%f, %f)\n", i, clusters[i].x, clusters[i].y);
    }

    return 0;
}