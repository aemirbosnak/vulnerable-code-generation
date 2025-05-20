//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: active
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define N 100        // Maximum number of points
#define EPSILON 0.1  // Maximum distance between two points to be considered belonging to the same cluster

typedef struct {
    double x;
    double y;
} point;

double distance(point a, point b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

int main() {
    point p[N];
    int n = 0;   // Number of points
    double d;    // Distance between two points
    int c[N];    // Cluster label of each point
    int i, j, k;

    // Read in the points from a file
    FILE *f = fopen("points.txt", "r");
    while (fscanf(f, "%lf %lf", &p[n].x, &p[n].y) == 2) {
        c[n] = -1;  // -1 means the point hasn't been clustered yet
        n++;
    }
    fclose(f);

    // Perform the clustering
    int cluster = 0;
    for (i = 0; i < n; i++) {
        if (c[i] == -1) {
            c[i] = cluster;
            for (j = i+1; j < n; j++) {
                if (c[j] == -1) {
                    d = distance(p[i], p[j]);
                    if (d < EPSILON) {
                        c[j] = cluster;
                    }
                }
            }
            cluster++;
        }
    }

    // Print out the clusters
    for (i = 0; i < cluster; i++) {
        printf("Cluster %d: ", i);
        for (j = 0; j < n; j++) {
            if (c[j] == i) {
                printf("(%lf,%lf) ", p[j].x, p[j].y);
            }
        }
        printf("\n");
    }

    return 0;
}