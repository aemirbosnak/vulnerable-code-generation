//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define DIMENSIONS 2

typedef struct {
    double coords[DIMENSIONS];
} Point;

typedef struct {
    Point center;
    Point points[MAX_POINTS];
    int num_points;
} Cluster;

int num_points;
Point points[MAX_POINTS];
int num_clusters;
Cluster clusters[MAX_CLUSTERS];

void read_points(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    num_points = 0;
    while (fscanf(file, "%lf %lf", &points[num_points].coords[0], &points[num_points].coords[1]) == 2) {
        num_points++;
    }

    fclose(file);
}

double distance(Point a, Point b) {
    return sqrt(pow(a.coords[0] - b.coords[0], 2) + pow(a.coords[1] - b.coords[1], 2));
}

void assign_clusters() {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].num_points = 0;
    }

    for (int i = 0; i < num_points; i++) {
        double min_dist = distance(points[i], clusters[0].center);
        int cluster_index = 0;

        for (int j = 1; j < num_clusters; j++) {
            double dist = distance(points[i], clusters[j].center);
            if (dist < min_dist) {
                min_dist = dist;
                cluster_index = j;
            }
        }
        clusters[cluster_index].points[clusters[cluster_index].num_points++] = points[i];
    }
}

void update_centers() {
    for (int i = 0; i < num_clusters; i++) {
        if (clusters[i].num_points == 0) continue;

        double sum_x = 0.0;
        double sum_y = 0.0;

        for (int j = 0; j < clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].coords[0];
            sum_y += clusters[i].points[j].coords[1];
        }

        clusters[i].center.coords[0] = sum_x / clusters[i].num_points;
        clusters[i].center.coords[1] = sum_y / clusters[i].num_points;
    }
}

int clusters_changed(Cluster old_clusters[]) {
    for (int i = 0; i < num_clusters; i++) {
        if (old_clusters[i].center.coords[0] != clusters[i].center.coords[0] ||
            old_clusters[i].center.coords[1] != clusters[i].center.coords[1]) {
            return 1;
        }
    }
    return 0;
}

void k_means(int k) {
    num_clusters = k;
    // Initialize cluster centers randomly from points
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].center = points[rand() % num_points];
        clusters[i].num_points = 0;
    }

    Cluster old_clusters[MAX_CLUSTERS];
    do {
        // Store old centers
        for (int i = 0; i < num_clusters; i++) {
            old_clusters[i] = clusters[i];
        }

        assign_clusters();
        update_centers();
    } while (clusters_changed(old_clusters));
}

void print_clusters() {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        printf("Center: (%.2f, %.2f)\n", clusters[i].center.coords[0], clusters[i].center.coords[1]);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("Point: (%.2f, %.2f)\n", clusters[i].points[j].coords[0], clusters[i].points[j].coords[1]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <data_file.txt> <num_clusters>\n", argv[0]);
        return EXIT_FAILURE;
    }

    srand(time(NULL));
    read_points(argv[1]);
    int k = atoi(argv[2]);

    k_means(k);
    print_clusters();

    return EXIT_SUCCESS;
}