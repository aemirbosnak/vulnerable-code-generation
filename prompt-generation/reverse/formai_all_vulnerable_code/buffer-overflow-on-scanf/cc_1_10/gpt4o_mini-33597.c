//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_POINTS 100
#define DIMENSIONS 2
#define MAX_ITERATIONS 100
#define THRESHOLD 0.0001

typedef struct {
    double coords[DIMENSIONS];
} Point;

typedef struct {
    Point centroid;
    int count;
    Point *points[MAX_POINTS];
} Cluster;

double distance(Point *p1, Point *p2) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += pow(p1->coords[i] - p2->coords[i], 2);
    }
    return sqrt(sum);
}

void compute_centroid(Cluster *cluster) {
    for (int i = 0; i < DIMENSIONS; i++) {
        cluster->centroid.coords[i] = 0.0;
    }
    for (int i = 0; i < cluster->count; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            cluster->centroid.coords[j] += cluster->points[i]->coords[j];
        }
    }
    for (int i = 0; i < DIMENSIONS; i++) {
        cluster->centroid.coords[i] /= cluster->count;
    }
}

void kmeans(Point *points, int total_points, int k) {
    Cluster clusters[k];
    bool changed;

    // Random initialization of centroids
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[rand() % total_points];
        clusters[i].count = 0;
    }

    for (int iter = 0; iter < MAX_ITERATIONS; iter++) {
        changed = false;

        // Clear clusters
        for (int i = 0; i < k; i++) {
            clusters[i].count = 0;
        }

        // Assign points to the nearest centroid
        for (int i = 0; i < total_points; i++) {
            double min_distance = INFINITY;
            int cluster_index = 0;

            for (int j = 0; j < k; j++) {
                double dist = distance(&points[i], &clusters[j].centroid);
                if (dist < min_distance) {
                    min_distance = dist;
                    cluster_index = j;
                }
            }
            clusters[cluster_index].points[clusters[cluster_index].count++] = &points[i];

            // Check if centroid has changed
            if (min_distance > THRESHOLD) {
                changed = true;
            }
        }

        // Compute the new centroids
        for (int i = 0; i < k; i++) {
            compute_centroid(&clusters[i]);
        }

        // If no changes, exit
        if (!changed) break;
    }

    // Output clusters
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].count; j++) {
            printf("Point(%f, %f)\n", clusters[i].points[j]->coords[0], clusters[i].points[j]->coords[1]);
        }
        printf("Centroid(%f, %f)\n\n", clusters[i].centroid.coords[0], clusters[i].centroid.coords[1]);
    }
}

int main() {
    srand(time(NULL));

    Point points[MAX_POINTS];
    int total_points;

    printf("Enter the number of points (max %d): ", MAX_POINTS);
    scanf("%d", &total_points);

    if (total_points > MAX_POINTS) {
        printf("Exceeded maximum number of points.\n");
        return 1;
    }

    printf("Enter the points (x y format):\n");
    for (int i = 0; i < total_points; i++) {
        scanf("%lf %lf", &points[i].coords[0], &points[i].coords[1]);
    }

    int k;
    printf("Enter the number of clusters (k): ");
    scanf("%d", &k);

    kmeans(points, total_points, k);

    return 0;
}