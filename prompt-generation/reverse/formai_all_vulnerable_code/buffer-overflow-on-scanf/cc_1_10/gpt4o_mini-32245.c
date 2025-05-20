//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_POINTS];
    int point_count;
} Cluster;

void initialize_clusters(Cluster clusters[], int k, Point points[], int point_count) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[i * (point_count / k)]; // Simple initialization
        clusters[i].point_count = 0;
    }
}

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int assign_point_to_cluster(Point point, Cluster clusters[], int k) {
    int closest = 0;
    double min_distance = distance(point, clusters[0].centroid);
    
    for (int i = 1; i < k; i++) {
        double dist = distance(point, clusters[i].centroid);
        if (dist < min_distance) {
            min_distance = dist;
            closest = i;
        }
    }
    return closest;
}

void update_clusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].point_count == 0) continue;
        
        double sum_x = 0.0, sum_y = 0.0;
        for (int j = 0; j < clusters[i].point_count; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sum_x / clusters[i].point_count;
        clusters[i].centroid.y = sum_y / clusters[i].point_count;
        clusters[i].point_count = 0; // Reset for the next iteration
    }
}

int main() {
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];
    int point_count, k;

    printf("Enter number of points (max %d): ", MAX_POINTS);
    scanf("%d", &point_count);
    
    if (point_count > MAX_POINTS || point_count <= 0) {
        printf("Invalid number of points.\n");
        return 1;
    }

    printf("Enter the points (x y):\n");
    for (int i = 0; i < point_count; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    printf("Enter number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &k);
    
    if (k > MAX_CLUSTERS || k <= 0 || k > point_count) {
        printf("Invalid number of clusters.\n");
        return 1;
    }

    initialize_clusters(clusters, k, points, point_count);

    int change_occurred;
    do {
        change_occurred = 0;

        // Assign each point to the closest cluster
        for (int i = 0; i < point_count; i++) {
            int cluster_index = assign_point_to_cluster(points[i], clusters, k);
            clusters[cluster_index].points[clusters[cluster_index].point_count] = points[i];
            clusters[cluster_index].point_count++;
        }

        // Update cluster centroids
        for (int i = 0; i < k; i++) {
            Point old_centroid = clusters[i].centroid;
            update_clusters(clusters, k);
            if (old_centroid.x != clusters[i].centroid.x || old_centroid.y != clusters[i].centroid.y) {
                change_occurred = 1;
            }
        }

    } while (change_occurred);

    // Display cluster centroids and their points
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: Centroid(%.2f, %.2f) - Points:\n", i, clusters[i].centroid.x, clusters[i].centroid.y);
        for (int j = 0; j < clusters[i].point_count; j++) {
            printf("    (%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }

    return 0;
}