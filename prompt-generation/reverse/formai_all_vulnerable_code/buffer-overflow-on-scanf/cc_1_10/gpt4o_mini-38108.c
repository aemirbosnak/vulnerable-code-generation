//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2
#define MAX_ITERATIONS 100
#define THRESHOLD 0.001

typedef struct {
    double coordinates[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    int size;
    Point points[MAX_POINTS];
} Cluster;

void initClusters(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].size = 0;
    }
}

double euclideanDistance(Point *a, Point *b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += pow(a->coordinates[i] - b->coordinates[i], 2);
    }
    return sqrt(sum);
}

void computeCentroid(Cluster *cluster) {
    for (int i = 0; i < DIMENSIONS; i++) {
        cluster->centroid.coordinates[i] = 0;
    }

    for (int i = 0; i < cluster->size; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            cluster->centroid.coordinates[j] += cluster->points[i].coordinates[j];
        }
    }

    for (int i = 0; i < DIMENSIONS; i++) {
        cluster->centroid.coordinates[i] /= cluster->size;
    }
}

int assignCluster(Point *point, Cluster *clusters, int k) {
    double minDist = INFINITY;
    int bestCluster = 0;
    
    for (int i = 0; i < k; i++) {
        double dist = euclideanDistance(point, &clusters[i].centroid);
        if (dist < minDist) {
            minDist = dist;
            bestCluster = i;
        }
    }

    return bestCluster;
}

void kMeans(Point *points, int numPoints, int k) {
    Cluster clusters[MAX_CLUSTERS];
    initClusters(clusters, k);
    
    // Random initial centroids
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[rand() % numPoints];
    }

    for (int iter = 0; iter < MAX_ITERATIONS; iter++) {
        // Clear clusters
        for (int i = 0; i < k; i++) {
            clusters[i].size = 0;
        }

        // Assign points to the nearest cluster
        for (int i = 0; i < numPoints; i++) {
            int clusterIndex = assignCluster(&points[i], clusters, k);
            clusters[clusterIndex].points[clusters[clusterIndex].size] = points[i];
            clusters[clusterIndex].size++;
        }

        // Compute new centroids
        for (int i = 0; i < k; i++) {
            if (clusters[i].size > 0) {
                Point oldCentroid = clusters[i].centroid;
                computeCentroid(&clusters[i]);
                if (euclideanDistance(&oldCentroid, &clusters[i].centroid) < THRESHOLD) {
                    printf("Converged in %d iterations.\n", iter + 1);
                    return;
                }
            }
        }
    }
    
    printf("Reached maximum iterations.\n");
}

void printClusters(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        printf(" Centroid: (");
        for (int j = 0; j < DIMENSIONS; j++) {
            printf("%f", clusters[i].centroid.coordinates[j]);
            if (j < DIMENSIONS - 1) printf(", ");
        }
        printf(")\n");

        printf(" Points:\n");
        for (int j = 0; j < clusters[i].size; j++) {
            printf("  (");
            for (int d = 0; d < DIMENSIONS; d++) {
                printf("%f", clusters[i].points[j].coordinates[d]);
                if (d < DIMENSIONS - 1) printf(", ");
            }
            printf(")\n");
        }
    }
}

int main() {
    srand(42); // For reproducibility
    Point points[MAX_POINTS];
    int numPoints;

    printf("Enter number of points (max %d): ", MAX_POINTS);
    scanf("%d", &numPoints);
    if (numPoints > MAX_POINTS) {
        printf("Too many points!\n");
        return 1;
    }

    printf("Enter the points (format: x y):\n");
    for (int i = 0; i < numPoints; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            scanf("%lf", &points[i].coordinates[j]);
        }
    }

    int k;
    printf("Enter number of clusters: ");
    scanf("%d", &k);
    if (k > MAX_CLUSTERS || k <= 0) {
        printf("Invalid number of clusters!\n");
        return 1;
    }

    kMeans(points, numPoints, k);
    Cluster clusters[MAX_CLUSTERS];
    initClusters(clusters, k);
    // After kMeans execution, please make sure to populate and print clusters.

    printClusters(clusters, k);

    return 0;
}