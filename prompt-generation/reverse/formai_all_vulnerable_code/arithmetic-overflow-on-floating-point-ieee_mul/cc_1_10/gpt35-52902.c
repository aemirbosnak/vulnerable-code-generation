//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100
#define K 3
#define MAX_ITERS 100

struct point {
    double x, y;
};

struct cluster {
    struct point centroid;
    int size;
    struct point points[N];
};

double distance(struct point a, struct point b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

void add_point_to_cluster(struct point p, struct cluster *c) {
    c->points[c->size++] = p;
}

void calculate_centroid(struct cluster *c) {
    double x = 0, y = 0;
    for (int i = 0; i < c->size; i++) {
        x += c->points[i].x;
        y += c->points[i].y;
    }
    c->centroid.x = x / c->size;
    c->centroid.y = y / c->size;
}

void assign_points_to_clusters(struct point points[], struct cluster clusters[]) {
    for (int i = 0; i < N; i++) {
        double min_distance = INFINITY;
        int cluster_index = -1;
        for (int j = 0; j < K; j++) {
            double d = distance(points[i], clusters[j].centroid);
            if (d < min_distance) {
                min_distance = d;
                cluster_index = j;
            }
        }
        add_point_to_cluster(points[i], &clusters[cluster_index]);
    }
}

void print_clusters(struct cluster clusters[]) {
    for (int i = 0; i < K; i++) {
        printf("Cluster %d: centroid (%.2f, %.2f)\n", i+1, clusters[i].centroid.x, clusters[i].centroid.y);
        for (int j = 0; j < clusters[i].size; j++) {
            printf("  (%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}

int main() {
    struct point points[N] = {
        {1, 1}, {1, 2}, {1, 3}, {2, 1}, {2, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3},
        {11, 11}, {11, 12}, {11, 13}, {12, 11}, {12, 12}, {12, 13}, {13, 11}, {13, 12}, {13, 13},
        {21, 21}, {21, 22}, {21, 23}, {22, 21}, {22, 22}, {22, 23}, {23, 21}, {23, 22}, {23, 23},
        {45, 50}, {55, 50}, {50, 60}
    };
    struct cluster clusters[K] = {
        {.centroid = {1, 1}, .size = 0},
        {.centroid = {11, 11}, .size = 0},
        {.centroid = {21, 21}, .size = 0}
    };
    assign_points_to_clusters(points, clusters);
    for (int i = 0; i < MAX_ITERS; i++) {
        for (int j = 0; j < K; j++) {
            calculate_centroid(&clusters[j]);
            clusters[j].size = 0;
        }
        assign_points_to_clusters(points, clusters);
    }
    print_clusters(clusters);
    return 0;
}