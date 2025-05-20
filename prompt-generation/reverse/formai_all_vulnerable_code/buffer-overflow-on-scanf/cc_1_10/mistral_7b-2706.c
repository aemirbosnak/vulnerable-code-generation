//MISTRAL-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_POINTS 1000
#define EPSILON 1.0
#define MIN_POINTS 5

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    int label;
    int visited;
} Cluster;

Cluster clusters[MAX_POINTS];
Point points[MAX_POINTS];

void init() {
    int i;

    for (i = 0; i < MAX_POINTS; ++i) {
        clusters[i].label = -1;
        clusters[i].visited = 0;
    }
}

int find_nearest_point_index(double x, double y) {
    int i, min_index = 0;
    double min_dist = pow(pow(points[0].x - x, 2) + pow(points[0].y - y, 2), 0.5);

    for (i = 1; i < MAX_POINTS; ++i) {
        double dist = pow(pow(points[i].x - x, 2) + pow(points[i].y - y, 2), 0.5);

        if (dist < min_dist) {
            min_dist = dist;
            min_index = i;
        }
    }

    return min_index;
}

void expand_cluster(int current_point_index) {
    int nearest_point_index = find_nearest_point_index(points[current_point_index].x, points[current_point_index].y);

    if (nearest_point_index >= 0 && clusters[nearest_point_index].label == -1 &&
        pow(pow(points[current_point_index].x - points[nearest_point_index].x, 2) +
             pow(points[current_point_index].y - points[nearest_point_index].y, 2), 0.5) <= EPSILON) {

        clusters[current_point_index].label = clusters[nearest_point_index].label = current_point_index;
        expand_cluster(nearest_point_index);
    }
}

int main() {
    int i, j, points_count = 0;

    scanf("%d", &i);

    for (j = 0; j < i; ++j) {
        scanf("%lf %lf", &points[j].x, &points[j].y);
        ++points_count;
    }

    init();

    for (i = 0; i < points_count; ++i) {
        if (clusters[i].label == -1) {
            clusters[i].label = i;
            expand_cluster(i);
        }
    }

    for (i = 0; i < points_count; ++i) {
        if (clusters[i].label != -1) {
            printf("Point (%lf, %lf) is in cluster %d\n", points[i].x, points[i].y, clusters[i].label);
        }
    }

    return 0;
}