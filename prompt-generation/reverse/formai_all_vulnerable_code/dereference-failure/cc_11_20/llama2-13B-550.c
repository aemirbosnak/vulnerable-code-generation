//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 10000

int main() {
    int i, j, k, m;
    double mean, stddev, temp, sum;

    // Generate a random matrix of size N x N
    double **matrix = (double **) malloc(N * sizeof(double *));
    for (i = 0; i < N; i++) {
        matrix[i] = (double *) malloc(N * sizeof(double));
        for (j = 0; j < N; j++) {
            matrix[i][j] = (double) rand() / RAND_MAX;
        }
    }

    // Calculate the mean and standard deviation of the matrix
    mean = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            temp = matrix[i][j];
            mean += temp;
        }
        mean /= N;
    }

    stddev = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            temp = matrix[i][j] - mean;
            stddev += temp * temp;
        }
        stddev /= N;
    }
    stddev = sqrt(stddev);

    // Calculate the probability distribution of the matrix
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            sum = 0;
            for (k = 0; k < N; k++) {
                sum += matrix[i][k] * matrix[k][j];
            }
            matrix[i][j] = sum / N;
        }
    }

    // Print the probability distribution
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}