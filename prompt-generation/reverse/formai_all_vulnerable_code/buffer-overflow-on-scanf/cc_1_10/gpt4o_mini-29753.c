//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define MAX_ITERATIONS 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point centroid;
    int num_points;
    Point points[MAX_POINTS];
} Cluster;

double euclidean_distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.y - b.y) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void initialize_clusters(Cluster clusters[], int k, Point points[], int num_points) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[rand() % num_points]; // Randomly picking a point as a centroid
        clusters[i].num_points = 0;
    }
}

void assign_points_to_clusters(Point points[], int num_points, Cluster clusters[], int k) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int cluster_index = -1;

        for (int j = 0; j < k; j++) {
            double distance = euclidean_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }
        
        clusters[cluster_index].points[clusters[cluster_index].num_points++] = points[i];
    }
}

void update_centroids(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].num_points > 0) {
            double sum_x = 0, sum_y = 0;
            for (int j = 0; j < clusters[i].num_points; j++) {
                sum_x += clusters[i].points[j].x;
                sum_y += clusters[i].points[j].y;
            }
            clusters[i].centroid.x = sum_x / clusters[i].num_points;
            clusters[i].centroid.y = sum_y / clusters[i].num_points;
            clusters[i].num_points = 0; // Reset for the next iteration
        }
    }
}

void k_means(Point points[], int num_points, int k) {
    Cluster clusters[MAX_CLUSTERS];
    initialize_clusters(clusters, k, points, num_points);

    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        assign_points_to_clusters(points, num_points, clusters, k);
        update_centroids(clusters, k);
    }

    // Print the results
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: Centroid(%.2f, %.2f) -> Points: ", i + 1, clusters[i].centroid.x, clusters[i].centroid.y);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%.2f, %.2f) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

int main() {
    int num_points, k;

    printf("Enter the number of points: ");
    scanf("%d", &num_points);
    
    if (num_points > MAX_POINTS) {
        printf("Exceeded maximum number of points (%d)\n", MAX_POINTS);
        return 1;
    }

    Point points[MAX_POINTS];

    printf("Enter the points (x y):\n");
    for (int i = 0; i < num_points; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    printf("Enter the number of clusters: ");
    scanf("%d", &k);

    if (k > MAX_CLUSTERS) {
        printf("Exceeded maximum number of clusters (%d)\n", MAX_CLUSTERS);
        return 1;
    }

    srand(time(0));
    k_means(points, num_points, k);

    return 0;
}