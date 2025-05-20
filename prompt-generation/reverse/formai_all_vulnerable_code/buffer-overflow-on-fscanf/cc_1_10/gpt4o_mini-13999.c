//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point center;
    Point points[MAX_POINTS];
    int count;
} Cluster;

double euclidean_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void initialize_clusters(Cluster clusters[], Point points[], int k, int num_points) {
    for (int i = 0; i < k; i++) {
        clusters[i].center = points[i];  // Initialize centers from the first k points
        clusters[i].count = 0;            // Reset points count
    }
}

void assign_points_to_clusters(Point points[], Cluster clusters[], int k, int num_points) {
    for (int i = 0; i < k; i++) {
        clusters[i].count = 0;  // Reset point count for each iteration
    }
    
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int cluster_index = -1;

        for (int j = 0; j < k; j++) {
            double distance = euclidean_distance(points[i], clusters[j].center);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }

        clusters[cluster_index].points[clusters[cluster_index].count] = points[i];
        clusters[cluster_index].count++;
    }
}

void update_clusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].count == 0) continue;  // Avoid division by zero
        double sum_x = 0, sum_y = 0;

        for (int j = 0; j < clusters[i].count; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }

        clusters[i].center.x = sum_x / clusters[i].count;
        clusters[i].center.y = sum_y / clusters[i].count;
    }
}

int main() {
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];
    int num_points = 0;
    int k = 3; // Number of clusters
    FILE *file = fopen("points.txt", "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return EXIT_FAILURE;
    }

    // Read points from the file
    while (fscanf(file, "%lf %lf", &points[num_points].x, &points[num_points].y) == 2) {
        num_points++;
        if (num_points >= MAX_POINTS) break;
    }
    fclose(file);

    // Initialize clusters
    initialize_clusters(clusters, points, k, num_points);

    int iterations = 10;
    for (int i = 0; i < iterations; i++) {
        assign_points_to_clusters(points, clusters, k, num_points);
        update_clusters(clusters, k);
    }

    // Print the cluster centers
    printf("Cluster Centers:\n");
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: (%.2lf, %.2lf)\n", i + 1, clusters[i].center.x, clusters[i].center.y);
    }

    // Print the points in each cluster
    for (int i = 0; i < k; i++) {
        printf("Points in Cluster %d:\n", i + 1);
        for (int j = 0; j < clusters[i].count; j++) {
            printf("    (%.2lf, %.2lf)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }

    return EXIT_SUCCESS;
}