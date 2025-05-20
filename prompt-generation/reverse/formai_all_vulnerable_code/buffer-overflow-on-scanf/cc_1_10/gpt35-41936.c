//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Implementation of C-Clustering algorithm using Euclidean distance formula.
*/

#define MAX_POINTS 1000
#define MAX_CLUSTERS 10

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_POINTS];
    int count;
} Cluster;

int n_points, n_clusters, max_iterations;
Point points[MAX_POINTS];
Cluster clusters[MAX_CLUSTERS];

double euclidean_distance(Point a, Point b) {
    double x_diff = a.x - b.x;
    double y_diff = a.y - b.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

void seed_clusters() {
    for (int i = 0; i < n_clusters; ++i) {
        clusters[i].centroid = points[i];
    }
}

int assign_cluster(Point p) {
    double min_distance = INFINITY;
    int closest_cluster = 0;

    for (int i = 0; i < n_clusters; ++i) {
        double distance = euclidean_distance(p, clusters[i].centroid);
        if (distance < min_distance) {
            min_distance = distance;
            closest_cluster = i;
        }
    }

    clusters[closest_cluster].points[clusters[closest_cluster].count++] = p;

    return closest_cluster;
}

void calc_centroids() {
    for (int i = 0; i < n_clusters; ++i) {
        double sum_x = 0, sum_y = 0;
        for (int j = 0; j < clusters[i].count; ++j) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sum_x / clusters[i].count;
        clusters[i].centroid.y = sum_y / clusters[i].count;
    }
}

void print_clusters() {
    for (int i = 0; i < n_clusters; ++i) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].count; ++j) {
            printf("\t(%lf, %lf)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\tCentroid: (%lf, %lf)\n", clusters[i].centroid.x, clusters[i].centroid.y);
    }
}

int main() {
    printf("Enter the number of points: ");
    scanf("%d", &n_points);

    printf("Enter the number of clusters: ");
    scanf("%d", &n_clusters);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    printf("Enter the points:\n");
    for (int i = 0; i < n_points; ++i) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    seed_clusters();

    // Run clustering algorithm for max_iterations or until clusters don't change
    int iterations = 0;
    int cluster_changed = 1;
    while (iterations < max_iterations && cluster_changed) {
        cluster_changed = 0;

        // Assign each point to its closest cluster
        for (int i = 0; i < n_points; ++i) {
            int assigned_cluster = assign_cluster(points[i]);
            if (assigned_cluster != i) {
                cluster_changed = 1;
            }
        }

        // Recompute centroids
        calc_centroids();

        ++iterations;
    }

    print_clusters();

    return 0;
}