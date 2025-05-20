//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: creative
/*
 * This is a unique implementation of the C Clustering Algorithm.
 * The program takes a set of 2D x,y coordinates and groups them into k clusters using the k-means clustering algorithm.
 * You can specify the number of clusters you want to form, and the program will randomly generate initial cluster centers,
 * then iteratively assign each point to its closest cluster and recalculate the cluster centers until convergence is reached.
 *
 * Author: ChatBot
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_COORD 100.0 /* Maximum value for a coordinate */
#define NUM_POINTS 100 /* Number of points to generate */

typedef struct {
    double x;
    double y;
} point;

/* Function to calculate the distance between two points */
double distance(point p1, point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

/* Function to randomly generate a set of points within a given range */
void generate_points(point *points, int num_points) {
    int i;
    for (i = 0; i < num_points; i++) {
        points[i].x = ((double)rand()/RAND_MAX) * MAX_COORD;
        points[i].y = ((double)rand()/RAND_MAX) * MAX_COORD;
    }
}

/* Function to initialize the cluster centers with random points */
void initialize_clusters(point *clusters, int num_clusters) {
    int i;
    for (i = 0; i < num_clusters; i++) {
        clusters[i].x = ((double)rand()/RAND_MAX) * MAX_COORD;
        clusters[i].y = ((double)rand()/RAND_MAX) * MAX_COORD;
    }
}

/* Function to assign each point to its closest cluster */
void assign_clusters(point *points, int num_points, point *clusters, int num_clusters, int *cluster_assignments) {
    int i, j;
    double min_distance, dist;
    for (i = 0; i < num_points; i++) {
        min_distance = MAX_COORD*sqrt(2.0); /* Set initial minimum distance to the maximum possible */
        for (j = 0; j < num_clusters; j++) {
            dist = distance(points[i], clusters[j]);
            if (dist < min_distance) {
                min_distance = dist;
                cluster_assignments[i] = j;
            }
        }
    }
}

/* Function to recalculate the cluster centers based on the assigned points */
void recalculate_clusters(point *points, int num_points, point *clusters, int num_clusters, int *cluster_assignments) {
    int i, j, count;
    double x_sum, y_sum;
    for (i = 0; i < num_clusters; i++) {
        count = 0;
        x_sum = y_sum = 0.0;
        for (j = 0; j < num_points; j++) {
            if (cluster_assignments[j] == i) {
                count++;
                x_sum += points[j].x;
                y_sum += points[j].y;
            }
        }
        clusters[i].x = x_sum / count;
        clusters[i].y = y_sum / count;
    }
}

/* Function to check if the cluster assignments have changed */
int check_convergence(int *prev_assignments, int *curr_assignments, int num_points) {
    int i;
    for (i = 0; i < num_points; i++) {
        if (prev_assignments[i] != curr_assignments[i]) {
            return 0; /* Cluster assignments have changed, not yet converged */
        }
    }
    return 1; /* Cluster assignments have not changed, converged */
}

/* Main function */
int main(int argc, char *argv[]) {
    srand(time(NULL)); /* Seed the random number generator */

    int num_clusters, i;
    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);

    point *points = malloc(sizeof(point) * NUM_POINTS);
    generate_points(points, NUM_POINTS); /* Generate random points */

    point *clusters = malloc(sizeof(point) * num_clusters);
    initialize_clusters(clusters, num_clusters); /* Initialize random cluster centers */

    int *cluster_assignments = malloc(sizeof(int) * NUM_POINTS);
    int *prev_assignments = malloc(sizeof(int) * NUM_POINTS);

    int converged = 0;
    while (!converged) {
        assign_clusters(points, NUM_POINTS, clusters, num_clusters, cluster_assignments); /* Assign each point to its closest cluster */

        /* Check if the cluster assignments have changed from the previous iteration */
        if (check_convergence(prev_assignments, cluster_assignments, NUM_POINTS)) {
            converged = 1;
        } else {
            for (i = 0; i < NUM_POINTS; i++) {
                prev_assignments[i] = cluster_assignments[i];
            }
            recalculate_clusters(points, NUM_POINTS, clusters, num_clusters, cluster_assignments); /* Recalculate the cluster centers */

            /* Print the current cluster centers */
            printf("Cluster centers:\n");
            for (i = 0; i < num_clusters; i++) {
                printf("(%lf, %lf)\n", clusters[i].x, clusters[i].y);
            }
            printf("\n");
        }
    }

    free(points);
    free(clusters);
    free(cluster_assignments);
    free(prev_assignments);

    return 0;
}