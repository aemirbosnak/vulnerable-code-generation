//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
    int num_clusters;
} Clustering;

void kmeans(Clustering *clustering, int num_iterations) {
    srand(time(NULL));
    int i, j, k, n;
    int min_dist, min_dist_id;
    double total_dist = 0;

    for (i = 0; i < clustering->num_points; i++) {
        clustering->points[i].id = i;
    }

    for (i = 0; i < clustering->num_clusters; i++) {
        clustering->points[i].x = (double)rand() / RAND_MAX;
        clustering->points[i].y = (double)rand() / RAND_MAX;
    }

    for (i = 0; i < clustering->num_points; i++) {
        min_dist = 9999;
        min_dist_id = -1;

        for (j = 0; j < clustering->num_clusters; j++) {
            double dist = ((clustering->points[j].x - clustering->points[i].x) * (clustering->points[j].x - clustering->points[i].x)) + ((clustering->points[j].y - clustering->points[i].y) * (clustering->points[j].y - clustering->points[i].y));
            if (dist < min_dist) {
                min_dist = dist;
                min_dist_id = j;
            }
        }
        clustering->points[i].id = min_dist_id;
    }

    for (i = 0; i < clustering->num_points; i++) {
        total_dist += min_dist;
    }

    for (i = 0; i < clustering->num_points; i++) {
        clustering->points[i].x /= total_dist;
        clustering->points[i].y /= total_dist;
    }

    for (j = 0; j < clustering->num_clusters; j++) {
        for (i = 0; i < clustering->num_points; i++) {
            if (clustering->points[i].id == j) {
                clustering->points[j].x += clustering->points[i].x;
                clustering->points[j].y += clustering->points[i].y;
            }
        }
    }

    for (k = 0; k < clustering->num_clusters; k++) {
        for (i = 0; i < clustering->num_points; i++) {
            if (clustering->points[i].id == k) {
                clustering->points[k].x /= clustering->num_points;
                clustering->points[k].y /= clustering->num_points;
            }
        }
    }

    for (i = 0; i < clustering->num_clusters; i++) {
        for (j = 0; j < clustering->num_points; j++) {
            if (clustering->points[j].id == i) {
                for (n = 0; n < clustering->num_points; n++) {
                    if (clustering->points[n].id!= i) {
                        double dist = ((clustering->points[i].x - clustering->points[n].x) * (clustering->points[i].x - clustering->points[n].x)) + ((clustering->points[i].y - clustering->points[n].y) * (clustering->points[i].y - clustering->points[n].y));
                        if (dist < min_dist) {
                            min_dist = dist;
                            min_dist_id = n;
                        }
                    }
                }
                clustering->points[j].id = min_dist_id;
            }
        }
    }

    for (i = 0; i < clustering->num_clusters; i++) {
        for (j = 0; j < clustering->num_points; j++) {
            if (clustering->points[j].id == i) {
                clustering->points[i].x = clustering->points[j].x;
                clustering->points[i].y = clustering->points[j].y;
            }
        }
    }

    for (i = 0; i < clustering->num_points; i++) {
        printf("Point %d is in cluster %d, x=%f, y=%f\n", i, clustering->points[i].id, clustering->points[i].x, clustering->points[i].y);
    }
}

int main() {
    srand(time(NULL));
    int num_points, num_clusters, num_iterations;

    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);

    printf("Enter the number of iterations: ");
    scanf("%d", &num_iterations);

    Clustering clustering;
    clustering.num_points = num_points;
    clustering.num_clusters = num_clusters;
    clustering.points = (Point *)malloc(num_points * sizeof(Point));

    for (int i = 0; i < num_points; i++) {
        clustering.points[i].id = i;
        clustering.points[i].x = (double)rand() / RAND_MAX;
        clustering.points[i].y = (double)rand() / RAND_MAX;
    }

    kmeans(&clustering, num_iterations);

    return 0;
}