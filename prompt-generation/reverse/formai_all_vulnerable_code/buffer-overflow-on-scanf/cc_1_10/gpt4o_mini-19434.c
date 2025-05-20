//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_POINTS];
    int num_points;
} Cluster;

double euclidean_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void initialize_clusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid.x = (rand() % 100) / 10.0; // Random x in range [0, 10]
        clusters[i].centroid.y = (rand() % 100) / 10.0; // Random y in range [0, 10]
        clusters[i].num_points = 0; 
    }
}

void assign_points_to_clusters(Point points[], int num_points, Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].num_points = 0;  // Reset point count for each cluster
    }

    for (int i = 0; i < num_points; i++) {
        double min_distance = DBL_MAX;
        int cluster_index = 0;
        for (int j = 0; j < k; j++) {
            double distance = euclidean_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }
        clusters[cluster_index].points[clusters[cluster_index].num_points++] = points[i];
    }
}

void update_centroids(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        double sum_x = 0.0, sum_y = 0.0;
        for (int j = 0; j < clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        if (clusters[i].num_points > 0) {
            clusters[i].centroid.x = sum_x / clusters[i].num_points;
            clusters[i].centroid.y = sum_y / clusters[i].num_points;
        }
    }
}

int has_converged(Cluster old_clusters[], Cluster new_clusters[], int k) {
    for (int i = 0; i < k; i++) {
        if (old_clusters[i].centroid.x != new_clusters[i].centroid.x || 
            old_clusters[i].centroid.y != new_clusters[i].centroid.y) {
            return 0; // Not converged
        }
    }
    return 1; // Converged
}

void kmeans(Point points[], int num_points, int k) {
    Cluster clusters[MAX_CLUSTERS];
    initialize_clusters(clusters, k);

    Cluster previous_clusters[MAX_CLUSTERS];
    do {
        for (int i = 0; i < k; i++) {
            previous_clusters[i] = clusters[i]; // Store old centroids
        }

        assign_points_to_clusters(points, num_points, clusters, k);
        update_centroids(clusters, k);

    } while (!has_converged(previous_clusters, clusters, k));

    // Print final clusters
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: Centroid(%.2f, %.2f), Points:", i + 1, clusters[i].centroid.x, clusters[i].centroid.y);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf(" (%.2f, %.2f)", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Point points[MAX_POINTS];
    int num_points;

    printf("Enter the number of points (max %d): ", MAX_POINTS);
    scanf("%d", &num_points);
    if (num_points > MAX_POINTS) {
        printf("Error: Number of points exceeds maximum allowed.\n");
        return 1;
    }

    for (int i = 0; i < num_points; i++) {
        points[i].x = (rand() % 100) / 10.0; // Random x in range [0, 10]
        points[i].y = (rand() % 100) / 10.0; // Random y in range [0, 10]
    }

    int k;
    printf("Enter the number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &k);
    if (k > MAX_CLUSTERS || k <= 0) {
        printf("Error: Invalid number of clusters.\n");
        return 1;
    }

    kmeans(points, num_points, k);
    return 0;
}