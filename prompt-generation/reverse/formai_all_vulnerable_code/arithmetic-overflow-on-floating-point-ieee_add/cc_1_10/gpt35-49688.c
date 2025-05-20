//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define NUM_POINTS 100
#define NUM_CLUSTERS 5
#define MAX_ITERATIONS 100

float calculate_distance(float x1, float y1, float x2, float y2) {
    return sqrtf(powf((x2 - x1), 2) + powf((y2 - y1), 2));
}

int main() {
    float points[NUM_POINTS][2] = {
        {0.1, 0.2},
        {0.3, 0.4},
        {0.5, 0.6},
        // Additional points go here
    };
    float centroids[NUM_CLUSTERS][2] = {
        {0.2, 0.3},
        {0.4, 0.5},
        {0.6, 0.7},
        // Additional centroids go here
    };
    int assignment[NUM_POINTS] = {0};

    int i, j, k, l, m, n;
    for (l = 0; l < MAX_ITERATIONS; l++) {
        // Cluster assignment step
        for (i = 0; i < NUM_POINTS; i++) {
            float min_distance = INFINITY;
            for (j = 0; j < NUM_CLUSTERS; j++) {
                float distance = calculate_distance(points[i][0], points[i][1], centroids[j][0], centroids[j][1]);
                if (distance < min_distance) {
                    min_distance = distance;
                    assignment[i] = j;
                }
            }
        }
        // Centroid calculation step
        for (m = 0; m < NUM_CLUSTERS; m++) {
            float sum_x = 0, sum_y = 0, count = 0;
            for (n = 0; n < NUM_POINTS; n++) {
                if (assignment[n] == m) {
                    sum_x += points[n][0];
                    sum_y += points[n][1];
                    count++;
                }
            }
            centroids[m][0] = sum_x / count;
            centroids[m][1] = sum_y / count;
        }
    }
    // Output results
    printf("Final assignments:\n");
    for (i = 0; i < NUM_POINTS; i++) {
        printf("%d ", assignment[i]);
    }
    printf("\n");
    printf("Final centroids:\n");
    for (i = 0; i < NUM_CLUSTERS; i++) {
        printf("%.2f %.2f\n", centroids[i][0], centroids[i][1]);
    }
    return 0;
}