//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define constant for cluster size
#define CLUSTER_SIZE 2

// function to calculate euclidean distance between two points
double euclidean_distance(double* point1, double* point2, int dimensions) {
    double distance = 0;
    for (int i = 0; i < dimensions; i++) {
        distance += pow((point1[i] - point2[i]), 2);
    }
    return sqrt(distance);
}

int main() {
    int num_points, dimensions;

    // get user input for number of points and dimensions
    printf("Enter the number of points: ");
    scanf("%d", &num_points);
    printf("Enter the number of dimensions: ");
    scanf("%d", &dimensions);

    // allocate memory for points array
    double* points = (double*)malloc(num_points * dimensions * sizeof(double));

    // get user input for each point
    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j < dimensions; j++) {
            printf("Enter the %d-th coordinate of the %d-th point: ", j + 1, i + 1);
            scanf("%lf", &points[(i * dimensions) + j]);
        }
    }

    // allocate memory for cluster array
    double* clusters = (double*)malloc(CLUSTER_SIZE * dimensions * sizeof(double));

    // initialize clusters with first two points
    for (int i = 0; i < dimensions; i++) {
        clusters[i] = points[i];
        clusters[i + dimensions] = points[i + dimensions];
    }

    // keep track of which cluster each point belongs to
    int* point_cluster = (int*)malloc(num_points * sizeof(int));

    // keep track of which cluster each cluster belongs to
    int* cluster_cluster = (int*)malloc(CLUSTER_SIZE * sizeof(int));

    // run K-means clustering algorithm until convergence
    while (1) {
        int num_changes = 0;

        // assign each point to closest cluster
        for (int i = 0; i < num_points; i++) {
            double min_distance = INFINITY;
            int min_cluster;
            for (int j = 0; j < CLUSTER_SIZE; j++) {
                double distance = euclidean_distance(&points[i * dimensions], &clusters[j * dimensions], dimensions);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_cluster = j;
                }
            }
            if (point_cluster[i] != min_cluster) {
                point_cluster[i] = min_cluster;
                num_changes++;
            }
        }

        // if no points changed cluster, stop
        if (num_changes == 0) {
            break;
        }

        // update cluster centers to be centroid of all points in that cluster
        for (int i = 0; i < CLUSTER_SIZE; i++) {
            int num_points_in_cluster = 0;
            double* centroid = (double*)malloc(dimensions * sizeof(double));
            for (int j = 0; j < dimensions; j++) {
                centroid[j] = 0;
            }
            for (int j = 0; j < num_points; j++) {
                if (point_cluster[j] == i) {
                    num_points_in_cluster++;
                    for (int k = 0; k < dimensions; k++) {
                        centroid[k] += points[(j * dimensions) + k];
                    }
                }
            }
            for (int j = 0; j < dimensions; j++) {
                clusters[(i * dimensions) + j] = centroid[j] / num_points_in_cluster;
            }
        }
    }

    // output results
    for (int i = 0; i < num_points; i++) {
        printf("Point %d belongs to cluster %d\n", i + 1, point_cluster[i] + 1);
    }

    // free allocated memory
    free(points);
    free(clusters);
    free(point_cluster);
    free(cluster_cluster);

    return 0;
}