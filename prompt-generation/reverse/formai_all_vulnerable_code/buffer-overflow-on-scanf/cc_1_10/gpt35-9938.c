//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ITERATIONS 100 // maximum number of iterations for convergence
#define EPSILON 0.0001 // threshold for detecting convergence

typedef struct {
    double x;
    double y;
    int cluster;
} point;

typedef struct {
    double x;
    double y;
    int size;
    point *points;
} cluster;

double distance(point *p1, point *p2) {
    return sqrt((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
}

void init_clusters(cluster *clusters, point *points, int num_points, int k) {
    // randomly assign initial clusters
    for (int i = 0; i < num_points; i++) {
        points[i].cluster = rand() % k;
        clusters[points[i].cluster].points[clusters[points[i].cluster].size++] = points[i];
    }
    
    // calculate initial cluster center positions
    for (int c = 0; c < k; c++) {
        double x_sum = 0, y_sum = 0;
        for (int i = 0; i < clusters[c].size; i++) {
            x_sum += clusters[c].points[i].x;
            y_sum += clusters[c].points[i].y;
        }
        clusters[c].x = x_sum / clusters[c].size;
        clusters[c].y = y_sum / clusters[c].size;
    }
}

void kmeans(cluster *clusters, point *points, int num_points, int k) {
    // initialize clusters with random initial assignments
    init_clusters(clusters, points, num_points, k);
    
    // repeat clustering process until convergence or maximum iterations reached
    int iteration = 0;
    while (iteration < ITERATIONS) {
        int changed = 0; // flag for whether any points changed clusters
        
        // assign each point to its closest cluster
        for (int i = 0; i < num_points; i++) {
            double closest_dist = INFINITY;
            int closest_cluster = points[i].cluster;
            for (int c = 0; c < k; c++) {
                double dist = distance(&points[i], &clusters[c].points[0]);
                if (dist < closest_dist) {
                    closest_dist = dist;
                    closest_cluster = c;
                }
            }
            if (points[i].cluster != closest_cluster) {
                changed = 1;
                points[i].cluster = closest_cluster;
            }
            clusters[closest_cluster].points[clusters[closest_cluster].size++] = points[i];
        }
        
        // if no points changed clusters, the algorithm has converged
        if (!changed) {
            break;
        }
        
        // recalculate cluster center positions
        for (int c = 0; c < k; c++) {
            double x_sum = 0, y_sum = 0;
            for (int i = 0; i < clusters[c].size; i++) {
                x_sum += clusters[c].points[i].x;
                y_sum += clusters[c].points[i].y;
            }
            double new_x = x_sum / clusters[c].size;
            double new_y = y_sum / clusters[c].size;
            double delta_x = new_x - clusters[c].x;
            double delta_y = new_y - clusters[c].y;
            if (delta_x * delta_x + delta_y * delta_y < EPSILON) {
                // cluster center has converged
                break;
            }
            clusters[c].x = new_x;
            clusters[c].y = new_y;
        }
        
        // clear points from old clusters
        for (int c = 0; c < k; c++) {
            clusters[c].size = 0;
        }
        
        iteration++;
    }
    
    // print final cluster assignments
    printf("Final cluster assignments:\n");
    for (int i = 0; i < num_points; i++) {
        printf("(%f, %f) -> Cluster %d\n", points[i].x, points[i].y, points[i].cluster);
    }
}

int main() {
    int num_points, k;
    printf("Enter number of points: ");
    scanf("%d", &num_points);
    printf("Enter number of clusters: ");
    scanf("%d", &k);
    
    // initialize points with random positions
    point *points = malloc(num_points * sizeof(point));
    for (int i = 0; i < num_points; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
    
    // initialize clusters
    cluster *clusters = malloc(k * sizeof(cluster));
    for (int c = 0; c < k; c++) {
        clusters[c].x = 0;
        clusters[c].y = 0;
        clusters[c].size = 0;
        clusters[c].points = malloc(num_points * sizeof(point));
    }
    
    // run kmeans clustering algorithm
    kmeans(clusters, points, num_points, k);
    
    // cleanup
    for (int c = 0; c < k; c++) {
        free(clusters[c].points);
    }
    free(clusters);
    free(points);
    
    return 0;
}