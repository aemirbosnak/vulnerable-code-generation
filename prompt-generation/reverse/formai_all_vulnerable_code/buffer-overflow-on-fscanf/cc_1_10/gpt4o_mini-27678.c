//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define TOLERANCE 0.001
#define MAX_ITERATIONS 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_POINTS];
    int point_count;
} Cluster;

void read_data(const char* filename, Point* points, int* num_points) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    *num_points = 0;
    while (fscanf(file, "%lf %lf", &points[*num_points].x, &points[*num_points].y) == 2) {
        (*num_points)++;
        if (*num_points >= MAX_POINTS) break;
    }

    fclose(file);
}

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void initialize_clusters(Cluster* clusters, Point* points, int num_clusters, int num_points) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid = points[i]; // Select the first `k` points as initial centroids
        clusters[i].point_count = 0;
    }
}

void assign_points_to_clusters(Cluster* clusters, Point* points, int num_clusters, int num_points) {
    for (int i = 0; i < num_points; i++) {
        double min_dist = distance(points[i], clusters[0].centroid);
        int cluster_index = 0;
        
        for (int j = 1; j < num_clusters; j++) {
            double dist = distance(points[i], clusters[j].centroid);
            if (dist < min_dist) {
                min_dist = dist;
                cluster_index = j;
            }
        }

        clusters[cluster_index].points[clusters[cluster_index].point_count++] = points[i];
    }
}

void update_centroids(Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        double sum_x = 0;
        double sum_y = 0;
        for (int j = 0; j < clusters[i].point_count; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sum_x / clusters[i].point_count;
        clusters[i].centroid.y = sum_y / clusters[i].point_count;
    }
}

int centroids_changed(Cluster* clusters, Cluster* old_clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        if (distance(clusters[i].centroid, old_clusters[i].centroid) > TOLERANCE) {
            return 1;
        }
    }
    return 0;
}

void kmeans(Point* points, int num_points, int num_clusters) {
    Cluster clusters[MAX_CLUSTERS];
    Cluster old_clusters[MAX_CLUSTERS];

    initialize_clusters(clusters, points, num_clusters, num_points);
    
    for (int iter = 0; iter < MAX_ITERATIONS; iter++) {
        for (int i = 0; i < num_clusters; i++) {
            old_clusters[i] = clusters[i];
            clusters[i].point_count = 0; // Reset point count
        }

        assign_points_to_clusters(clusters, points, num_clusters, num_points);
        update_centroids(clusters, num_clusters);

        if (!centroids_changed(clusters, old_clusters, num_clusters)) {
            break; // Centroids have stabilized
        }
    }

    // Print results
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        for (int j = 0; j < clusters[i].point_count; j++) {
            printf("\tPoint: (%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

int main() {
    Point points[MAX_POINTS];
    int num_points = 0;

    read_data("data.txt", points, &num_points);

    int num_clusters = 3; // Example number of clusters
    kmeans(points, num_points, num_clusters);

    return 0;
}