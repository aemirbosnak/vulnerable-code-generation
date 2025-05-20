//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#define MAX_POINTS 1000
#define MAX_CLUSTERS 10

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point centroid;
    int num_points;
    point points[MAX_POINTS];
} cluster;

int num_points;
point points[MAX_POINTS];
int num_clusters;
cluster clusters[MAX_CLUSTERS];

double distance(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void initialize_clusters() {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = rand() % 100;
        clusters[i].centroid.y = rand() % 100;
        clusters[i].num_points = 0;
    }
}

void assign_points_to_clusters() {
    for (int i = 0; i < num_points; i++) {
        double min_distance = 1000000;
        int min_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            double d = distance(points[i], clusters[j].centroid);
            if (d < min_distance) {
                min_distance = d;
                min_cluster = j;
            }
        }
        clusters[min_cluster].points[clusters[min_cluster].num_points] = points[i];
        clusters[min_cluster].num_points++;
    }
}

void update_centroids() {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = 0;
        clusters[i].centroid.y = 0;
        for (int j = 0; j < clusters[i].num_points; j++) {
            clusters[i].centroid.x += clusters[i].points[j].x;
            clusters[i].centroid.y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x /= clusters[i].num_points;
        clusters[i].centroid.y /= clusters[i].num_points;
    }
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    assert(fp != NULL);
    fscanf(fp, "%d %d", &num_points, &num_clusters);
    for (int i = 0; i < num_points; i++) {
        fscanf(fp, "%d %d", &points[i].x, &points[i].y);
    }
    fclose(fp);
    initialize_clusters();
    for (int i = 0; i < 100; i++) {
        assign_points_to_clusters();
        update_centroids();
    }
    fp = fopen("output.txt", "w");
    assert(fp != NULL);
    for (int i = 0; i < num_clusters; i++) {
        fprintf(fp, "Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            fprintf(fp, "  %d %d\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
    fclose(fp);
    return 0;
}