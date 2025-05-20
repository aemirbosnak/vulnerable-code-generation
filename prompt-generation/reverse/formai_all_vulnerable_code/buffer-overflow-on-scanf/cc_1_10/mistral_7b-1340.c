//MISTRAL-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX_POINTS 10000
#define EPSILON 0.5
#define MIN_POINTS 5

typedef struct {
    double x, y;
} Point;

typedef struct {
    int id;
    int cluster_id;
} Cluster;

Point points[MAX_POINTS];
Cluster clusters[MAX_POINTS];
bool visited[MAX_POINTS];

int neighbor_count = 0;
int current_cluster_id = -1;
int current_point_id = -1;

double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

void process_point(int point_id) {
    Point p = points[point_id];

    current_point_id = point_id;
    current_cluster_id = -1;

    memset(visited, false, sizeof(visited));
    visited[point_id] = true;

    for (int i = 0; i < MAX_POINTS; i++) {
        if (i == point_id)
            continue;

        if (!visited[i] && distance(points[i], p) <= EPSILON) {
            clusters[i].cluster_id = current_cluster_id;
            neighbor_count++;
            process_point(i);
        }
    }

    if (neighbor_count >= MIN_POINTS) {
        current_cluster_id = clusters[point_id].id = current_cluster_id == -1 ? 0 : current_cluster_id;
    } else {
        clusters[point_id].cluster_id = -1;
    }

    neighbor_count = 0;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
        clusters[i].id = i;
    }

    for (int i = 0; i < n; i++) {
        if (clusters[i].cluster_id == -1) {
            current_cluster_id = -1;
            process_point(i);
        }
    }

    printf("Cluster IDs:\n");
    for (int i = 0; i < n; i++)
        printf("%d: %d\n", i, clusters[i].cluster_id);

    return 0;
}