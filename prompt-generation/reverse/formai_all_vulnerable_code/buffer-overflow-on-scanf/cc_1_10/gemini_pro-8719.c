//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Cluster;

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int n;
    scanf("%d", &n);

    Point *points = malloc(sizeof(Point) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    int k;
    scanf("%d", &k);

    Cluster *clusters = malloc(sizeof(Cluster) * k);
    for (int i = 0; i < k; i++) {
        clusters[i].points = malloc(sizeof(Point) * n);
        clusters[i].num_points = 0;
    }

    for (int i = 0; i < n; i++) {
        int min_cluster = 0;
        double min_distance = INFINITY;
        for (int j = 0; j < k; j++) {
            double dist = distance(points[i], clusters[j].points[0]);
            if (dist < min_distance) {
                min_cluster = j;
                min_distance = dist;
            }
        }
        clusters[min_cluster].points[clusters[min_cluster].num_points++] = points[i];
    }

    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("%d %d\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    return 0;
}