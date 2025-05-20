//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_POINTS];
    int num_points;
} Cluster;

double euclidean_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void initialize_centroids(Cluster clusters[], int k, Point points[], int num_points) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[i * (num_points / k)];
        clusters[i].num_points = 0;
    }
}

void assign_points_to_clusters(Point points[], int num_points, Cluster clusters[], int k) {
    for (int i = 0; i < num_points; i++) {
        double min_dist = INFINITY;
        int cluster_index = 0;

        for (int j = 0; j < k; j++) {
            double dist = euclidean_distance(points[i], clusters[j].centroid);
            if (dist < min_dist) {
                min_dist = dist;
                cluster_index = j;
            }
        }
        clusters[cluster_index].points[clusters[cluster_index].num_points++] = points[i];
    }
}

void update_centroids(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        double sum_x = 0, sum_y = 0;
        for (int j = 0; j < clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        if (clusters[i].num_points > 0) {
            clusters[i].centroid.x = sum_x / clusters[i].num_points;
            clusters[i].centroid.y = sum_y / clusters[i].num_points;
        }
    }
}

int main() {
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];
    int num_points = 0;
    int k;

    FILE *file = fopen("points.txt", "r");
    if (!file) {
        fprintf(stderr, "Error opening file.\n");
        return EXIT_FAILURE;
    }

    while (fscanf(file, "%lf %lf", &points[num_points].x, &points[num_points].y) == 2 && num_points < MAX_POINTS) {
        num_points++;
    }
    fclose(file);

    printf("Enter number of clusters (k): ");
    scanf("%d", &k);
    if (k > MAX_CLUSTERS || k > num_points) {
        fprintf(stderr, "Invalid number of clusters.\n");
        return EXIT_FAILURE;
    }

    initialize_centroids(clusters, k, points, num_points);

    int changed;
    do {
        for (int i = 0; i < k; i++) {
            clusters[i].num_points = 0; // Reset points for clusters
        }
        assign_points_to_clusters(points, num_points, clusters, k);
        Point previous_centroids[MAX_CLUSTERS];

        for (int i = 0; i < k; i++) {
            previous_centroids[i] = clusters[i].centroid;
        }

        update_centroids(clusters, k);

        changed = 0;
        for (int i = 0; i < k; i++) {
            if (previous_centroids[i].x != clusters[i].centroid.x || previous_centroids[i].y != clusters[i].centroid.y) {
                changed = 1;
            }
        }
    } while (changed);

    // Display the results
    printf("\nFinal clusters:\n");
    for (int i = 0; i < k; i++) {
        printf("Cluster %d centroid: (%.2f, %.2f)\n", i + 1, clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points in this cluster:\n");
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("  (%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}