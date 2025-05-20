//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_POINTS 1000
#define CLUSTER_SIZE 10
#define MAX_ITERATIONS 1000

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point points[CLUSTER_SIZE];
    int size;
} Cluster;

float distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int find_closest_cluster(Point p, Cluster clusters[], int num_clusters) {
    float min_distance = distance(p, clusters[0].points[0]);
    int closest_cluster = 0;
    for (int i = 0; i < num_clusters; i++) {
        for (int j = 0; j < clusters[i].size; j++) {
            if (distance(p, clusters[i].points[j]) < min_distance) {
                min_distance = distance(p, clusters[i].points[j]);
                closest_cluster = i;
            }
        }
    }
    return closest_cluster;
}

void initialize_clusters(Cluster clusters[], int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].size = 0;
    }
}

void add_point_to_cluster(Point p, Cluster *cluster) {
    cluster->points[cluster->size++] = p;
}

void print_cluster(Cluster cluster) {
    printf("{ ");
    for (int i = 0; i < cluster.size; i++) {
        printf("(%.2f, %.2f) ", cluster.points[i].x, cluster.points[i].y);
    }
    printf("}\n");
}

int main() {
    Point points[MAX_POINTS];
    int num_points;
    printf("Enter the number of points: ");
    scanf("%d", &num_points);
    printf("Enter the points in the form 'x y':\n");
    for (int i = 0; i < num_points; i++) {
        scanf("%f %f", &points[i].x, &points[i].y);
    }

    Cluster clusters[10]; // max of 10 clusters
    int num_clusters = 1;
    printf("\nCreating initial cluster...\n");
    add_point_to_cluster(points[0], &clusters[0]);
    initialize_clusters(clusters + 1, 9);

    int iterations = 0;
    bool changed_cluster = true;
    while (changed_cluster && iterations < MAX_ITERATIONS) {
        printf("\n--- Iteration %d ---\n", iterations + 1);
        changed_cluster = false;
        for (int i = 0; i < num_points; i++) {
            int closest_cluster = find_closest_cluster(points[i], clusters, num_clusters);
            if (closest_cluster != 0) {
                add_point_to_cluster(points[i], &clusters[closest_cluster]);
                add_point_to_cluster(clusters[0].points[--clusters[0].size], &clusters[closest_cluster]);
                changed_cluster = true;
                printf("Moved (%.2f, %.2f) from cluster 0 to cluster %d\n", points[i].x, points[i].y, closest_cluster);
            }
        }
        for (int i = 0; i < num_clusters; i++) {
            printf("Cluster %d: ", i);
            print_cluster(clusters[i]);
        }
        iterations++;
    }

    return 0;
}