//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_POINTS];
    int num_points;
} Cluster;

// Function to calculate the Euclidean distance between two points
float distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.y - b.y) * (a.x - b.x) * (a.y - b.y));
}

// Function to initialize clusters with random points
void initialize_clusters(Cluster clusters[], int k, Point points[], int num_points) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[rand() % num_points];
        clusters[i].num_points = 0;
    }
}

// Function to assign points to the nearest centroid
void assign_points_to_clusters(Cluster clusters[], int k, Point points[], int num_points) {
    for (int i = 0; i < k; i++) {
        clusters[i].num_points = 0;
    }

    for (int i = 0; i < num_points; i++) {
        int best_cluster = 0;
        float best_distance = distance(points[i], clusters[0].centroid);

        for (int j = 1; j < k; j++) {
            float dist = distance(points[i], clusters[j].centroid);
            if (dist < best_distance) {
                best_distance = dist;
                best_cluster = j;
            }
        }

        clusters[best_cluster].points[clusters[best_cluster].num_points++] = points[i];
    }
}

// Function to update the centroids of each cluster
void update_centroids(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].num_points > 0) {
            float sum_x = 0;
            float sum_y = 0;
            for (int j = 0; j < clusters[i].num_points; j++) {
                sum_x += clusters[i].points[j].x;
                sum_y += clusters[i].points[j].y;
            }
            clusters[i].centroid.x = sum_x / clusters[i].num_points;
            clusters[i].centroid.y = sum_y / clusters[i].num_points;
        }
    }
}

// Function to check if centroids have changed
int centroids_changed(Cluster old_clusters[], Cluster new_clusters[], int k) {
    for (int i = 0; i < k; i++) {
        if (old_clusters[i].centroid.x != new_clusters[i].centroid.x || 
            old_clusters[i].centroid.y != new_clusters[i].centroid.y) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    int k; // Number of clusters
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];

    // Sample input for points
    int num_points = 10;
    points[0] = (Point){1.0, 2.0};
    points[1] = (Point){1.5, 1.8};
    points[2] = (Point){5.0, 8.0};
    points[3] = (Point){8.0, 8.0};
    points[4] = (Point){1.0, 0.6};
    points[5] = (Point){9.0, 11.0};
    points[6] = (Point){8.0, 2.0};
    points[7] = (Point){10.0, 2.0};
    points[8] = (Point){9.0, 3.0};
    points[9] = (Point){3.0, 3.0};

    printf("Enter the number of clusters (k): ");
    scanf("%d", &k);

    // Initialize clusters
    initialize_clusters(clusters, k, points, num_points);

    Cluster old_clusters[MAX_CLUSTERS];

    // Main K-means loop
    do {
        for (int i = 0; i < k; i++) {
            old_clusters[i] = clusters[i];  // Save old centroids
        }
        
        assign_points_to_clusters(clusters, k, points, num_points);
        update_centroids(clusters, k);
        
    } while (centroids_changed(old_clusters, clusters, k));

    // Output the clusters
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("Centroid at (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points in this cluster:\n");
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    return 0;
}