//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 100     /* Number of points */
#define DIMENSIONS 2       /* Number of dimensions of each point */
#define NUM_CLUSTERS 5     /* Number of clusters */
#define MAX_ITERATIONS 100 /* Maximum number of iterations */

/* Define a struct to represent a point */
typedef struct {
    double* coordinates;  /* The coordinates of the point */
    int cluster_id;       /* The id of the cluster that the point belongs to */
} Point;

/* Define a struct to represent a cluster */
typedef struct {
    double* centroid;     /* The centroid of the cluster */
    Point* points;        /* The points that belong to the cluster */
    int num_points;       /* The number of points that belong to the cluster */
} Cluster;

/* Calculate the distance between two points */
double distance(Point* P1, Point* P2) {
    double dist = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        dist += pow(P1->coordinates[i] - P2->coordinates[i], 2);
    }
    return sqrt(dist);
}

int main() {
    /* Generate random points */
    Point points[NUM_POINTS];
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i].coordinates = malloc(sizeof(double) * DIMENSIONS);
        for (int j = 0; j < DIMENSIONS; j++) {
            points[i].coordinates[j] = rand() / (double)RAND_MAX;
        }
    }

    /* Initialize clusters */
    Cluster clusters[NUM_CLUSTERS];
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        /* Choose a random point as the centroid */
        int centroid_index = rand() % NUM_POINTS;
        clusters[i].centroid = malloc(sizeof(double) * DIMENSIONS);
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i].centroid[j] = points[centroid_index].coordinates[j];
        }

        /* Allocate memory for the points array and add the centroid point */
        clusters[i].points = malloc(sizeof(Point));
        clusters[i].points[0] = points[centroid_index];
        clusters[i].num_points = 1;
    }

    /* Run K-means algorithm */
    int iteration_count = 0;
    while (iteration_count < MAX_ITERATIONS) {
        /* Assign each point to the closest cluster */
        for (int i = 0; i < NUM_POINTS; i++) {
            double min_distance = INFINITY;
            int closest_cluster_index = -1;
            for (int j = 0; j < NUM_CLUSTERS; j++) {
                double d = distance(&points[i], &clusters[j].points[0]);
                if (d < min_distance) {
                    min_distance = d;
                    closest_cluster_index = j;
                }
            }
            points[i].cluster_id = closest_cluster_index;
        }

        /* Recalculate centroids */
        for (int i = 0; i < NUM_CLUSTERS; i++) {
            /* Clear the current points array */
            clusters[i].num_points = 0;

            /* Calculate the average coordinates of all points in the cluster */
            double sum_coords[DIMENSIONS] = { 0.0 };
            for (int j = 0; j < NUM_POINTS; j++) {
                if (points[j].cluster_id == i) {
                    clusters[i].num_points++;
                    for (int k = 0; k < DIMENSIONS; k++) {
                        sum_coords[k] += points[j].coordinates[k];
                    }
                }
            }
            for (int j = 0; j < DIMENSIONS; j++) {
                clusters[i].centroid[j] = sum_coords[j] / (double)clusters[i].num_points;
            }

            /* Allocate memory for the new points array and add the centroid point */
            clusters[i].points = malloc(sizeof(Point) * clusters[i].num_points);
            clusters[i].points[0].coordinates = clusters[i].centroid;
            clusters[i].points[0].cluster_id = i;

            /* Add all the points in the cluster (except for the centroid point) to the new points array */
            int point_index = 1;
            for (int j = 0; j < NUM_POINTS; j++) {
                if (points[j].cluster_id == i && &points[j] != &clusters[i].points[0]) {
                    clusters[i].points[point_index] = points[j];
                    point_index++;
                }
            }
        }

        iteration_count++;
    }

    /* Print the results */
    printf("Cluster assignments:\n");
    for (int i = 0; i < NUM_POINTS; i++) {
        printf("%d ", points[i].cluster_id);
    }
    printf("\n");

    /* Free memory */
    for (int i = 0; i < NUM_POINTS; i++) {
        free(points[i].coordinates);
    }
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        free(clusters[i].centroid);
        free(clusters[i].points);
    }

    return 0;
}