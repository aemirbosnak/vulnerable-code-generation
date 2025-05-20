//Falcon-180B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_CLUSTERS 10
#define MAX_DATA_POINTS 100

typedef struct {
    int id;
    double x, y;
} DataPoint;

typedef struct {
    int num_points;
    DataPoint *points;
} Cluster;

Cluster *initialize_clusters(int num_clusters) {
    Cluster *clusters = (Cluster *)malloc(num_clusters * sizeof(Cluster));

    for (int i = 0; i < num_clusters; i++) {
        clusters[i].num_points = 0;
        clusters[i].points = NULL;
    }

    return clusters;
}

void add_data_point(Cluster *clusters, int num_clusters, DataPoint point) {
    int cluster_idx = rand() % num_clusters;

    clusters[cluster_idx].num_points++;
    clusters[cluster_idx].points = (DataPoint *)realloc(clusters[cluster_idx].points, clusters[cluster_idx].num_points * sizeof(DataPoint));

    clusters[cluster_idx].points[clusters[cluster_idx].num_points - 1] = point;
}

void print_clusters(Cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);

        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%d, %lf, %lf)\n", clusters[i].points[j].id, clusters[i].points[j].x, clusters[i].points[j].y);
        }

        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Cluster *clusters = initialize_clusters(MAX_CLUSTERS);

    DataPoint data_points[MAX_DATA_POINTS];

    for (int i = 0; i < MAX_DATA_POINTS; i++) {
        data_points[i].id = i;
        data_points[i].x = rand() % 100;
        data_points[i].y = rand() % 100;

        add_data_point(clusters, MAX_CLUSTERS, data_points[i]);
    }

    print_clusters(clusters, MAX_CLUSTERS);

    return 0;
}