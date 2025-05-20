//FormAI DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define struct to store data points
typedef struct {
    double x;
    double y;
    int cluster;
} Point;


int main() {
    // Read in data points from file
    FILE *fp;

    if ((fp = fopen("data.txt", "r")) == NULL) {
        printf("Error: cannot open file\n");
        exit(1);
    }

    int num_points;
    fscanf(fp, "%d", &num_points);

    Point *points = malloc(num_points * sizeof(Point));
    for (int i = 0; i < num_points; i++) {
        fscanf(fp, "%lf %lf", &points[i].x, &points[i].y);
        points[i].cluster = -1;
    }

    fclose(fp);

    // Implement k-means clustering algorithm
    int num_clusters = 3;
    Point *centroids = malloc(num_clusters * sizeof(Point));

    // Select initial centroids randomly
    for (int i = 0; i < num_clusters; i++) {
        int idx = rand() % num_points;
        centroids[i] = points[idx];
    }

    int max_iter = 100;
    double tolerance = 0.001;
    int iter = 0;
    double error = 0.0;

    while (iter < max_iter) {
        // Assign each point to the nearest cluster
        for (int i = 0; i < num_points; i++) {
            double min_dist = INFINITY;
            int cluster_idx = -1;
            for (int j = 0; j < num_clusters; j++) {
                double dist = sqrt(pow(points[i].x - centroids[j].x, 2) + pow(points[i].y - centroids[j].y, 2));
                if (dist < min_dist) {
                    min_dist = dist;
                    cluster_idx = j;
                }
            }
            points[i].cluster = cluster_idx;
        }

        // Update centroid positions
        error = 0.0;
        for (int i = 0; i < num_clusters; i++) {
            int num_points_in_cluster = 0;
            double sum_x = 0.0;
            double sum_y = 0.0;
            for (int j = 0; j < num_points; j++) {
                if (points[j].cluster == i) {
                    num_points_in_cluster++;
                    sum_x += points[j].x;
                    sum_y += points[j].y;
                }
            }
            if (num_points_in_cluster > 0) {
                double old_x = centroids[i].x;
                double old_y = centroids[i].y;
                centroids[i].x = sum_x / num_points_in_cluster;
                centroids[i].y = sum_y / num_points_in_cluster;
                error += sqrt(pow(old_x - centroids[i].x, 2) + pow(old_y - centroids[i].y, 2));
            }
        }

        if (error < tolerance) {
            break;
        }

        iter++;
    }

    // Output results
    printf("Final cluster assignments:\n");
    for (int i = 0; i < num_points; i++) {
        printf("(%lf, %lf) assigned to cluster %d\n", points[i].x, points[i].y, points[i].cluster);
    }

    printf("Final centroid positions:\n");
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d: (%lf, %lf)\n", i, centroids[i].x, centroids[i].y);
    }

    free(points);
    free(centroids);

    return 0;
}