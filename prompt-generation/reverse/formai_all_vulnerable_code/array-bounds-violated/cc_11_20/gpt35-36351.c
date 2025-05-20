//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POINTS 100000
#define MAX_CLUSTERS 10

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point center;
    int count;
} cluster;

int main() {
    int n_points, n_clusters;
    point points[MAX_POINTS];
    cluster clusters[MAX_CLUSTERS];
    int assignments[MAX_POINTS];
    int i, j, k, l;
    double min_distance, distance;

    // get input from user
    printf("Enter number of points: ");
    scanf("%d", &n_points);

    printf("Enter number of clusters: ");
    scanf("%d", &n_clusters);

    // generate random points
    srand(time(NULL));

    for (i = 0; i < n_points; i++) {
        points[i].x = (double)rand()/(double)RAND_MAX;
        points[i].y = (double)rand()/(double)RAND_MAX;
    }

    // initialize clusters with random points
    for (i = 0; i < n_clusters; i++) {
        clusters[i].center = points[rand() % n_points];
        clusters[i].count = 0;
    }

    // iterate until convergence
    for (l = 0; l < 10; l++) {
        // assign each point to nearest cluster
        for (i = 0; i < n_points; i++) {
            min_distance = 1000000000;
            for (j = 0; j < n_clusters; j++) {
                distance = (points[i].x - clusters[j].center.x) * (points[i].x - clusters[j].center.x)
                         + (points[i].y - clusters[j].center.y) * (points[i].y - clusters[j].center.y);
                if (distance < min_distance) {
                    min_distance = distance;
                    assignments[i] = j;
                }
            }
            clusters[assignments[i]].count++;
        }

        // update cluster centers
        for (i = 0; i < n_clusters; i++) {
            clusters[i].center.x = 0;
            clusters[i].center.y = 0;
        }

        for (i = 0; i < n_points; i++) {
            clusters[assignments[i]].center.x += points[i].x;
            clusters[assignments[i]].center.y += points[i].y;
        }

        for (i = 0; i < n_clusters; i++) {
            if (clusters[i].count == 0) {
                continue;
            }
            clusters[i].center.x /= clusters[i].count;
            clusters[i].center.y /= clusters[i].count;
            clusters[i].count = 0;
        }
    }

    // print results
    for (i = 0; i < n_clusters; i++) {
        printf("Cluster %d:\n", i);
        printf("Center: (%f, %f)\n", clusters[i].center.x, clusters[i].center.y);
        printf("Points: \n");
        for (j = 0; j < n_points; j++) {
            if (assignments[j] == i) {
                printf("(%f, %f)\n", points[j].x, points[j].y);
            }
        }
    }

    return 0;
}