//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define MAX_POINTS 1000
#define MAX_CLUSTERS 10
#define DIMENSIONS 2

typedef struct {
    double coordinates[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_POINTS];
    int num_points;
} Cluster;

Cluster clusters[MAX_CLUSTERS];
int num_clusters;

double distance(Point a, Point b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += pow(a.coordinates[i] - b.coordinates[i], 2);
    }
    return sqrt(sum);
}

void initialize_clusters(Point* data, int num_points) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid = data[i];  // Initialize centroid with first `K` points
        clusters[i].num_points = 0;
    }
}

void assign_points_to_clusters(Point* data, int num_points) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].num_points = 0; // Reset the number of points for this cluster
    }
    
    for (int i = 0; i < num_points; i++) {
        double min_distance = DBL_MAX;
        int cluster_index = 0;

        for (int j = 0; j < num_clusters; j++) {
            double dist = distance(data[i], clusters[j].centroid);
            if (dist < min_distance) {
                min_distance = dist;
                cluster_index = j;
            }
        }

        clusters[cluster_index].points[clusters[cluster_index].num_points++] = data[i];
    }
}

void calculate_new_centroids() {
    for (int i = 0; i < num_clusters; i++) {
        if (clusters[i].num_points == 0) continue; // Avoid division by zero
        
        for (int j = 0; j < DIMENSIONS; j++) {
            double sum = 0.0;
            for (int k = 0; k < clusters[i].num_points; k++) {
                sum += clusters[i].points[k].coordinates[j];
            }
            clusters[i].centroid.coordinates[j] = sum / clusters[i].num_points; // Update centroid
        }
    }
}

int is_converged(Cluster* previous_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            if (clusters[i].centroid.coordinates[j] != previous_clusters[i].centroid.coordinates[j]) {
                return 0; // Not converged
            }
        }
    }
    return 1; // Converged
}

void kmeans(Point* data, int num_points, int k, int max_iterations) {
    num_clusters = k;
    initialize_clusters(data, num_points);
    
    Cluster previous_clusters[MAX_CLUSTERS];
    
    for (int iter = 0; iter < max_iterations; iter++) {
        // Store previous clusters
        for (int i = 0; i < num_clusters; i++) {
            previous_clusters[i] = clusters[i];
        }

        assign_points_to_clusters(data, num_points);
        calculate_new_centroids();

        if (is_converged(previous_clusters)) {
            break; // Exit if converged
        }
    }
}

void print_clusters() {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d: Centroid(%.2f, %.2f)\n", i, clusters[i].centroid.coordinates[0], clusters[i].centroid.coordinates[1]);
        printf("Points:\n");
        
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("\t(%.2f, %.2f)\n", clusters[i].points[j].coordinates[0], clusters[i].points[j].coordinates[1]);
        }
        printf("\n");
    }
}

int main() {
    int num_points, k;

    printf("Enter the number of data points: ");
    scanf("%d", &num_points);
    
    if (num_points > MAX_POINTS) {
        printf("Exceeds maximum number of points (%d)\n", MAX_POINTS);
        return 1;
    }

    Point data[MAX_POINTS];
    
    printf("Enter the data points (x y):\n");
    for (int i = 0; i < num_points; i++) {
        scanf("%lf %lf", &data[i].coordinates[0], &data[i].coordinates[1]);
    }

    printf("Enter the number of clusters (k): ");
    scanf("%d", &k);
    
    if (k > MAX_CLUSTERS) {
        printf("Exceeds maximum number of clusters (%d)\n", MAX_CLUSTERS);
        return 1;
    }

    kmeans(data, num_points, k, 100);
    print_clusters();

    return 0;
}