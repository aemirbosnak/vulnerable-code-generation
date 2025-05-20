//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2

typedef struct {
    double coords[DIMENSIONS];
} Point;

typedef struct {
    Point center;
    int num_points;
    Point points[MAX_POINTS];
} Cluster;

double euclidean_distance(Point a, Point b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += (a.coords[i] - b.coords[i]) * (a.coords[i] - b.coords[i]);
    }
    return sqrt(sum);
}

void calculate_new_centers(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i].center.coords[j] = 0.0;
        }
        clusters[i].num_points = 0;
    }

    // Accumulate points into clusters
    for (int i = 0; i < MAX_POINTS; i++) {
        int cluster_index = -1;
        double min_distance = INFINITY;
        for (int j = 0; j < k; j++) {
            double distance = euclidean_distance(clusters[j].center, clusters[j].points[i]);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }
        
        // Add point to the closest cluster
        if (cluster_index != -1) {
            clusters[cluster_index].points[clusters[cluster_index].num_points++] = clusters[cluster_index].points[i];
            for (int j = 0; j < DIMENSIONS; j++) {
                clusters[cluster_index].center.coords[j] += clusters[cluster_index].points[clusters[cluster_index].num_points - 1].coords[j];
            }
        }
    }

    // Calculate new centers
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            if (clusters[i].num_points > 0)
                clusters[i].center.coords[j] /= clusters[i].num_points;
        }
    }
}

void print_clusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("Center: (");
        for (int j = 0; j < DIMENSIONS; j++) {
            printf("%lf", clusters[i].center.coords[j]);
            if (j < DIMENSIONS - 1) printf(", ");
        }
        printf(")\nPoints:\n");
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("  (");
            for (int d = 0; d < DIMENSIONS; d++) {
                printf("%lf", clusters[i].points[j].coords[d]);
                if (d < DIMENSIONS - 1) printf(", ");
            }
            printf(")\n");
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    int k;
    printf("Enter the number of clusters (1 to %d): ", MAX_CLUSTERS);
    scanf("%d", &k);
    if (k < 1 || k > MAX_CLUSTERS) {
        printf("Invalid number of clusters.\n");
        return 1;
    }

    Cluster clusters[MAX_CLUSTERS];

    // Initial random centers
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i].center.coords[j] = (double)(rand() % 100);
        }
    }

    // Generate random points
    for (int i = 0; i < MAX_POINTS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i].points[i].coords[j] = (double)(rand() % 100);
        }
    }

    // K-Means Algorithm
    for (int iter = 0; iter < 10; iter++) {
        calculate_new_centers(clusters, k);
    }

    print_clusters(clusters, k);
    return 0;
}