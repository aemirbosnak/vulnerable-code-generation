//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    double x;
    double y;
    int cluster;
};

double distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void assign_clusters(struct Point* points, int num_points, struct Point* centroids, int num_clusters) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = distance(points[i], centroids[0]);
        int min_index = 0;
        for (int j = 1; j < num_clusters; j++) {
            double d = distance(points[i], centroids[j]);
            if (d < min_distance) {
                min_distance = d;
                min_index = j;
            }
        }
        points[i].cluster = min_index;
    }
}

void recompute_centroids(struct Point* points, int num_points, struct Point* centroids, int num_clusters) {
    int* cluster_sizes = calloc(num_clusters, sizeof(int));
    for (int i = 0; i < num_points; i++) {
        int c = points[i].cluster;
        centroids[c].x += points[i].x;
        centroids[c].y += points[i].y;
        cluster_sizes[c]++;
    }
    for (int i = 0; i < num_clusters; i++) {
        centroids[i].x /= cluster_sizes[i];
        centroids[i].y /= cluster_sizes[i];
    }
    free(cluster_sizes);
}

void kmeans(struct Point* points, int num_points, struct Point* centroids, int num_clusters, int max_iterations) {
    assign_clusters(points, num_points, centroids, num_clusters);
    int iter = 0;
    while (iter < max_iterations) {
        recompute_centroids(points, num_points, centroids, num_clusters);
        assign_clusters(points, num_points, centroids, num_clusters);
        iter++;
    }
}

int main() {
    struct Point points[] = {{2.0, 3.0}, {5.0, 6.0}, {8.0, 6.0}, {1.0, 2.0}, {5.0, 4.0}, {7.0, 2.0}};
    struct Point centroids[] = {{2.0, 3.0}, {5.0, 6.0}};
    int num_points = 6;
    int num_clusters = 2;
    int max_iterations = 10;
    kmeans(points, num_points, centroids, num_clusters, max_iterations);
    for (int i = 0; i < num_points; i++) {
        printf("Point (%f, %f) is in cluster %d\n", points[i].x, points[i].y, points[i].cluster);
    }
    return 0;
}