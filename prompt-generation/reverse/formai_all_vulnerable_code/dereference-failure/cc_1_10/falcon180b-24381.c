//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

struct Point {
    int x;
    int y;
};

struct Cluster {
    int id;
    int size;
    struct Point *points;
};

void initCluster(struct Cluster *cluster, int id) {
    cluster->id = id;
    cluster->size = 0;
    cluster->points = (struct Point *) malloc(MAX * sizeof(struct Point));
}

void addPointToCluster(struct Cluster *cluster, int x, int y) {
    cluster->size++;
    struct Point *point = &cluster->points[cluster->size - 1];
    point->x = x;
    point->y = y;
}

void printCluster(struct Cluster *cluster) {
    printf("Cluster %d has %d points:\n", cluster->id, cluster->size);
    for (int i = 0; i < cluster->size; i++) {
        printf("(%d, %d)\n", cluster->points[i].x, cluster->points[i].y);
    }
}

void kMeans(struct Point *points, int numPoints, int numClusters) {
    struct Cluster *clusters = (struct Cluster *) malloc(numClusters * sizeof(struct Cluster));
    for (int i = 0; i < numClusters; i++) {
        initCluster(&clusters[i], i);
    }

    for (int i = 0; i < numPoints; i++) {
        int minDistance = MAX;
        int clusterId = -1;
        for (int j = 0; j < numClusters; j++) {
            int distance = pow(points[i].x - clusters[j].points[0].x, 2) + pow(points[i].y - clusters[j].points[0].y, 2);
            if (distance < minDistance) {
                minDistance = distance;
                clusterId = j;
            }
        }
        addPointToCluster(&clusters[clusterId], points[i].x, points[i].y);
    }

    for (int i = 0; i < numClusters; i++) {
        printCluster(&clusters[i]);
    }
}

int main() {
    struct Point points[] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}};
    int numPoints = sizeof(points) / sizeof(points[0]);
    int numClusters = 3;

    kMeans(points, numPoints, numClusters);

    return 0;
}