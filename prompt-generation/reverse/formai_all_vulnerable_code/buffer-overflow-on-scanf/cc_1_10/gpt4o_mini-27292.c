//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIMENSIONS 2
#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define MAX_ITERATIONS 100
#define THRESHOLD 0.01

typedef struct {
    double coordinates[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    int count;
} Cluster;

double euclidean_distance(Point a, Point b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += (a.coordinates[i] - b.coordinates[i]) * (a.coordinates[i] - b.coordinates[i]);
    }
    return sqrt(sum);
}

void initialize_clusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i].centroid.coordinates[j] = rand() % 100; // Random initialization
        }
        clusters[i].count = 0;
    }
}

void assign_points_to_clusters(Point points[], int num_points, Cluster clusters[], int k) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = euclidean_distance(points[i], clusters[0].centroid);
        int cluster_index = 0;
        for (int j = 1; j < k; j++) {
            double distance = euclidean_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }
        clusters[cluster_index].count++;
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[cluster_index].centroid.coordinates[j] += points[i].coordinates[j];
        }
    }
}

void update_cluster_centroids(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].count > 0) {
            for (int j = 0; j < DIMENSIONS; j++) {
                clusters[i].centroid.coordinates[j] /= clusters[i].count;
            }
        }
        clusters[i].count = 0; // Reset count for next iteration
    }
}

int kmeans(Point points[], int num_points, Cluster clusters[], int k) {
    initialize_clusters(clusters, k);
    int iterations = 0;
    double prev_centroids[MAX_CLUSTERS][DIMENSIONS];

    while (iterations < MAX_ITERATIONS) {
        // Store previous centroids
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < DIMENSIONS; j++) {
                prev_centroids[i][j] = clusters[i].centroid.coordinates[j];
            }
        }

        assign_points_to_clusters(points, num_points, clusters, k);
        update_cluster_centroids(clusters, k);
        
        // Check for convergence
        int converged = 1;
        for (int i = 0; i < k; i++) {
            if (euclidean_distance(clusters[i].centroid, (Point){.coordinates = {prev_centroids[i][0], prev_centroids[i][1]}}) > THRESHOLD) {
                converged = 0;
                break;
            }
        }

        if (converged) {
            break;
        }

        iterations++;
    }
    return iterations;
}

void print_clusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d Centroid: (", i);
        for (int j = 0; j < DIMENSIONS; j++) {
            printf("%lf", clusters[i].centroid.coordinates[j]);
            if (j < DIMENSIONS - 1) printf(", ");
        }
        printf(")\n");
    }
}

int main() {
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];
    int num_points, k;

    printf("Enter the number of points: ");
    scanf("%d", &num_points);
    
    if (num_points > MAX_POINTS) {
        printf("Exceeded maximum number of points (%d).\n", MAX_POINTS);
        return -1;
    }

    for (int i = 0; i < num_points; i++) {
        printf("Enter coordinates of point %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].coordinates[0], &points[i].coordinates[1]);
    }

    printf("Enter the number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &k);
    
    if (k > MAX_CLUSTERS) {
        printf("Exceeded maximum number of clusters (%d).\n", MAX_CLUSTERS);
        return -1;
    }

    int iterations = kmeans(points, num_points, clusters, k);
    printf("K-means clustering completed in %d iterations.\n", iterations);
    print_clusters(clusters, k);

    return 0;
}