//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 5

// Point structure
typedef struct {
    double x, y;
} Point;

int main() {
    int k, i, j, np, nc, iterations, has_changed;
    Point points[MAX_POINTS];
    Point clusters[MAX_CLUSTERS];
    int assignments[MAX_POINTS];
    int counts[MAX_CLUSTERS];
    double distances[MAX_POINTS][MAX_CLUSTERS];

    // Input data
    printf("Enter the number of points: ");
    scanf("%d", &np);
    printf("Enter the coordinates of each point:\n");
    for (i = 0; i < np; i++) {
        printf("Point %d:\n", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    printf("Enter the number of clusters: ");
    scanf("%d", &nc);
    printf("Enter the coordinates of the initial centroids:\n");
    for (i = 0; i < nc; i++) {
        printf("Cluster %d:\n", i + 1);
        scanf("%lf %lf", &clusters[i].x, &clusters[i].y);
    }

    // Loop until convergence or maximum number of iterations
    iterations = 0;
    do {
        // Assignment step
        has_changed = 0;
        for (i = 0; i < np; i++) {
            for (j = 0; j < nc; j++) {
                distances[i][j] = sqrt(pow(points[i].x - clusters[j].x, 2) + pow(points[i].y - clusters[j].y, 2));
            }
            k = 0;
            for (j = 1; j < nc; j++) {
                if (distances[i][j] < distances[i][k]) {
                    k = j;
                }
            }
            if (assignments[i] != k) {
                assignments[i] = k;
                has_changed = 1;
            }
        }

        // Update step
        for (i = 0; i < nc; i++) {
            counts[i] = 0;
            clusters[i].x = 0;
            clusters[i].y = 0;
        }
        for (i = 0; i < np; i++) {
            k = assignments[i];
            counts[k]++;
            clusters[k].x += points[i].x;
            clusters[k].y += points[i].y;
        }
        for (i = 0; i < nc; i++) {
            if (counts[i] > 0) {
                clusters[i].x /= counts[i];
                clusters[i].y /= counts[i];
            }
        }

        iterations++;
    } while (has_changed && iterations < 100);

    // Output results
    printf("\nResulting clusters:\n");
    for (i = 0; i < nc; i++) {
        printf("Cluster %d: (%.2lf, %.2lf)\n", i + 1, clusters[i].x, clusters[i].y);
    }

    return 0;
}