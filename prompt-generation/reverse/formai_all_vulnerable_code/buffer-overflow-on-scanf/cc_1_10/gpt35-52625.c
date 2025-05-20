//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX 100
#define INF 99999999

typedef struct Point {
    double x, y;
} Point;

Point points[MAX] = {0};

// Distance between two points
double distance(Point a, Point b) {
    double xDiff = a.x - b.x;
    double yDiff = a.y - b.y;
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}

// Find the index of the point with the smallest distance to a cluster
int findClosestToCluster(Point cluster[], Point p, int k) {
    double minDist = INF;
    int minIndex = -1;
    for (int i = 0; i < k; i++) {
        double dist = distance(cluster[i], p);
        if (dist < minDist) {
            minDist = dist;
            minIndex = i;
        }
    }
    return minIndex;
}

// Calculate the new cluster positions
void updateClusters(Point clusters[], int size[], Point points[], int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].x = 0;
        clusters[i].y = 0;
        for (int j = 0; j < size[i]; j++) {
            clusters[i].x += points[j + i * MAX].x;
            clusters[i].y += points[j + i * MAX].y;
        }
        clusters[i].x /= (double)size[i];
        clusters[i].y /= (double)size[i];
    }
}

// K-means clustering algorithm
void kMeansClustering(Point points[], int n, int k) {
    Point clusters[k];
    int size[k];
    for (int i = 0; i < k; i++) {
        clusters[i].x = rand() % n;
        clusters[i].y = rand() % n;
        size[i] = 0;
    }

    bool changed = true;
    while (changed) {
        for (int i = 0; i < k; i++) {
            size[i] = 0;
        }

        changed = false;
        for (int i = 0; i < n; i++) {
            int clusterIndex = findClosestToCluster(clusters, points[i], k);
            if (clusterIndex != points[i].x) {
                changed = true;
                points[i].x = clusterIndex;
            }
            size[clusterIndex]++;
        }
        updateClusters(clusters, size, points, k);
    }

    // Print results
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: (%.2f, %.2f)\n", i + 1, clusters[i].x, clusters[i].y);
        for (int j = 0; j < n; j++) {
            if (points[j].x == i) {
                printf("    (%.2f, %.2f)\n", points[j].x, points[j].y);
            }
        }
    }
}

int main() {
    printf("Enter the number of points: ");
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter point %d (x y): ", i + 1);
        Point p;
        scanf("%lf %lf", &p.x, &p.y);
        points[i] = p;
    }

    printf("Enter the number of clusters: ");
    int k;
    scanf("%d", &k);
    kMeansClustering(points, n, k);

    return 0;
}