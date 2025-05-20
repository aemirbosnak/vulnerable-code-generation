//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define MAX_CLUSTERS 5

int main()
{
    int num_clusters = MAX_CLUSTERS;
    int num_data_points = 10;
    int num_iterations = MAX_ITERATIONS;

    float *data = (float*) malloc(num_data_points * sizeof(float));
    int *clusters = (int*) malloc(num_data_points * sizeof(int));

    for (int i = 0; i < num_data_points; i++) {
        data[i] = (float)rand() / (float)RAND_MAX;
    }

    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = (int)rand() / (int)RAND_MAX;
    }

    float *centroids = (float*) malloc(num_clusters * sizeof(float));

    for (int i = 0; i < num_clusters; i++) {
        centroids[i] = data[clusters[i]];
    }

    float *distances = (float*) malloc(num_clusters * num_data_points * sizeof(float));

    for (int iteration = 0; iteration < num_iterations; iteration++) {
        for (int i = 0; i < num_data_points; i++) {
            float min_distance = 0;
            int min_cluster = 0;

            for (int j = 0; j < num_clusters; j++) {
                float distance = 0;

                for (int k = 0; k < num_clusters; k++) {
                    distance += pow(data[i] - centroids[k], 2);
                }

                distance = sqrt(distance);

                if (distance < min_distance) {
                    min_distance = distance;
                    min_cluster = j;
                }
            }

            distances[i * num_clusters + min_cluster] = min_distance;
        }

        for (int i = 0; i < num_clusters; i++) {
            centroids[i] = 0;

            for (int j = 0; j < num_data_points; j++) {
                centroids[i] += distances[j * num_clusters + i];
            }

            centroids[i] = centroids[i] / (float)num_data_points;
        }
    }

    for (int i = 0; i < num_data_points; i++) {
        printf("%d ", clusters[i]);
    }

    printf("\n");

    for (int i = 0; i < num_clusters; i++) {
        printf("Centroid %d: ", i);

        for (int j = 0; j < num_data_points; j++) {
            printf("%f ", centroids[i]);
        }

        printf("\n");
    }

    free(data);
    free(clusters);
    free(centroids);
    free(distances);

    return 0;
}