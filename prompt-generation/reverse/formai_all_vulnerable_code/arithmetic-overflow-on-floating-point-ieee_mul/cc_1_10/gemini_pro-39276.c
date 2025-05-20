//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data point struct
typedef struct {
    double x;
    double y;
} point;

// Cluster struct
typedef struct {
    point center;
    int size;
    point* points;
} cluster;

// Initialize cluster
cluster* init_cluster(double x, double y) {
    cluster* c = malloc(sizeof(cluster));
    c->center.x = x;
    c->center.y = y;
    c->size = 0;
    c->points = NULL;
    return c;
}

// Add point to cluster
void add_point_to_cluster(cluster* c, point* p) {
    if (c->size == 0) {
        c->points = malloc(sizeof(point));
    } else {
        c->points = realloc(c->points, sizeof(point) * (c->size + 1));
    }
    c->points[c->size++] = *p;
}

// Calculate distance between two points
double distance(point* p1, point* p2) {
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

// Calculate average of points
point average(point* points, int size) {
    point avg;
    avg.x = 0;
    avg.y = 0;
    for (int i = 0; i < size; i++) {
        avg.x += points[i].x;
        avg.y += points[i].y;
    }
    avg.x /= size;
    avg.y /= size;
    return avg;
}

// Find closest cluster to point
cluster* find_closest_cluster(point* p, cluster** clusters, int num_clusters) {
    cluster* closest_cluster = NULL;
    double closest_distance = INFINITY;
    for (int i = 0; i < num_clusters; i++) {
        double distance_to_cluster = distance(p, &clusters[i]->center);
        if (distance_to_cluster < closest_distance) {
            closest_distance = distance_to_cluster;
            closest_cluster = clusters[i];
        }
    }
    return closest_cluster;
}

// Assign points to clusters
void assign_points_to_clusters(point* points, int num_points, cluster** clusters, int num_clusters) {
    for (int i = 0; i < num_points; i++) {
        cluster* closest_cluster = find_closest_cluster(&points[i], clusters, num_clusters);
        add_point_to_cluster(closest_cluster, &points[i]);
    }
}

// Update cluster centers
void update_cluster_centers(cluster** clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i]->center = average(clusters[i]->points, clusters[i]->size);
    }
}

// Main function
int main() {
    // Initialize points
    point points[] = {
        {1.0, 2.0},
        {3.0, 4.0},
        {5.0, 6.0},
        {7.0, 8.0},
        {9.0, 10.0},
    };
    int num_points = sizeof(points) / sizeof(point);

    // Initialize clusters
    cluster* clusters[] = {
        init_cluster(0.0, 0.0),
        init_cluster(10.0, 10.0),
    };
    int num_clusters = sizeof(clusters) / sizeof(cluster*);

    // Assign points to clusters
    assign_points_to_clusters(points, num_points, clusters, num_clusters);

    // Update cluster centers
    update_cluster_centers(clusters, num_clusters);

    // Print clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i]->size; j++) {
            printf("  (%f, %f)\n", clusters[i]->points[j].x, clusters[i]->points[j].y);
        }
    }

    return 0;
}