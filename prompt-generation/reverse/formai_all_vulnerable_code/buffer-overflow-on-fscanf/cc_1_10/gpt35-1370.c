//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: random
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define N 1000

// Define struct for holding point information
typedef struct {
    double x;
    double y;
} point_t;

// Define struct for holding cluster information
typedef struct {
    point_t center;
    point_t *points;
    int num_points;
} cluster_t;

// Define function to calculate distance between two points
double distance(point_t p1, point_t p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Define function to initialize clusters with random centers
void init_clusters(cluster_t *clusters, int k, point_t *points, int num_points) {
    for (int i = 0; i < k; i++) {
        clusters[i].center.x = points[rand() % num_points].x;
        clusters[i].center.y = points[rand() % num_points].y;
        clusters[i].points = malloc(sizeof(point_t) * N);
        clusters[i].num_points = 0;
    }
}

// Define function to assign points to closest cluster
void assign_points(cluster_t *clusters, int k, point_t *points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        double min_dist = INFINITY;
        int closest_cluster = 0;
        
        for (int j = 0; j < k; j++) {
            double dist = distance(points[i], clusters[j].center);
            
            if (dist < min_dist) {
                min_dist = dist;
                closest_cluster = j;
            }
        }
        
        clusters[closest_cluster].points[clusters[closest_cluster].num_points++] = points[i];
    }
}

// Define function to recompute cluster centers
void recompute_centers(cluster_t *clusters, int k) {
    for (int i = 0; i < k; i++) {
        double sum_x = 0, sum_y = 0;
        
        for (int j = 0; j < clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        
        if (clusters[i].num_points > 0) {
            clusters[i].center.x = sum_x / clusters[i].num_points;
            clusters[i].center.y = sum_y / clusters[i].num_points;
        }
    }
}

// Define function to print cluster information
void print_clusters(cluster_t *clusters, int k) {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d\n", i + 1);
        printf("Center: (%.2f, %.2f)\n", clusters[i].center.x, clusters[i].center.y);
        
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("Point %d: (%.2f, %.2f)\n", j + 1, clusters[i].points[j].x, clusters[i].points[j].y);
        }
        
        printf("\n");
    }
}

int main() {
    point_t points[N];
    int num_points = 0;
    int k = 0;
    
    // Read in point data
    FILE *file = fopen("points.txt", "r");
    
    if (file) {
        while (fscanf(file, "%lf,%lf", &points[num_points].x, &points[num_points].y) == 2) {
            num_points++;
        }
    } else {
        printf("Error: could not open points.txt\n");
        return 1;
    }
    
    fclose(file);
    
    // Read in number of clusters
    printf("Enter the number of clusters: ");
    scanf("%d", &k);
    
    // Initialize clusters
    cluster_t clusters[k];
    init_clusters(clusters, k, points, num_points);
    
    // Perform k-means clustering
    bool converged = false;
    int iter = 1;
    
    while (!converged && iter <= 100) {
        printf("Iteration %d\n", iter);
        assign_points(clusters, k, points, num_points);
        recompute_centers(clusters, k);
        print_clusters(clusters, k);
        iter++;
    }
    
    return 0;
}