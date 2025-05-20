//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.0001 // define epsilon for threshold value

typedef struct point { // define point struct
    double x, y;
} point;

double distance(point a, point b) { // calculate distance between two points
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int n; // number of points
    printf("Enter number of points: ");
    scanf("%d", &n);
    point points[n]; // array of points
    
    // input coordinates of each point
    for (int i = 0; i < n; i++) {
        printf("Enter coordinates for point %d: ", i+1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    
    int cluster_id = 0; // initialize cluster ID to zero
    int cluster_assignment[n]; // array to store cluster assignments
    
    // iterate over each point
    for (int i = 0; i < n; i++) {
        if (cluster_assignment[i] != 0) continue; // if already assigned to a cluster, skip
        
        cluster_id++; // increment cluster ID
        cluster_assignment[i] = cluster_id; // assign point to new cluster
        
        // iterate over each remaining point
        for (int j = i+1; j < n; j++) {
            if (cluster_assignment[j] != 0) continue; // if already assigned to a cluster, skip
            
            double dist = distance(points[i], points[j]); // calculate distance between points
            
            if (dist < EPSILON) { // if within threshold distance
                cluster_assignment[j] = cluster_id; // assign point to same cluster as i
            }
        }
    }
    
    // print cluster assignments for each point
    printf("\nCluster assignments:\n");
    for (int i = 0; i < n; i++) {
        printf("Point %d assigned to cluster %d\n", i+1, cluster_assignment[i]);
    }
    
    return 0; // program executed successfully
}