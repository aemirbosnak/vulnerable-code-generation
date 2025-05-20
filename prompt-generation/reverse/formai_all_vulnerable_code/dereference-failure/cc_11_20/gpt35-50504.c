//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 1000
#define EPSILON 0.0001

struct point {
    float x;
    float y;
    int cluster; // Cluster number
};

int main() {
    // Generate random points
    int num_points = 50;
    struct point *points = (struct point*) malloc(num_points*sizeof(struct point));
    
    srand(time(NULL));
    for (int i = 0; i < num_points; i++) {
        points[i].x = (float) rand()/RAND_MAX;
        points[i].y = (float) rand()/RAND_MAX;
        points[i].cluster = -1;
    }
    
    // Initialize centroids
    int num_clusters = 3;
    struct point *centroids = (struct point*) malloc(num_clusters*sizeof(struct point));
    for (int i = 0; i < num_clusters; i++) {
        centroids[i].x = (float) rand()/RAND_MAX;
        centroids[i].y = (float) rand()/RAND_MAX;
    }
    
    // Run K-Means Clustering Algorithm
    int iter = 0;
    float prev_cost = INFINITY;
    while (iter < MAX_ITER) {
        // Assign points to nearest centroid
        for (int i = 0; i < num_points; i++) {
            float min_dist = INFINITY;
            int min_cluster = -1;
            for (int j = 0; j < num_clusters; j++) {
                float dist = sqrt(pow(points[i].x-centroids[j].x, 2) + pow(points[i].y-centroids[j].y, 2));
                if (dist < min_dist) {
                    min_dist = dist;
                    min_cluster = j;
                }
            }
            points[i].cluster = min_cluster;
        }
        
        // Update centroids
        for (int i = 0; i < num_clusters; i++) {
            int count = 0;
            float sum_x = 0;
            float sum_y = 0;
            for (int j = 0; j < num_points; j++) {
                if (points[j].cluster == i) {
                    count++;
                    sum_x += points[j].x;
                    sum_y += points[j].y;
                }
            }
            if (count > 0) {
                centroids[i].x = sum_x/count;
                centroids[i].y = sum_y/count;
            }
        }
        
        // Compute cost
        float cost = 0;
        for (int i = 0; i < num_points; i++) {
            cost += sqrt(pow(points[i].x-centroids[points[i].cluster].x, 2) + pow(points[i].y-centroids[points[i].cluster].y, 2));
        }
        printf("Cost: %f\n", cost);
        
        // Check for convergence
        if (abs(prev_cost-cost) < EPSILON) {
            printf("Converged after %d iterations!\n", iter);
            break;
        }
        prev_cost = cost;
        iter++;
    }
    
    // Print final clusters
    printf("Final Clusters:\n");
    for (int i = 0; i < num_points; i++) {
        printf("Point (%f, %f) Cluster: %d\n", points[i].x, points[i].y, points[i].cluster);
    }
    
    free(points);
    free(centroids);
    return 0;
}