//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define MAX_POINTS 100
#define DIMENSIONS 2
#define MAX_ITERATIONS 100
#define EPSILON 0.0001

typedef struct {
    double coordinates[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    int count;
    Point points[MAX_POINTS];
} Cluster;

void readData(const char* filename, Point* points, int* numPoints) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    *numPoints = 0;
    while (fscanf(file, "%lf %lf", &points[*numPoints].coordinates[0], 
                    &points[*numPoints].coordinates[1]) == 2) {
        (*numPoints)++;
    }
    fclose(file);
}

double euclideanDistance(Point* p1, Point* p2) {
    return sqrt(pow(p1->coordinates[0] - p2->coordinates[0], 2) +
                pow(p1->coordinates[1] - p2->coordinates[1], 2));
}

void initializeClusters(Cluster* clusters, int k, Point* points, int numPoints) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[rand() % numPoints];
        clusters[i].count = 0;
    }
}

void assignPointsToClusters(Cluster* clusters, int k, Point* points, int numPoints) {
    for (int i = 0; i < numPoints; i++) {
        int clusterIndex = 0;
        double minDistance = DBL_MAX;
        for (int j = 0; j < k; j++) {
            double distance = euclideanDistance(&points[i], &clusters[j].centroid);
            if (distance < minDistance) {
                minDistance = distance;
                clusterIndex = j;
            }
        }
        clusters[clusterIndex].points[clusters[clusterIndex].count++] = points[i];
    }
}

void updateCentroids(Cluster* clusters, int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].count == 0) continue; // Avoid division by zero
        double sumX = 0.0, sumY = 0.0;
        for (int j = 0; j < clusters[i].count; j++) {
            sumX += clusters[i].points[j].coordinates[0];
            sumY += clusters[i].points[j].coordinates[1];
        }
        clusters[i].centroid.coordinates[0] = sumX / clusters[i].count;
        clusters[i].centroid.coordinates[1] = sumY / clusters[i].count;
    }
}

int checkConvergence(Cluster* clusters, Cluster* prevClusters, int k) {
    for (int i = 0; i < k; i++) {
        if (euclideanDistance(&clusters[i].centroid, &prevClusters[i].centroid) > EPSILON) {
            return 0; // Not converged
        }
    }
    return 1; // Converged
}

void kMeans(Point* points, int numPoints, int k) {
    Cluster clusters[k];
    Cluster prevClusters[k];

    initializeClusters(clusters, k, points, numPoints);

    for (int iter = 0; iter < MAX_ITERATIONS; iter++) {
        // Save previous clusters
        for (int i = 0; i < k; i++) {
            prevClusters[i] = clusters[i];
            clusters[i].count = 0; // Reset count for new assignment
        }

        assignPointsToClusters(clusters, k, points, numPoints);
        updateCentroids(clusters, k);

        if (checkConvergence(clusters, prevClusters, k)) {
            printf("Converged after %d iterations\n", iter + 1);
            break;
        }
    }
    
    for (int i = 0; i < k; i++) {
        printf("Cluster %d Centroid: (%.2f, %.2f)\n", i + 1,
               clusters[i].centroid.coordinates[0],
               clusters[i].centroid.coordinates[1]);
        printf("Points:\n");
        for (int j = 0; j < clusters[i].count; j++) {
            printf("  (%.2f, %.2f)\n", clusters[i].points[j].coordinates[0],
                   clusters[i].points[j].coordinates[1]);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <datafile> <k>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Point points[MAX_POINTS];
    int numPoints;
    int k = atoi(argv[2]);

    srand(time(NULL));
    readData(argv[1], points, &numPoints);
    kMeans(points, numPoints, k);

    return 0;
}