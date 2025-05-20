//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int N = 10;
    int k = 3;
    int **data = malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++) {
        data[i] = malloc(k * sizeof(int));
    }

    srand(time(NULL));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < k; j++) {
            data[i][j] = rand() % 100;
        }
    }

    int **centroids = malloc(k * sizeof(int*));
    for(int i = 0; i < k; i++) {
        centroids[i] = malloc(N * sizeof(int));
    }

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < N; j++) {
            centroids[i][j] = rand() % 100;
        }
    }

    for(int iter = 0; iter < 100; iter++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < k; j++) {
                int minDist = 100000;
                int minIndex = -1;
                for(int l = 0; l < k; l++) {
                    if(l!= j) {
                        int dist = 0;
                        for(int m = 0; m < N; m++) {
                            dist += (centroids[j][m] - data[i][m]) * (centroids[j][m] - data[i][m]);
                        }
                        if(dist < minDist) {
                            minDist = dist;
                            minIndex = l;
                        }
                    }
                }
                data[i][j] = minIndex;
            }
        }

        for(int i = 0; i < k; i++) {
            for(int j = 0; j < N; j++) {
                centroids[i][j] = 0;
                for(int l = 0; l < N; l++) {
                    centroids[i][j] += data[l][i] * data[l][j];
                }
                centroids[i][j] /= N;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < k; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

    free(data);
    for(int i = 0; i < k; i++) {
        free(centroids[i]);
    }
    free(centroids);

    return 0;
}