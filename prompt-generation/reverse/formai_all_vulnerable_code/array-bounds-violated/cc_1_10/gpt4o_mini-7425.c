//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2
#define MAX_ITERATIONS 100

typedef struct {
    double coords[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    Point points[MAX_POINTS];
    int point_count;
} Cluster;

double distance(Point a, Point b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += pow(a.coords[i] - b.coords[i], 2);
    }
    return sqrt(sum);
}

void assign_clusters(Point points[], int point_count, Cluster clusters[], int cluster_count) {
    for (int i = 0; i < point_count; i++) {
        double min_dist = INFINITY;
        int cluster_index = -1;

        for (int j = 0; j < cluster_count; j++) {
            double dist = distance(points[i], clusters[j].centroid);
            if (dist < min_dist) {
                min_dist = dist;
                cluster_index = j;
            }
        }
        clusters[cluster_index].points[clusters[cluster_index].point_count++] = points[i];
    }
}

void update_centroids(Cluster clusters[], int cluster_count) {
    for (int i = 0; i < cluster_count; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i].centroid.coords[j] = 0;
        }
        for (int j = 0; j < clusters[i].point_count; j++) {
            for (int k = 0; k < DIMENSIONS; k++) {
                clusters[i].centroid.coords[k] += clusters[i].points[j].coords[k];
            }
        }
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i].centroid.coords[j] /= clusters[i].point_count;
        }
    }
}

int clusters_changed(Cluster old_clusters[], Cluster new_clusters[], int cluster_count) {
    for (int i = 0; i < cluster_count; i++) {
        if (distance(old_clusters[i].centroid, new_clusters[i].centroid) != 0.0) {
            return 1; // Clusters have changed
        }
    }
    return 0; // No change
}

void print_clusters(Cluster clusters[], int cluster_count) {
    for (int i = 0; i < cluster_count; i++) {
        printf("Cluster %d:\n", i + 1);
        printf(" Centroid: (");
        for (int j = 0; j < DIMENSIONS; j++) {
            printf("%f", clusters[i].centroid.coords[j]);
            if (j < DIMENSIONS - 1) printf(", ");
        }
        printf(")\n Points:\n");
        for (int j = 0; j < clusters[i].point_count; j++) {
            printf("  (");
            for (int k = 0; k < DIMENSIONS; k++) {
                printf("%f", clusters[i].points[j].coords[k]);
                if (k < DIMENSIONS - 1) printf(", ");
            }
            printf(")\n");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int point_count, cluster_count;
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];

    printf("Enter number of points (max %d): ", MAX_POINTS);
    scanf("%d", &point_count);
    if (point_count > MAX_POINTS) {
        printf("Too many points! Limiting to %d.\n", MAX_POINTS);
        point_count = MAX_POINTS;
    }

    printf("Enter number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &cluster_count);
    if (cluster_count > MAX_CLUSTERS) {
        printf("Too many clusters! Limiting to %d.\n", MAX_CLUSTERS);
        cluster_count = MAX_CLUSTERS;
    }

    printf("Enter points (x y) one by one:\n");
    for (int i = 0; i < point_count; i++) {
        printf("Point %d: ", i + 1);
        scanf("%lf %lf", &points[i].coords[0], &points[i].coords[1]);
    }

    for (int i = 0; i < cluster_count; i++) {
        clusters[i].centroid = points[rand() % point_count]; // Randomly initialize centroids
        clusters[i].point_count = 0;
    }

    for (int iter = 0; iter < MAX_ITERATIONS; iter++) {
        for (int j = 0; j < cluster_count; j++) {
            clusters[j].point_count = 0; // Reset points
        }

        assign_clusters(points, point_count, clusters, cluster_count);
        Cluster old_clusters[MAX_CLUSTERS] = {0};
        for (int j = 0; j < cluster_count; j++) {
            old_clusters[j] = clusters[j]; // Store the old clusters
        }

        update_centroids(clusters, cluster_count);

        if (!clusters_changed(old_clusters, clusters, cluster_count)) {
            printf("Clusters stabilized after %d iterations.\n", iter + 1);
            break;
        }
    }
    print_clusters(clusters, cluster_count);
    return 0;
}