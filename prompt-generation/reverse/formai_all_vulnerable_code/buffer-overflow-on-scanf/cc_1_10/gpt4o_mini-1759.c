//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2
#define MAX_ITERATIONS 100
#define THRESHOLD 0.001

typedef struct {
    double coords[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_POINTS];
    int count;
} Cluster;

double euclideanDistance(Point* a, Point* b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; ++i) {
        sum += (a->coords[i] - b->coords[i]) * (a->coords[i] - b->coords[i]);
    }
    return sqrt(sum);
}

void assignPointsToClusters(Point* points, Cluster* clusters, int numPoints, int k) {
    for (int i = 0; i < numPoints; ++i) {
        double minDist = INFINITY;
        int clusterIndex = -1;
        for (int j = 0; j < k; ++j) {
            double dist = euclideanDistance(&points[i], &clusters[j].centroid);
            if (dist < minDist) {
                minDist = dist;
                clusterIndex = j;
            }
        }
        clusters[clusterIndex].points[clusters[clusterIndex].count++] = points[i];
    }
}

void updateCentroids(Cluster* clusters, int k) {
    for (int i = 0; i < k; ++i) {
        if (clusters[i].count == 0) continue;
        for (int d = 0; d < DIMENSIONS; ++d) {
            double sum = 0.0;
            for (int p = 0; p < clusters[i].count; ++p) {
                sum += clusters[i].points[p].coords[d];
            }
            clusters[i].centroid.coords[d] = sum / clusters[i].count;
        }
    }
}

int centroidsConverged(Cluster* clusters, Cluster* oldClusters, int k) {
    for (int i = 0; i < k; ++i) {
        if (euclideanDistance(&clusters[i].centroid, &oldClusters[i].centroid) > THRESHOLD) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int k, numPoints;
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];

    printf("Enter number of points (max %d): ", MAX_POINTS);
    scanf("%d", &numPoints);

    if (numPoints > MAX_POINTS || numPoints <= 0) {
        printf("Invalid number of points.\n");
        return 1;
    }

    printf("Enter the points (x y format):\n");
    for (int i = 0; i < numPoints; i++) {
        scanf("%lf %lf", &points[i].coords[0], &points[i].coords[1]);
    }

    printf("Enter number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &k);

    if (k > MAX_CLUSTERS || k <= 0) {
        printf("Invalid number of clusters.\n");
        return 1;
    }

    // Randomly initialize cluster centroids
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[rand() % numPoints];
        clusters[i].count = 0;
    }

    int iterations = 0;
    while (iterations < MAX_ITERATIONS) {
        // Save old centroids for convergence check
        Cluster oldClusters[MAX_CLUSTERS];
        for (int i = 0; i < k; i++) {
            oldClusters[i] = clusters[i];
            clusters[i].count = 0; // Reset points count for next assignment
        }

        assignPointsToClusters(points, clusters, numPoints, k);
        updateCentroids(clusters, k);

        if (centroidsConverged(clusters, oldClusters, k)) {
            printf("Centroids have converged after %d iterations.\n", iterations);
            break;
        }

        iterations++;
    }

    printf("Final centroids:\n");
    for (int i = 0; i < k; i++) {
        printf("Cluster %d centroid: (%.2f, %.2f)\n", i + 1, clusters[i].centroid.coords[0], clusters[i].centroid.coords[1]);
    }

    printf("Point assignments:\n");
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        for (int j = 0; j < clusters[i].count; j++) {
            printf("Point: (%.2f, %.2f)\n", clusters[i].points[j].coords[0], clusters[i].points[j].coords[1]);
        }
    }

    return 0;
}