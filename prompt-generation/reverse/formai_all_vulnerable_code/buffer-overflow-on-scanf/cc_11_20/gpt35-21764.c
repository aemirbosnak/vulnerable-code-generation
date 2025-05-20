//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_ITERATIONS 1000

struct Point {
    float x, y;
    int cluster;
};

int main() {
    struct Point points[MAX_POINTS];
    int k, n, iterations;
    float min_distance, distance, x, y, centroid_x, centroid_y;

    // read input data
    scanf("%d", &k); // number of clusters
    scanf("%d", &n); // number of points
    for (int i = 0; i < n; i++) {
        scanf("%f", &points[i].x);
        scanf("%f", &points[i].y);
        points[i].cluster = -1; // initialize to no cluster
    }

    // initialize centroids randomly
    for (int i = 0; i < k; i++) {
        points[i].cluster = i;
    }
    for (int i = k; i < n; i++) {
        int centroid_index = (int)(rand() % k);
        points[i].cluster = centroid_index;
    }

    // iterate until convergence or max iterations
    iterations = 0;
    while (iterations < MAX_ITERATIONS) {
        int changed = 0;

        // update centroids
        for (int i = 0; i < k; i++) {
            x = 0;
            y = 0;
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (points[j].cluster == i) {
                    x += points[j].x;
                    y += points[j].y;
                    count++;
                }
            }
            if (count > 0) {
                x /= count;
                y /= count;

                // update centroid
                if (points[i].x != x || points[i].y != y) {
                    points[i].x = x;
                    points[i].y = y;
                    changed = 1;
                }
            }
        }

        if (!changed) {
            // converged
            break;
        }

        // assign points to closest cluster
        for (int i = 0; i < n; i++) {
            min_distance = INFINITY;
            for (int j = 0; j < k; j++) {
                distance = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
                if (distance < min_distance) {
                    // update cluster
                    points[i].cluster = j;
                    min_distance = distance;
                }
            }
        }

        iterations++;
    }

    // output results
    for (int i = 0; i < k; i++) {
        printf("Centroid %d: (%f, %f)\n", i, points[i].x, points[i].y);
        printf("Points in cluster %d:\n", i);
        for (int j = 0; j < n; j++) {
            if (points[j].cluster == i) {
                printf("(%f, %f)\n", points[j].x, points[j].y);
            }
        }
    }

    return 0;
}