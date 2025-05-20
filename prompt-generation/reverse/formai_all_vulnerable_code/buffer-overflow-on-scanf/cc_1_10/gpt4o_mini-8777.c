//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 5
#define DIMENSIONS 2

typedef struct {
    double coordinates[DIMENSIONS];
    int cluster_id;
} Point;

typedef struct {
    double centroid[DIMENSIONS];
    int num_points;
} Cluster;

void init_points(Point points[], int num_points);
void init_clusters(Cluster clusters[], int num_clusters);
void assign_clusters(Point points[], Cluster clusters[], int num_points, int num_clusters);
void update_centroids(Point points[], Cluster clusters[], int num_points, int num_clusters);
double distance(Point p, Cluster c);
void print_results(Point points[], int num_points, Cluster clusters[], int num_clusters);

int main() {
    int num_points, num_clusters;

    printf("Enter the number of points (max %d): ", MAX_POINTS);
    scanf("%d", &num_points);

    if (num_points > MAX_POINTS) {
        printf("Too many points! Limiting to %d.\n", MAX_POINTS);
        num_points = MAX_POINTS;
    }

    printf("Enter the number of clusters (max %d): ", MAX_CLUSTERS);
    scanf("%d", &num_clusters);

    if (num_clusters > MAX_CLUSTERS) {
        printf("Too many clusters! Limiting to %d.\n", MAX_CLUSTERS);
        num_clusters = MAX_CLUSTERS;
    }

    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];

    init_points(points, num_points);
    init_clusters(clusters, num_clusters);

    int iterations = 0;
    int changed;

    do {
        assign_clusters(points, clusters, num_points, num_clusters);
        update_centroids(points, clusters, num_points, num_clusters);
        iterations++;
        
        changed = 0; // Reset change flag
        for (int i = 0; i < num_points; i++) {
            int new_cluster = points[i].cluster_id;
            if (points[i].cluster_id != new_cluster) {
                changed++;
            }
        }
    } while (changed > 0 && iterations < 100);

    printf("\nClustering complete after %d iterations!\n", iterations);
    print_results(points, num_points, clusters, num_clusters);

    return 0;
}

void init_points(Point points[], int num_points) {
    printf("Please enter the coordinates (x y) for each point:\n");
    for (int i = 0; i < num_points; i++) {
        printf("Point %d: ", i + 1);
        scanf("%lf %lf", &points[i].coordinates[0], &points[i].coordinates[1]);
        points[i].cluster_id = -1; // Initially unassigned
    }
}

void init_clusters(Cluster clusters[], int num_clusters) {
    printf("Initializing cluster centroids...\n");
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid[0] = rand() % 100; // Random x
        clusters[i].centroid[1] = rand() % 100; // Random y
        clusters[i].num_points = 0;
        printf("Cluster %d initialized at (%f, %f)\n", i + 1, clusters[i].centroid[0], clusters[i].centroid[1]);
    }
}

void assign_clusters(Point points[], Cluster clusters[], int num_points, int num_clusters) {
    for (int i = 0; i < num_points; i++) {
        double min_dist = INFINITY;
        for (int j = 0; j < num_clusters; j++) {
            double dist = distance(points[i], clusters[j]);
            if (dist < min_dist) {
                min_dist = dist;
                points[i].cluster_id = j; // Assign new cluster
            }
        }
    }
}

void update_centroids(Point points[], Cluster clusters[], int num_points, int num_clusters) {
    for (int j = 0; j < num_clusters; j++) {
        clusters[j].centroid[0] = 0;
        clusters[j].centroid[1] = 0;
        clusters[j].num_points = 0;
    }

    for (int i = 0; i < num_points; i++) {
        int cluster_id = points[i].cluster_id;
        clusters[cluster_id].centroid[0] += points[i].coordinates[0];
        clusters[cluster_id].centroid[1] += points[i].coordinates[1];
        clusters[cluster_id].num_points++;
    }

    for (int j = 0; j < num_clusters; j++) {
        if (clusters[j].num_points > 0) {
            clusters[j].centroid[0] /= clusters[j].num_points;
            clusters[j].centroid[1] /= clusters[j].num_points;
        }
    }
}

double distance(Point p, Cluster c) {
    return sqrt(pow(c.centroid[0] - p.coordinates[0], 2) + pow(c.centroid[1] - p.coordinates[1], 2));
}

void print_results(Point points[], int num_points, Cluster clusters[], int num_clusters) {
    for (int j = 0; j < num_clusters; j++) {
        printf("Cluster %d centroid: (%f, %f)\n", j + 1, clusters[j].centroid[0], clusters[j].centroid[1]);
    }

    printf("\nPoints assigned to clusters:\n");
    for (int i = 0; i < num_points; i++) {
        printf("Point (%f, %f) is in Cluster %d\n", points[i].coordinates[0], points[i].coordinates[1], points[i].cluster_id + 1);
    }
}