//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 100
#define TOL 0.0001

int main() {
    // generating random data
    float *data = (float*)malloc(sizeof(float)*1000);
    float *c_means = (float*)calloc(3, sizeof(float));
    int *clusters = (int*)malloc(sizeof(int)*1000);
    int i;
    for (i=0; i<1000; i++) {
        data[i] = (rand() % 50) + 1;
    }

    // initialization of cluster means
    c_means[0] = 5.0;
    c_means[1] = 15.0;
    c_means[2] = 25.0;

    float *old_c_means = (float*)calloc(3, sizeof(float));
    int iter = 0;

    while (iter < MAX_ITER) {
        // calculating clusters
        int j, k;
        for (j=0; j<1000; j++) {
            float min = INFINITY;
            int idx = -1;
            for (k=0; k<3; k++) {
                float dist = fabs(data[j] - c_means[k]);
                if (dist < min) {
                    min = dist;
                    idx = k;
                }
            }
            clusters[j] = idx;
        }

        // saving old cluster means
        for (k=0; k<3; k++) {
            old_c_means[k] = c_means[k];
        }

        // calculating new cluster means
        float sum[3] = {0.0, 0.0, 0.0};
        int count[3] = {0, 0, 0};
        for (j=0; j<1000; j++) {
            sum[clusters[j]] += data[j];
            count[clusters[j]]++;
        }
        for (k=0; k<3; k++) {
            c_means[k] = sum[k] / count[k];
        }

        // checking for convergence
        float max_shift = 0.0;
        for (k=0; k<3; k++) {
            float shift = fabs(old_c_means[k] - c_means[k]);
            if (shift > max_shift) {
                max_shift = shift;
            }
        }
        printf("Iteration: %d, Max Shift: %f\n", iter, max_shift);
        if (max_shift < TOL) {
            break;
        }

        iter++;
    }

    // printing final clusters
    printf("\nClusters:\n");
    for (i=0; i<1000; i++) {
        printf("%d ", clusters[i]);
    }
    printf("\n");

    free(data);
    free(c_means);
    free(old_c_means);
    free(clusters);

    return 0;
}