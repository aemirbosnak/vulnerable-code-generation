//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 50 // Define maximum points that the program can handle
#define MAX_ITERATIONS 100 // Define maximum number of iterations for the algorithm

struct Point {
    double x;
    double y;
};

struct Cluster {
    int id;
    struct Point center;
    struct Point points[MAX_POINTS];
    int size;
};

int main() {
    struct Point points[MAX_POINTS];
    int num_points = 0;

    // Read in the points from a file or user input
    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    printf("Enter the %d points (format: x,y):\n", num_points);
    for (int i = 0; i < num_points; i++) {
        scanf("%lf,%lf", &points[i].x, &points[i].y);
    }

    // Initialize the clusters
    struct Cluster clusters[MAX_POINTS];
    int num_clusters = 3; // Set the number of clusters
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].id = i;
        clusters[i].center.x = points[i].x;
        clusters[i].center.y = points[i].y;
        clusters[i].size = 0;
    }

    // Run the clustering algorithm
    int iteration = 0;
    double epsilon = 0.001; // Set the convergence criterion
    int converged = 0;

    while (iteration < MAX_ITERATIONS && !converged) {
        // Assign each point to the nearest cluster
        for (int i = 0; i < num_points; i++) {
            double min_distance = INFINITY;
            int closest_cluster = 0;
            for (int j = 0; j < num_clusters; j++) {
                double distance = sqrt(pow(points[i].x - clusters[j].center.x, 2) + pow(points[i].y - clusters[j].center.y, 2));
                if (distance < min_distance) {
                    min_distance = distance;
                    closest_cluster = j;
                }
            }
            clusters[closest_cluster].points[clusters[closest_cluster].size] = points[i];
            clusters[closest_cluster].size++;
        }

        // Update the cluster centers
        converged = 1;
        for (int i = 0; i < num_clusters; i++) {
            double sum_x = 0;
            double sum_y = 0;
            for (int j = 0; j < clusters[i].size; j++) {
                sum_x += clusters[i].points[j].x;
                sum_y += clusters[i].points[j].y;
            }
            double new_center_x = sum_x / clusters[i].size;
            double new_center_y = sum_y / clusters[i].size;
            if (fabs(new_center_x - clusters[i].center.x) > epsilon || fabs(new_center_y - clusters[i].center.y) > epsilon) {
                converged = 0;
            }
            clusters[i].center.x = new_center_x;
            clusters[i].center.y = new_center_y;
            clusters[i].size = 0;
        }

        iteration++;
    }

    // Print the results
    printf("Clustering results:\n");
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d center: (%.2lf, %.2lf)\n", clusters[i].id, clusters[i].center.x, clusters[i].center.y);
        printf("Points in cluster:\n");
        for (int j = 0; j < clusters[i].size; j++) {
            printf("(%.2lf, %.2lf)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }

    return 0;
}