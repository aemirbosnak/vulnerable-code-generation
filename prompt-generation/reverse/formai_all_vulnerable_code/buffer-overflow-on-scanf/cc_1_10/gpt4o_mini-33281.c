//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2
#define MAX_ITERATIONS 100

typedef struct {
    double coordinates[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_POINTS];
    int point_count;
} Cluster;

double euclidean_distance(Point a, Point b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += pow(a.coordinates[i] - b.coordinates[i], 2);
    }
    return sqrt(sum);
}

void initialize_clusters(Cluster clusters[], Point points[], int k, int n) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[rand() % n];
        clusters[i].point_count = 0;
    }
}

void assign_clusters(Cluster clusters[], Point points[], int k, int n) {
    for (int i = 0; i < n; i++) {
        int min_index = 0;
        double min_distance = euclidean_distance(points[i], clusters[0].centroid);
        for (int j = 1; j < k; j++) {
            double distance = euclidean_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                min_index = j;
            }
        }
        clusters[min_index].points[clusters[min_index].point_count++] = points[i];
    }
}

void update_centroids(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        double sum[DIMENSIONS] = {0.0};
        for (int j = 0; j < clusters[i].point_count; j++) {
            for (int d = 0; d < DIMENSIONS; d++) {
                sum[d] += clusters[i].points[j].coordinates[d];
            }
        }
        for (int d = 0; d < DIMENSIONS; d++) {
            clusters[i].centroid.coordinates[d] = sum[d] / clusters[i].point_count;
        }
        clusters[i].point_count = 0; // Reset for the next iteration
    }
}

void kmeans(Point points[], int n, int k) {
    Cluster clusters[MAX_CLUSTERS];
    initialize_clusters(clusters, points, k, n);

    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        assign_clusters(clusters, points, k, n);
        update_centroids(clusters, k);
    }

    // Print results
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("Centroid: (");
        for (int d = 0; d < DIMENSIONS; d++) {
            printf("%.2f", clusters[i].centroid.coordinates[d]);
            if (d < DIMENSIONS - 1) printf(", ");
        }
        printf(")\nPoints:\n");
        for (int j = 0; j < clusters[i].point_count; j++) {
            printf("  (");
            for (int d = 0; d < DIMENSIONS; d++) {
                printf("%.2f", clusters[i].points[j].coordinates[d]);
                if (d < DIMENSIONS - 1) printf(", ");
            }
            printf(")\n");
        }
    }
}

int main() {
    Point points[MAX_POINTS];
    int n, k;

    // Generate random points
    printf("Enter number of points (max %d): ", MAX_POINTS);
    scanf("%d", &n);
    if (n > MAX_POINTS) n = MAX_POINTS;

    printf("Enter number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &k);
    if (k > MAX_CLUSTERS) k = MAX_CLUSTERS;

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        points[i].coordinates[0] = rand() % 100; // x coordinate
        points[i].coordinates[1] = rand() % 100; // y coordinate
    }

    // Perform K-means clustering
    kmeans(points, n, k);

    return 0;
}