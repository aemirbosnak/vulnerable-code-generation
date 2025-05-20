//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CLUSTERS 10
#define MAX_POINTS 100

typedef struct {
    double x, y;
} Point;

typedef struct {
    int cluster;
    double x, y;
} Cluster;

void read_points(char* filename, Point* points, int* n) {
    // Read in points from a file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }
    fscanf(file, "%d", n);
    for (int i = 0; i < *n; i++) {
        fscanf(file, "%lf %lf", &points[i].x, &points[i].y);
    }
    fclose(file);
}

void write_clusters(char* filename, Cluster* clusters, int n) {
    // Write out clusters to a file
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %lf %lf\n", clusters[i].cluster, clusters[i].x, clusters[i].y);
    }
    fclose(file);
}

void kmeans(Cluster* clusters, Point* points, int n, int k) {
    // K-Means clustering algorithm
    for (int i = 0; i < k; i++) {
        int min_dist = 1000;
        int min_idx = -1;
        for (int j = 0; j < n; j++) {
            double dist = (points[j].x - clusters[i].x) * (points[j].x - clusters[i].x) + (points[j].y - clusters[i].y) * (points[j].y - clusters[i].y);
            if (dist < min_dist) {
                min_dist = dist;
                min_idx = j;
            }
        }
        clusters[i].x = points[min_idx].x;
        clusters[i].y = points[min_idx].y;
    }
}

int main() {
    char filename[] = "points.txt";
    Point points[MAX_POINTS];
    int n;
    read_points(filename, points, &n);
    Cluster clusters[MAX_CLUSTERS];
    for (int i = 0; i < MAX_CLUSTERS; i++) {
        clusters[i].cluster = i;
    }
    kmeans(clusters, points, n, MAX_CLUSTERS);
    write_clusters(filename, clusters, MAX_CLUSTERS);
    return 0;
}