//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point center;
    Point points[MAX_POINTS];
    int point_count;
} Cluster;

Cluster clusters[MAX_CLUSTERS];
int k; // number of clusters
int iterations;

double calculate_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void initialize_clusters(Point* data, int n) {
    for (int i = 0; i < k; i++) {
        clusters[i].center = data[rand() % n];
        clusters[i].point_count = 0;
    }
}

void assign_points_to_clusters(Point* data, int n) {
    for (int i = 0; i < k; i++) {
        clusters[i].point_count = 0;
    }

    for (int i = 0; i < n; i++) {
        double min_distance = DBL_MAX;
        int cluster_index = -1;

        for (int j = 0; j < k; j++) {
            double distance = calculate_distance(data[i], clusters[j].center);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }
        
        clusters[cluster_index].points[clusters[cluster_index].point_count++] = data[i];
    }
}

void update_cluster_centers() {
    for (int i = 0; i < k; i++) {
        double sum_x = 0, sum_y = 0;
        for (int j = 0; j < clusters[i].point_count; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }

        if (clusters[i].point_count > 0) {
            clusters[i].center.x = sum_x / clusters[i].point_count;
            clusters[i].center.y = sum_y / clusters[i].point_count;
        }
    }
}

void kmeans(Point* data, int n) {
    initialize_clusters(data, n);

    for (iterations = 0; iterations < 100; iterations++) {
        assign_points_to_clusters(data, n);
        update_cluster_centers();
        
        // Check for convergence, i.e., if centers have not changed
        int converged = 1;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < clusters[i].point_count; j++) {
                if (calculate_distance(clusters[i].center, clusters[i].points[j]) > 1e-5) {
                    converged = 0;
                    break;
                }
            }
        }
        if (converged) break; // Stop if converged
    }
}

void print_clusters() {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("Center: (%.2f, %.2f)\n", clusters[i].center.x, clusters[i].center.y);
        printf("Points:\n");
        for (int j = 0; j < clusters[i].point_count; j++) {
            printf("  (%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0)); // Seed the random number generator

    Point data[MAX_POINTS];
    int n = 0;

    // Example data points
    data[n++] = (Point){2.0, 3.0};
    data[n++] = (Point){3.0, 4.0};
    data[n++] = (Point){5.0, 6.0};
    data[n++] = (Point){8.0, 8.0};
    data[n++] = (Point){12.0, 10.0};
    data[n++] = (Point){15.0, 12.0};
    data[n++] = (Point){14.0, 14.0};
    
    // Define number of clusters
    printf("Enter the number of clusters (k): ");
    scanf("%d", &k);

    // Run K-Means algorithm
    kmeans(data, n);
    
    // Print the clusters
    print_clusters();

    return 0;
}