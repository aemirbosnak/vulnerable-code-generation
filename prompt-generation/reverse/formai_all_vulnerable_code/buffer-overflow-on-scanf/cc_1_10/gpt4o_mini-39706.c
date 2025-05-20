//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define DIMENSIONS 2
#define MAX_ITER 100

typedef struct {
    double coordinates[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_POINTS];
    int count;
} Cluster;

double distance(Point a, Point b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += pow(a.coordinates[i] - b.coordinates[i], 2);
    }
    return sqrt(sum);
}

void initialize_clusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid.coordinates[0] = rand() % 100; // Random x
        clusters[i].centroid.coordinates[1] = rand() % 100; // Random y
        clusters[i].count = 0;
    }
}

void assign_points_to_clusters(Point points[], Cluster clusters[], int n, int k) {
    for (int i = 0; i < n; i++) {
        double min_dist = INFINITY;
        int cluster_index = -1;

        for (int j = 0; j < k; j++) {
            double dist = distance(points[i], clusters[j].centroid);
            if (dist < min_dist) {
                min_dist = dist;
                cluster_index = j;
            }
        }
        clusters[cluster_index].points[clusters[cluster_index].count++] = points[i];
    }
}

void calculate_centroids(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].count == 0) continue; // No points in cluster
        for (int j = 0; j < DIMENSIONS; j++) {
            double sum = 0.0;
            for (int m = 0; m < clusters[i].count; m++) {
                sum += clusters[i].points[m].coordinates[j];
            }
            clusters[i].centroid.coordinates[j] = sum / clusters[i].count; // Average
        }
    }
}

void clear_clusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].count = 0;
    }
}

int main() {
    int n, k;

    printf("Enter number of points: ");
    scanf("%d", &n);
    printf("Enter number of clusters: ");
    scanf("%d", &k);

    Point points[n];
    Cluster clusters[k];

    // Generate random points
    for (int i = 0; i < n; i++) {
        points[i].coordinates[0] = rand() % 100; // Random x
        points[i].coordinates[1] = rand() % 100; // Random y
    }

    initialize_clusters(clusters, k);

    for (int iter = 0; iter < MAX_ITER; iter++) {
        assign_points_to_clusters(points, clusters, n, k);
        calculate_centroids(clusters, k);
        
        // Uncomment for debugging
        // printf("Iteration %d:\n", iter + 1);
        // for (int j = 0; j < k; j++) {
        //     printf("Cluster %d centroid: (%.2f, %.2f)\n", j, 
        //            clusters[j].centroid.coordinates[0],
        //            clusters[j].centroid.coordinates[1]);
        // }
        
        clear_clusters(clusters, k);
    }

    // Print final clusters
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: Centroid (%.2f, %.2f) contains:\n", 
               i, clusters[i].centroid.coordinates[0], 
               clusters[i].centroid.coordinates[1]);
        for (int j = 0; j < clusters[i].count; j++) {
            printf("    Point (%.2f, %.2f)\n", 
                   clusters[i].points[j].coordinates[0], 
                   clusters[i].points[j].coordinates[1]);
        }
    }

    return 0;
}