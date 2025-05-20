//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define DIMENSION 2
#define N 6 // Number of data points
#define K 2 // Number of clusters

struct Point {
    double x[DIMENSION];
};

typedef struct Point Point;

int main() {

    Point points[N] = {{{5, 3}}, {{10, 15}}, {{15, 12}}, {{24, 10}}, {{30, 45}}, {{85, 70}}};
    // Initialize the cluster centers
    Point centers[K] = {{{5, 3}}, {{30, 45}}};

    int i, j, k;
    int belongsTo[N];

    for(i = 0; i < N; i++) {
        double minDist = INFINITY;
        double dist;

        for(j = 0; j < K; j++) {
            // Calculate the distance between the data point and the cluster center
            dist = sqrt(pow(points[i].x[0] - centers[j].x[0], 2) + pow(points[i].x[1] - centers[j].x[1], 2));

            if(dist < minDist) {
                minDist = dist;
                belongsTo[i] = j;
            }
        }
    }

    // Recalculate the cluster centers
    int count[K];
    for(i = 0; i < K; i++) {
        count[i] = 0;
        centers[i].x[0] = 0;
        centers[i].x[1] = 0;
    }

    for(i = 0; i < N; i++) {
        count[belongsTo[i]]++;
        centers[belongsTo[i]].x[0] += points[i].x[0];
        centers[belongsTo[i]].x[1] += points[i].x[1];
    }

    for(i = 0; i < K; i++) {
        centers[i].x[0] /= count[i];
        centers[i].x[1] /= count[i];
    }

    printf("Cluster 1: ");
    for(i = 0; i < N; i++) {
        if(belongsTo[i] == 0) {
            printf("(%f, %f) ", points[i].x[0], points[i].x[1]);
        }
    }

    printf("\nCluster 2: ");
    for(i = 0; i < N; i++) {
        if(belongsTo[i] == 1) {
            printf("(%f, %f) ", points[i].x[0], points[i].x[1]);
        }
    }
    
    return 0;
}