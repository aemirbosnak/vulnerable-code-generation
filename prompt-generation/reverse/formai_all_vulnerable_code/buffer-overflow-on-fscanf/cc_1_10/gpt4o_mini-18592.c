//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define MAX_ITERATIONS 100
#define DIMENSIONS 2

typedef struct {
    double coordinates[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    int num_points;
    Point points[MAX_POINTS];
} Cluster;

double distance(Point a, Point b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += (a.coordinates[i] - b.coordinates[i]) * (a.coordinates[i] - b.coordinates[i]);
    }
    return sqrt(sum);
}

void assign_points_to_clusters(Point points[], int num_points, Cluster clusters[], int num_clusters) {
    for (int i = 0; i < num_points; i++) {
        double min_dist = INFINITY;
        int closest_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            double dist = distance(points[i], clusters[j].centroid);
            if (dist < min_dist) {
                min_dist = dist;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].points[clusters[closest_cluster].num_points++] = points[i];
    }
}

void update_centroids(Cluster clusters[], int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        if (clusters[i].num_points > 0) {
            for (int j = 0; j < DIMENSIONS; j++) {
                clusters[i].centroid.coordinates[j] = 0.0;
            }

            for (int j = 0; j < clusters[i].num_points; j++) {
                for (int k = 0; k < DIMENSIONS; k++) {
                    clusters[i].centroid.coordinates[k] += clusters[i].points[j].coordinates[k];
                }
            }
            for (int j = 0; j < DIMENSIONS; j++) {
                clusters[i].centroid.coordinates[j] /= clusters[i].num_points;
            }
        }
    }
}

int main() {
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];
    int num_points = 0;
    int num_clusters = 3;  // Set number of clusters

    // Initialize clusters randomly (for simplicity)
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].num_points = 0;
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i].centroid.coordinates[j] = (rand() % 100) / 10.0;  // Random coordinates
        }
    }

    // Read points from a file
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, "%lf %lf", &points[num_points].coordinates[0], &points[num_points].coordinates[1]) != EOF) {
        num_points++;
    }
    fclose(file);

    // K-means Algorithm
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        // Reset clusters
        for (int i = 0; i < num_clusters; i++) {
            clusters[i].num_points = 0;
        }

        // Assign points to clusters
        assign_points_to_clusters(points, num_points, clusters, num_clusters);
        
        // Update centroids
        update_centroids(clusters, num_clusters);
        
        // Printing the clusters for each iteration
        printf("Iteration %d:\n", iteration + 1);
        for (int i = 0; i < num_clusters; i++) {
            printf("Cluster %d: Count = %d, Centroid = (%f, %f)\n", 
                   i, clusters[i].num_points,
                   clusters[i].centroid.coordinates[0],
                   clusters[i].centroid.coordinates[1]);
        }
        printf("\n");
    }

    return 0;
}