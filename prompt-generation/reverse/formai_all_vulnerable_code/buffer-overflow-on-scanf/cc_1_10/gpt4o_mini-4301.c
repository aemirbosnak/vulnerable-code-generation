//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2

typedef struct {
    double coordinates[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    Point *points;
    int num_points;
} Cluster;

void init_clusters(Cluster *clusters, int k, Point *points) {
    for (int i = 0; i < k; i++) {
        // Initialize cluster centroids with random points
        clusters[i].centroid = points[rand() % MAX_POINTS];
        clusters[i].points = (Point *)malloc(MAX_POINTS * sizeof(Point));
        clusters[i].num_points = 0;
    }
}

double euclidean_distance(Point a, Point b) {
    double distance = 0;
    for (int i = 0; i < DIMENSIONS; i++) {
        distance += pow(a.coordinates[i] - b.coordinates[i], 2);
    }
    return sqrt(distance);
}

int assign_points_to_clusters(Point *points, Cluster *clusters, int k, int num_points) {
    int changes = 0;

    for (int i = 0; i < num_points; i++) {
        int closest_cluster = -1;
        double min_distance = INFINITY;

        for (int j = 0; j < k; j++) {
            double distance = euclidean_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster = j;
            }
        }

        // Add point to the closest cluster
        if (closest_cluster != -1) {
            clusters[closest_cluster].points[clusters[closest_cluster].num_points++] = points[i];
            changes++;
        }
    }
    return changes;
}

void update_centroids(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].num_points == 0) continue; // Avoid division by zero

        double sum[DIMENSIONS] = {0};
        for (int j = 0; j < clusters[i].num_points; j++) {
            for (int d = 0; d < DIMENSIONS; d++) {
                sum[d] += clusters[i].points[j].coordinates[d];
            }
        }

        for (int d = 0; d < DIMENSIONS; d++) {
            clusters[i].centroid.coordinates[d] = sum[d] / clusters[i].num_points;
        }
    }
}

void kmeans(Point *points, int num_points, int k) {
    Cluster clusters[MAX_CLUSTERS];
    init_clusters(clusters, k, points);

    int changed;
    do {
        // Reset points count for each cluster
        for (int i = 0; i < k; i++) {
            clusters[i].num_points = 0;
        }

        changed = assign_points_to_clusters(points, clusters, k, num_points);
        update_centroids(clusters, k);
    } while (changed > 0);

    // Output results
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("Point: (%.2f, %.2f)\n", clusters[i].points[j].coordinates[0], clusters[i].points[j].coordinates[1]);
        }
        printf("Centroid: (%.2f, %.2f)\n\n", clusters[i].centroid.coordinates[0], clusters[i].centroid.coordinates[1]);
        free(clusters[i].points);
    }
}

int main() {
    srand(time(NULL));

    Point points[MAX_POINTS];
    int num_points;

    printf("Enter number of points (max %d): ", MAX_POINTS);
    scanf("%d", &num_points);

    if (num_points > MAX_POINTS) {
        printf("Number of points exceeds maximum limit.\n");
        return 1;
    }

    printf("Enter points (format: x y):\n");
    for (int i = 0; i < num_points; i++) {
        scanf("%lf %lf", &points[i].coordinates[0], &points[i].coordinates[1]);
    }

    int k;
    printf("Enter number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &k);

    if (k <= 0 || k > MAX_CLUSTERS) {
        printf("Invalid number of clusters.\n");
        return 1;
    }

    kmeans(points, num_points, k);

    return 0;
}