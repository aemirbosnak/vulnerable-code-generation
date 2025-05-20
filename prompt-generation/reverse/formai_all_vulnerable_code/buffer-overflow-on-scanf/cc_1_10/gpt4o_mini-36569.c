//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: portable
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
    Point points[MAX_POINTS];
    int num_points;
} Cluster;

void initialize_clusters(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].num_points = 0;
        for (int j = 0; j < DIMENSIONS; j++) {
            clusters[i].centroid.coordinates[j] = (double)rand() / RAND_MAX; // Random initialization
        }
    }
}

double calculate_distance(Point a, Point b) {
    double sum = 0.0;
    for (int j = 0; j < DIMENSIONS; j++) {
        sum += (a.coordinates[j] - b.coordinates[j]) * (a.coordinates[j] - b.coordinates[j]);
    }
    return sqrt(sum);
}

int assign_to_closest_cluster(Point point, Cluster clusters[], int k) {
    double min_distance = INFINITY;
    int cluster_index = -1;

    for (int i = 0; i < k; i++) {
        double distance = calculate_distance(point, clusters[i].centroid);
        if (distance < min_distance) {
            min_distance = distance;
            cluster_index = i;
        }
    }
    return cluster_index;
}

void update_centroids(Cluster clusters[], int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].num_points > 0) {
            for (int j = 0; j < DIMENSIONS; j++) {
                clusters[i].centroid.coordinates[j] = 0.0; // Reset centroid
            }

            for (int j = 0; j < clusters[i].num_points; j++) {
                for (int d = 0; d < DIMENSIONS; d++) {
                    clusters[i].centroid.coordinates[d] += clusters[i].points[j].coordinates[d];
                }
            }

            for (int d = 0; d < DIMENSIONS; d++) {
                clusters[i].centroid.coordinates[d] /= clusters[i].num_points; // Calculate mean
            }
        }
    }
}

int main() {
    int num_points, num_clusters;
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];
    
    printf("Enter the number of points: ");
    scanf("%d", &num_points);
    if (num_points > MAX_POINTS) {
        printf("Maximum allowed points is %d\n", MAX_POINTS);
        return 1;
    }
    
    printf("Enter the points (format: x y):\n");
    for (int i = 0; i < num_points; i++) {
        scanf("%lf %lf", &points[i].coordinates[0], &points[i].coordinates[1]);
    }

    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);
    if (num_clusters > MAX_CLUSTERS) {
        printf("Maximum allowed clusters is %d\n", MAX_CLUSTERS);
        return 1;
    }

    srand(time(NULL)); // Seed for random number generation
    initialize_clusters(clusters, num_clusters);
    
    int changed;
    do {
        // Reset points in each cluster
        for (int i = 0; i < num_clusters; i++) {
            clusters[i].num_points = 0;
        }

        // Assign points to the closest cluster
        for (int i = 0; i < num_points; i++) {
            int cluster_index = assign_to_closest_cluster(points[i], clusters, num_clusters);
            clusters[cluster_index].points[clusters[cluster_index].num_points++] = points[i];
        }

        // Store the current centroids to check for convergence
        Point previous_centroids[MAX_CLUSTERS];
        for (int i = 0; i < num_clusters; i++) {
            previous_centroids[i] = clusters[i].centroid;
        }

        // Update centroids of the clusters
        update_centroids(clusters, num_clusters);

        // Check if centroids have changed
        changed = 0;
        for (int i = 0; i < num_clusters; i++) {
            if (calculate_distance(previous_centroids[i], clusters[i].centroid) > 1e-6) {
                changed = 1;
                break;
            }
        }
    } while (changed);

    // Output the final clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("Centroid: (%.2f, %.2f)\n", clusters[i].centroid.coordinates[0], clusters[i].centroid.coordinates[1]);
        printf("Points:\n");
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("    (%.2f, %.2f)\n", clusters[i].points[j].coordinates[0], clusters[i].points[j].coordinates[1]);
        }
        printf("\n");
    }

    return 0;
}