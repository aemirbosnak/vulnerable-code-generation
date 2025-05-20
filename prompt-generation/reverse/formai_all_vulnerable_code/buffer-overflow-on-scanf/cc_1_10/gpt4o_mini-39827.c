//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2

typedef struct {
    double coordinates[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_POINTS];
    int count;
} Cluster;

double euclidean_distance(Point a, Point b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += pow(a.coordinates[i] - b.coordinates[i], 2);
    }
    return sqrt(sum);
}

void initialize_clusters(Cluster clusters[], int k, Point points[], int num_points) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[i % num_points]; // Assign first k points as centroids
        clusters[i].count = 0;
    }
}

void assign_points_to_clusters(Cluster clusters[], int k, Point points[], int num_points) {
    for (int i = 0; i < k; i++) {
        clusters[i].count = 0; // Reset count before assigning new points
    }

    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster = 0;

        for (int j = 0; j < k; j++) {
            double distance = euclidean_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].points[clusters[closest_cluster].count++] = points[i];
    }
}

void update_cluster_centroids(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].count == 0) continue; // Avoid division by zero
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i].centroid.coordinates[j] = 0; // Reset centroid coordinates
        }
        for (int j = 0; j < clusters[i].count; j++) {
            for (int d = 0; d < DIMENSIONS; d++) {
                clusters[i].centroid.coordinates[d] += clusters[i].points[j].coordinates[d];
            }
        }
        for (int d = 0; d < DIMENSIONS; d++) {
            clusters[i].centroid.coordinates[d] /= clusters[i].count; // Average calculation
        }
    }
}

int main() {
    int num_points, k;
    Point points[MAX_POINTS];
    
    printf("Enter the number of points (max %d): ", MAX_POINTS);
    scanf("%d", &num_points);
    
    if (num_points > MAX_POINTS) {
        printf("Number of points exceeds the limit.\n");
        return 1;
    }

    printf("Enter the points (x y):\n");
    for (int i = 0; i < num_points; i++) {
        scanf("%lf %lf", &points[i].coordinates[0], &points[i].coordinates[1]);
    }

    printf("Enter the number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &k);

    if (k > MAX_CLUSTERS) {
        printf("Number of clusters exceeds the limit.\n");
        return 1;
    }

    Cluster clusters[MAX_CLUSTERS];
    initialize_clusters(clusters, k, points, num_points);

    int iterations = 0;
    const int max_iterations = 100;
    while (iterations < max_iterations) {
        assign_points_to_clusters(clusters, k, points, num_points);
        update_cluster_centroids(clusters, k);
        iterations++;
    }

    printf("Cluster centroids after %d iterations:\n", iterations);
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: (%lf, %lf)\n", i + 1, clusters[i].centroid.coordinates[0], clusters[i].centroid.coordinates[1]);
    }

    return 0;
}