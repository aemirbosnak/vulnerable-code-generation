//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NO_OF_POINTS 7
#define NO_OF_CLUSTERS 2

float data[NO_OF_POINTS][2] = {{5.1, 3.5}, {4.9, 3.0}, {4.7, 3.2}, {4.6, 3.1}, {5.0, 3.6}, {5.4, 3.9}, {4.6, 3.4}};

float centroids[NO_OF_CLUSTERS][2] = {{4.6, 3.4}, {5.0, 3.6}};

int label[NO_OF_POINTS];

float euclidean_distance(float x1, float y1, float x2, float y2) {
    float dist = sqrtf(powf((x1 - x2), 2) + powf((y1 - y2), 2));
    return dist;
}

void cluster_assignment() {
    float dist, min_dist;
    int i, j, k;
    for(i=0; i<NO_OF_POINTS; i++) {
        min_dist = INFINITY;
        for(j=0; j<NO_OF_CLUSTERS; j++) {
            dist = euclidean_distance(data[i][0], data[i][1], centroids[j][0], centroids[j][1]);
            if(dist < min_dist) {
                min_dist = dist;
                label[i] = j;
            }
        }
    }
}

void centroid_update() {
    float sum_x[NO_OF_CLUSTERS] = {0.0};
    float sum_y[NO_OF_CLUSTERS] = {0.0};
    float count[NO_OF_CLUSTERS] = {0.0};
    int i, j;
    for(i=0; i<NO_OF_POINTS; i++) {
        for(j=0; j<NO_OF_CLUSTERS; j++) {
            if(label[i] == j) {
                sum_x[j] += data[i][0];
                sum_y[j] += data[i][1];
                count[j]++;
            }
        }
    }
    for(i=0; i<NO_OF_CLUSTERS; i++) {
        centroids[i][0] = sum_x[i] / count[i];
        centroids[i][1] = sum_y[i] / count[i];
    }
}

void print_clusters() {
    int i, j;
    printf("Clusters:\n");
    for(i=0; i<NO_OF_CLUSTERS; i++) {
        printf("Cluster %d:\n", i+1);
        for(j=0; j<NO_OF_POINTS; j++) {
            if(label[j] == i) {
                printf("(%.2f, %.2f)\n", data[j][0], data[j][1]);
            }
        }
    }
}

int main() {
    int i, j, k;
    printf("Initial centroids:\n");
    for(i=0; i<NO_OF_CLUSTERS; i++) {
        printf("(%.2f, %.2f)\n", centroids[i][0], centroids[i][1]);
    }
    for(i=0; i<3; i++) {
        printf("Iteration %d:\n", i+1);
        cluster_assignment();
        centroid_update();
        for(j=0; j<NO_OF_CLUSTERS; j++) {
            printf("New centroid %d: (%.2f, %.2f)\n", j+1, centroids[j][0], centroids[j][1]);
        }
        print_clusters();
        printf("\n");
    }
    return 0;
}