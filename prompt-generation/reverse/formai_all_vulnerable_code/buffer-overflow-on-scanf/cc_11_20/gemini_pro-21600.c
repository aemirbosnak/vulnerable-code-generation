//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define MAX_CLUSTERS 10

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point center;
    int num_points;
} cluster;

int main() {
    int i, j, k;
    int num_points, num_clusters;
    point points[MAX_POINTS];
    cluster clusters[MAX_CLUSTERS];

    // Read input
    scanf("%d %d", &num_points, &num_clusters);
    for (i = 0; i < num_points; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // Initialize clusters
    for (i = 0; i < num_clusters; i++) {
        clusters[i].center.x = rand() % 1000;
        clusters[i].center.y = rand() % 1000;
        clusters[i].num_points = 0;
    }

    // Assign points to clusters
    for (i = 0; i < num_points; i++) {
        int min_dist = -1;
        int min_cluster = -1;
        for (j = 0; j < num_clusters; j++) {
            int dist = (points[i].x - clusters[j].center.x) * (points[i].x - clusters[j].center.x) + (points[i].y - clusters[j].center.y) * (points[i].y - clusters[j].center.y);
            if (min_dist == -1 || dist < min_dist) {
                min_dist = dist;
                min_cluster = j;
            }
        }
        clusters[min_cluster].num_points++;
    }

    // Update cluster centers
    for (i = 0; i < num_clusters; i++) {
        clusters[i].center.x = 0;
        clusters[i].center.y = 0;
        for (j = 0; j < num_points; j++) {
            if (j % num_clusters == i) {
                clusters[i].center.x += points[j].x;
                clusters[i].center.y += points[j].y;
            }
        }
        clusters[i].center.x /= clusters[i].num_points;
        clusters[i].center.y /= clusters[i].num_points;
    }

    // Print output
    for (i = 0; i < num_points; i++) {
        for (j = 0; j < num_clusters; j++) {
            if (i % num_clusters == j) {
                printf("%d %d\n", clusters[j].center.x, clusters[j].center.y);
            }
        }
    }

    return 0;
}