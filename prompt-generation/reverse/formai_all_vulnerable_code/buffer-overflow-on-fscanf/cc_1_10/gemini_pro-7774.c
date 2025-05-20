//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point* points;
    int size;
} Dataset;

typedef struct {
    Point* centroid;
    int size;
} Cluster;

Dataset* load_dataset(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    Dataset* dataset = malloc(sizeof(Dataset));
    dataset->points = NULL;
    dataset->size = 0;

    while (1) {
        double x, y;
        int n = fscanf(file, "%lf %lf", &x, &y);
        if (n == 2) {
            dataset->points = realloc(dataset->points, (dataset->size + 1) * sizeof(Point));
            dataset->points[dataset->size].x = x;
            dataset->points[dataset->size].y = y;
            dataset->size++;
        } else {
            break;
        }
    }

    fclose(file);

    return dataset;
}

void free_dataset(Dataset* dataset) {
    free(dataset->points);
    free(dataset);
}

Cluster* create_clusters(Dataset* dataset, int k) {
    Cluster* clusters = malloc(k * sizeof(Cluster));
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = &dataset->points[i];
        clusters[i].size = 0;
    }

    return clusters;
}

void free_clusters(Cluster* clusters, int k) {
    for (int i = 0; i < k; i++) {
        free(clusters[i].centroid);
    }
    free(clusters);
}

double distance(Point* p1, Point* p2) {
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

void assign_points_to_clusters(Dataset* dataset, Cluster* clusters, int k) {
    for (int i = 0; i < dataset->size; i++) {
        Point* point = &dataset->points[i];
        double min_distance = INFINITY;
        int min_cluster = -1;
        for (int j = 0; j < k; j++) {
            double distance_to_centroid = distance(point, clusters[j].centroid);
            if (distance_to_centroid < min_distance) {
                min_distance = distance_to_centroid;
                min_cluster = j;
            }
        }
        clusters[min_cluster].size++;
    }
}

void update_centroids(Dataset* dataset, Cluster* clusters, int k) {
    for (int i = 0; i < k; i++) {
        Cluster* cluster = &clusters[i];
        double sum_x = 0;
        double sum_y = 0;
        for (int j = 0; j < cluster->size; j++) {
            Point* point = &dataset->points[j];
            sum_x += point->x;
            sum_y += point->y;
        }
        cluster->centroid->x = sum_x / cluster->size;
        cluster->centroid->y = sum_y / cluster->size;
    }
}

void k_means(Dataset* dataset, int k, int max_iterations) {
    Cluster* clusters = create_clusters(dataset, k);
    for (int i = 0; i < max_iterations; i++) {
        assign_points_to_clusters(dataset, clusters, k);
        update_centroids(dataset, clusters, k);
    }
    free_clusters(clusters, k);
}

int main() {
    Dataset* dataset = load_dataset("dataset.txt");
    if (dataset == NULL) {
        return 1;
    }

    int k = 3;
    int max_iterations = 100;
    k_means(dataset, k, max_iterations);

    free_dataset(dataset);

    return 0;
}