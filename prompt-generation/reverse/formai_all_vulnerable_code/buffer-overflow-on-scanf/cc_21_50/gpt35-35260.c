//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    printf("Welcome to our unique C Clustering Algorithm Implementation program!\n");
    int data_points, clusters, dimensions, i, j, k, l, m, n, p, flag;
    float **datapoints, **centroids, **prev_centroids, *euclidean_dist, sum, min_val, max_val, range, random_val;
    printf("Enter the number of data points: ");
    scanf("%d", &data_points);
    printf("Enter the number of clusters: ");
    scanf("%d", &clusters);
    printf("Enter the number of dimensions: ");
    scanf("%d", &dimensions);

    datapoints = (float **) malloc(data_points * sizeof(float *));
    for (i = 0; i < data_points; i++) {
        datapoints[i] = (float *) malloc(dimensions * sizeof(float));
    }

    centroids = (float **) malloc(clusters * sizeof(float *));
    for (i = 0; i < clusters; i++) {
        centroids[i] = (float *) malloc(dimensions * sizeof(float));
    }

    prev_centroids = (float **) malloc(clusters * sizeof(float *));
    for (i = 0; i < clusters; i++) {
        prev_centroids[i] = (float *) malloc(dimensions * sizeof(float));
    }

    euclidean_dist = (float *) malloc(clusters * sizeof(float));

    // input data points
    printf("\nEnter the data points: ");
    for (i = 0; i < data_points; i++) {
        printf("\nData point %d: ", i + 1);
        for (j = 0; j < dimensions; j++) {
            scanf("%f", &datapoints[i][j]);
        }
    }

    // initialize random centroids
    printf("\nInitializing the centroids...");
    for (i = 0; i < clusters; i++) {
        for (j = 0; j < dimensions; j++) {
            min_val = max_val = datapoints[0][j];
            for (k = 0; k < data_points; k++) {
                if (datapoints[k][j] < min_val) {
                    min_val = datapoints[k][j];
                }
                if (datapoints[k][j] > max_val) {
                    max_val = datapoints[k][j];
                }
            }
            range = max_val - min_val;
            random_val = ((float) rand() / (float) RAND_MAX) * range + min_val;
            centroids[i][j] = random_val;
        }
    }

    // clustering process
    printf("\n\nStarting the clustering process...");
    flag = 1;
    while (flag == 1) {
        flag = 0;
        for (i = 0; i < clusters; i++) {
            for (j = 0; j < dimensions; j++) {
                prev_centroids[i][j] = centroids[i][j];
            }
        }
        for (i = 0; i < data_points; i++) {
            for (j = 0; j < clusters; j++) {
                sum = 0;
                for (k = 0; k < dimensions; k++) {
                    sum += pow((datapoints[i][k] - centroids[j][k]), 2);
                }
                euclidean_dist[j] = sqrt(sum);
            }
            min_val = euclidean_dist[0];
            p = 0;
            for (j = 1; j < clusters; j++) {
                if (euclidean_dist[j] < min_val) {
                    min_val = euclidean_dist[j];
                    p = j;
                }
            }
            if (datapoints[i][dimensions] != p + 1) {
                flag = 1;
            }
            datapoints[i][dimensions] = p + 1;
        }
        if (flag == 1) {
            for (i = 0; i < clusters; i++) {
                for (j = 0; j < dimensions; j++) {
                    sum = 0;
                    n = 0;
                    for (k = 0; k < data_points; k++) {
                        if (datapoints[k][dimensions] == i + 1) {
                            sum += datapoints[k][j];
                            n++;
                        }
                    }
                    centroids[i][j] = sum / n;
                }
            }
        }
    }

    // printing the final result
    printf("\n\nFinal result: ");
    for (i = 0; i < data_points; i++) {
        printf("\nData point %d: ", i + 1);
        for (j = 0; j < dimensions; j++) {
            printf("%f ", datapoints[i][j]);
        }
        printf("Cluster: %d", (int) datapoints[i][dimensions]);
    }
    printf("\n\n");

    return 0;
}