//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define MIN_ITERATIONS 1
#define MIN_CLUSTERS 2
#define MAX_CLUSTERS 100
#define MAX_SIZE 10000

typedef struct {
    int* data;
    int n;
    int m;
    int k;
    int* centroids;
} Matrix;

Matrix* createMatrix(int n, int m) {
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->data = malloc(n * m * sizeof(int));
    matrix->n = n;
    matrix->m = m;
    matrix->k = 0;
    matrix->centroids = NULL;
    return matrix;
}

void destroyMatrix(Matrix* matrix) {
    free(matrix->data);
    free(matrix);
}

void initializeCentroids(Matrix* matrix) {
    int* centroids = malloc(matrix->k * matrix->m * sizeof(int));
    int* randCentroids = malloc(matrix->k * matrix->m * sizeof(int));
    int i, j, k;

    for (i = 0; i < matrix->m; i++) {
        for (j = 0; j < matrix->k; j++) {
            randCentroids[i * matrix->k + j] = matrix->data[i * matrix->n + (rand() % matrix->n)];
        }
    }

    for (i = 0; i < matrix->k; i++) {
        for (j = 0; j < matrix->m; j++) {
            centroids[j * matrix->k + i] = randCentroids[j * matrix->k + i];
        }
    }

    matrix->centroids = centroids;
}

void computeDistances(Matrix* matrix) {
    int* distances = malloc(matrix->k * matrix->n * sizeof(int));
    int i, j, k;

    for (i = 0; i < matrix->k; i++) {
        for (j = 0; j < matrix->n; j++) {
            distances[i * matrix->n + j] = 0;
        }
    }

    for (i = 0; i < matrix->n; i++) {
        for (j = 0; j < matrix->k; j++) {
            distances[j * matrix->n + i] = 0;
            for (k = 0; k < matrix->m; k++) {
                distances[j * matrix->n + i] += (matrix->data[i * matrix->n + k] - matrix->centroids[k * matrix->k + j]) * (matrix->data[i * matrix->n + k] - matrix->centroids[k * matrix->k + j]);
            }
        }
    }
}

void optimizeCentroids(Matrix* matrix) {
    int* newCentroids = malloc(matrix->k * matrix->m * sizeof(int));
    int i, j, k;

    for (i = 0; i < matrix->k; i++) {
        for (j = 0; j < matrix->m; j++) {
            newCentroids[j * matrix->k + i] = 0;
            for (k = 0; k < matrix->n; k++) {
                newCentroids[j * matrix->k + i] += matrix->data[k * matrix->n + j] * matrix->data[k * matrix->n + i];
            }
            newCentroids[j * matrix->k + i] /= matrix->data[j * matrix->n + i];
        }
    }

    for (i = 0; i < matrix->k; i++) {
        for (j = 0; j < matrix->m; j++) {
            matrix->centroids[j * matrix->k + i] = newCentroids[j * matrix->k + i];
        }
    }

    free(newCentroids);
}

void printMatrix(Matrix* matrix) {
    int i, j;

    for (i = 0; i < matrix->n; i++) {
        for (j = 0; j < matrix->m; j++) {
            printf("%d ", matrix->data[i * matrix->n + j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_matrix.txt> <output_centroids.txt>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    int n, m;
    fscanf(inputFile, "%d %d", &n, &m);

    Matrix* matrix = createMatrix(n, m);
    fscanf(inputFile, "%d", &matrix->n);
    for (int i = 0; i < matrix->n; i++) {
        fscanf(inputFile, "%d", &matrix->data[i]);
    }

    fscanf(inputFile, "%d", &matrix->k);
    matrix->centroids = malloc(matrix->k * matrix->m * sizeof(int));
    fscanf(inputFile, "%d", &matrix->k);
    for (int i = 0; i < matrix->k; i++) {
        fscanf(inputFile, "%d", &matrix->centroids[i]);
    }

    initializeCentroids(matrix);
    computeDistances(matrix);

    int iterations = 0;
    while (fabs(matrix->centroids[0] - matrix->centroids[1]) > 1e-6 && iterations < MAX_ITERATIONS) {
        optimizeCentroids(matrix);
        iterations++;
    }

    if (iterations < MIN_ITERATIONS) {
        printf("Convergence not reached after %d iterations.\n", iterations);
    } else {
        printf("Convergence reached after %d iterations.\n", iterations);
        printf("Centroids: ");
        for (int i = 0; i < matrix->k; i++) {
            for (int j = 0; j < matrix->m; j++) {
                fprintf(outputFile, "%d ", matrix->centroids[j * matrix->k + i]);
            }
            fprintf(outputFile, "\n");
        }
    }

    destroyMatrix(matrix);
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}