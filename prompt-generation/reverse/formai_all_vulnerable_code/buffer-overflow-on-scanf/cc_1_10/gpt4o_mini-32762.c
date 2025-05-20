//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2

typedef struct {
    double coordinates[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    int point_count;
    Point points[MAX_POINTS];
} Cluster;

double calculate_distance(Point a, Point b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += (a.coordinates[i] - b.coordinates[i]) * (a.coordinates[i] - b.coordinates[i]);
    }
    return sqrt(sum);
}

void initialize_clusters(Cluster clusters[], int k, Point points[], int num_points) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[rand() % num_points]; // Randomly select initial centroids
        clusters[i].point_count = 0;
    }
}

void assign_points_to_clusters(Cluster clusters[], int k, Point points[], int num_points) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = DBL_MAX;
        int cluster_index = -1;

        for (int j = 0; j < k; j++) {
            double distance = calculate_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }
        clusters[cluster_index].points[clusters[cluster_index].point_count] = points[i];
        clusters[cluster_index].point_count++;
    }
}

void update_centroids(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i].centroid.coordinates[j] = 0;
        }

        for (int j = 0; j < clusters[i].point_count; j++) {
            for (int d = 0; d < DIMENSIONS; d++) {
                clusters[i].centroid.coordinates[d] += clusters[i].points[j].coordinates[d];
            }
        }

        if (clusters[i].point_count > 0) {
            for (int d = 0; d < DIMENSIONS; d++) {
                clusters[i].centroid.coordinates[d] /= clusters[i].point_count; // Average
            }
        }
        clusters[i].point_count = 0; // Reset for next iteration
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int num_points, k;

    printf("Enter number of points: ");
    scanf("%d", &num_points);
    
    // Validate num_points
    if (num_points > MAX_POINTS || num_points <= 0) {
        printf("Number of points should be between 1 and %d.\n", MAX_POINTS);
        return 1;
    }

    Point points[MAX_POINTS];
    printf("Enter the points (x y): \n");
    for (int i = 0; i < num_points; i++) {
        scanf("%lf %lf", &points[i].coordinates[0], &points[i].coordinates[1]);
    }

    printf("Enter number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &k);
    
    // Validate k
    if (k > MAX_CLUSTERS || k <= 0) {
        printf("Number of clusters should be between 1 and %d.\n", MAX_CLUSTERS);
        return 1;
    }

    Cluster clusters[MAX_CLUSTERS];
    initialize_clusters(clusters, k, points, num_points);

    // K-Means algorithm
    for (int iteration = 0; iteration < 10; iteration++) {
        assign_points_to_clusters(clusters, k, points, num_points);
        update_centroids(clusters, k);
    }

    // Display results
    for (int i = 0; i < k; i++) {
        printf("Cluster %d Centroid: (%.2f, %.2f)\n", i + 1, clusters[i].centroid.coordinates[0], clusters[i].centroid.coordinates[1]);
    }

    return 0;
}