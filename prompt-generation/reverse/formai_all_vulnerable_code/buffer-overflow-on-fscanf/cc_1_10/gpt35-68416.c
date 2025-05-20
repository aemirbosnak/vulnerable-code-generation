//FormAI DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 500
#define K 3
#define MAX_ITER 100

typedef struct {
    double x, y;
} data_t;

data_t data[N];

int assignments[N];
data_t means[K];

double distance(data_t a, data_t b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    // Read data from file
    FILE *fp = fopen("data.txt", "r");
    for (int i = 0; i < N; i++) {
        fscanf(fp, "%lf %lf", &data[i].x, &data[i].y);
    }
    fclose(fp);

    // Initialize means
    for (int i = 0; i < K; i++) {
        means[i].x = data[(int)(rand()/(double)RAND_MAX*N)].x;
        means[i].y = data[(int)(rand()/(double)RAND_MAX*N)].y;
    }

    // Run kmeans
    for (int iter = 0; iter < MAX_ITER; iter++) {
        // Assign points to nearest mean
        for (int i = 0; i < N; i++) {
            double min_dist = INFINITY;
            for (int j = 0; j < K; j++) {
                double dist = distance(data[i], means[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    assignments[i] = j;
                }
            }
        }

        // Recalculate means
        for (int i = 0; i < K; i++) {
            double sum_x = 0, sum_y = 0;
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (assignments[j] == i) {
                    sum_x += data[j].x;
                    sum_y += data[j].y;
                    count++;
                }
            }
            if (count > 0) {
                means[i].x = sum_x / count;
                means[i].y = sum_y / count;
            }
        }
    }

    // Print results
    for (int i = 0; i < K; i++) {
        printf("Cluster %d: (%lf, %lf)\n", i+1, means[i].x, means[i].y);
    }

    return 0;
}