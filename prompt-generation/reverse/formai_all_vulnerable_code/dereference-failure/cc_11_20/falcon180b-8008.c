//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <float.h>

#define MAX_SIZE 1000
#define MAX_ITER 10000

int main() {
    srand(time(NULL));
    int size = rand() % MAX_SIZE + 2;
    double *matrix = (double *)malloc(size * size * sizeof(double));
    for (int i = 0; i < size * size; i++) {
        matrix[i] = rand() % 100 / 100.0;
    }
    double *vector = (double *)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        vector[i] = rand() % 100 / 100.0;
    }
    double *result = (double *)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        result[i] = 0.0;
    }
    double epsilon = 1e-6;
    int iter = 0;
    while (iter < MAX_ITER && fabs(vector[0]) > epsilon) {
        for (int i = 0; i < size; i++) {
            double sum = 0.0;
            for (int j = 0; j < size; j++) {
                sum += matrix[i * size + j] * vector[j];
            }
            vector[i] -= sum;
        }
        for (int i = 0; i < size; i++) {
            vector[i] /= vector[0];
        }
        for (int i = 0; i < size; i++) {
            result[i] += vector[i];
        }
        iter++;
    }
    printf("Result:\n");
    for (int i = 0; i < size; i++) {
        printf("%f\n", result[i]);
    }
    free(matrix);
    free(vector);
    free(result);
    return 0;
}