//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: genius
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
    int point_count;
} Cluster;

float euclideanDistance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void initializeClusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        printf("Enter the coordinates for centroid %d (x y): ", i + 1);
        scanf("%f %f", &clusters[i].centroid.x, &clusters[i].centroid.y);
        clusters[i].point_count = 0; // Initialize point count
    }
}

void assignPointsToClusters(Point points[], int num_points, Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].point_count = 0; // Reset point count for clusters
    }
    for (int i = 0; i < num_points; i++) {
        float min_distance = INFINITY;
        int assigned_cluster = -1;
        for (int j = 0; j < k; j++) {
            float distance = euclideanDistance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                assigned_cluster = j;
            }
        }
        clusters[assigned_cluster].points[clusters[assigned_cluster].point_count++] = points[i];
    }
}

void updateCentroids(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].point_count == 0) continue; // Avoid division by zero
        float sum_x = 0;
        float sum_y = 0;
        for (int j = 0; j < clusters[i].point_count; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sum_x / clusters[i].point_count;
        clusters[i].centroid.y = sum_y / clusters[i].point_count;
    }
}

void printClusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        printf(" Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf(" Points:\n");
        for (int j = 0; j < clusters[i].point_count; j++) {
            printf("  (%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}

int main() {
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];
    int num_points, k, iterations = 100;

    printf("Enter the number of data points (max %d): ", MAX_POINTS);
    scanf("%d", &num_points);

    if (num_points > MAX_POINTS) {
        printf("Exceeded maximum number of points. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < num_points; i++) {
        printf("Enter point %d (x y): ", i + 1);
        scanf("%f %f", &points[i].x, &points[i].y);
    }

    printf("Enter number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &k);

    if (k > MAX_CLUSTERS) {
        printf("Exceeded maximum number of clusters. Exiting...\n");
        return 1;
    }

    initializeClusters(clusters, k);

    for (int i = 0; i < iterations; i++) {
        assignPointsToClusters(points, num_points, clusters, k);
        updateCentroids(clusters, k);
    }

    printClusters(clusters, k);
    
    return 0;
}