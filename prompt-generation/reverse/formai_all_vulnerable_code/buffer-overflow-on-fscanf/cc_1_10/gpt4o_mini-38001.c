//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2

typedef struct {
    double coords[DIMENSIONS];
    int cluster;
} Point;

typedef struct {
    double centroid[DIMENSIONS];
    int size;
} Cluster;

void load_data(const char *filename, Point points[], int *num_points) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    *num_points = 0;
    while (fscanf(file, "%lf,%lf\n", &points[*num_points].coords[0], &points[*num_points].coords[1]) == 2) {
        points[*num_points].cluster = -1; // unassigned
        (*num_points)++;
    }

    fclose(file);
}

double euclidean_distance(const Point *a, const Cluster *b) {
    double sum = 0.0;
    for (int i = 0; i < DIMENSIONS; i++) {
        sum += pow(a->coords[i] - b->centroid[i], 2);
    }
    return sqrt(sum);
}

void initialize_clusters(Cluster clusters[], int k, Point points[], int num_points) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid[0] = points[rand() % num_points].coords[0];
        clusters[i].centroid[1] = points[rand() % num_points].coords[1];
        clusters[i].size = 0;
    }
}

void assign_clusters(Point points[], Cluster clusters[], int num_points, int k) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int cluster_index = -1;

        for (int j = 0; j < k; j++) {
            double distance = euclidean_distance(&points[i], &clusters[j]);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }
        points[i].cluster = cluster_index;
        clusters[cluster_index].size++;
    }
}

void update_centroids(Point points[], Cluster clusters[], int num_points, int k) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid[0] = 0.0;
        clusters[i].centroid[1] = 0.0;
        clusters[i].size = 0;
    }

    for (int i = 0; i < num_points; i++) {
        int cluster_index = points[i].cluster;
        clusters[cluster_index].centroid[0] += points[i].coords[0];
        clusters[cluster_index].centroid[1] += points[i].coords[1];
        clusters[cluster_index].size++;
    }

    for (int i = 0; i < k; i++) {
        if (clusters[i].size > 0) {
            clusters[i].centroid[0] /= clusters[i].size;
            clusters[i].centroid[1] /= clusters[i].size;
        }
    }
}

int main() {
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];
    int num_points = 0;
    int k;

    printf("Enter the number of clusters: ");
    scanf("%d", &k);
    
    load_data("data.txt", points, &num_points);
    initialize_clusters(clusters, k, points, num_points);

    int iterations = 0;
    while (iterations < 100) {
        assign_clusters(points, clusters, num_points, k);
        update_centroids(points, clusters, num_points, k);
        iterations++;
    }

    printf("Final clusters:\n");
    for (int i = 0; i < k; i++) {
        printf("Cluster %d | Centroid: (%.2f, %.2f) | Size: %d\n", i, clusters[i].centroid[0], clusters[i].centroid[1], clusters[i].size);
    }

    return 0;
}