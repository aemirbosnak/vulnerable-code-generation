//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_ITERATIONS 10

struct Point {
    double x;
    double y;
    int cluster;
};

struct Centroid {
    double x;
    double y;
    int count;
};

int main() {
    int num_points, num_clusters, i, j, k, converged = 0, iteration_count = 0;
    struct Point points[MAX_POINTS];
    struct Centroid centroids[MAX_POINTS];
    
    // Get number of points and clusters from user
    printf("How many points do you want to cluster? (max %d): ", MAX_POINTS);
    scanf("%d", &num_points);
    printf("How many clusters do you want? (max %d): ", num_points);
    scanf("%d", &num_clusters);
    
    // Generate random points
    for (i = 0; i < num_points; i++) {
        points[i].x = (double) rand() / RAND_MAX;
        points[i].y = (double) rand() / RAND_MAX;
        points[i].cluster = -1; // no cluster assigned yet
    }
    
    // Initialize centroids with random points
    for (i = 0; i < num_clusters; i++) {
        centroids[i].x = (double) rand() / RAND_MAX;
        centroids[i].y = (double) rand() / RAND_MAX;
        centroids[i].count = 0;
    }
    
    // Repeat until convergence or max iterations reached
    while (!converged && iteration_count < MAX_ITERATIONS) {
        converged = 1;
        
        // Assign points to clusters
        for (i = 0; i < num_points; i++) {
            double min_distance = INFINITY;
            
            for (j = 0; j < num_clusters; j++) {
                double distance = sqrt(pow(points[i].x - centroids[j].x, 2) + pow(points[i].y - centroids[j].y, 2));
                
                if (distance < min_distance) {
                    min_distance = distance;
                    points[i].cluster = j;
                }
            }
        }
        
        // Recalculate centroids
        for (i = 0; i < num_clusters; i++) {
            double total_x = 0, total_y = 0;
            
            for (j = 0; j < num_points; j++) {
                if (points[j].cluster == i) {
                    total_x += points[j].x;
                    total_y += points[j].y;
                    centroids[i].count++;
                }
            }
            
            if (centroids[i].count > 0) {
                double new_x = total_x / centroids[i].count;
                double new_y = total_y / centroids[i].count;
                
                if (new_x != centroids[i].x || new_y != centroids[i].y) {
                    centroids[i].x = new_x;
                    centroids[i].y = new_y;
                    converged = 0;
                }
            }
        }
        
        iteration_count++;
    }
    
    // Print final cluster assignments
    printf("\nFinal cluster assignments:\n");
    
    for (i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        
        for (j = 0; j < num_points; j++) {
            if (points[j].cluster == i) {
                printf("Point %d (%f, %f)\n", j, points[j].x, points[j].y);
            }
        }
    }
    
    return 0;
}