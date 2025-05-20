//Code Llama-13B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define MAX_ITER 100

void print_matrix(int n, int m, double **A) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }
}

void print_centroids(int k, int n, double **centroids) {
    for (int i = 0; i < k; i++) {
        printf("Centroid %d: ", i);
        for (int j = 0; j < n; j++) {
            printf("%.2f ", centroids[i][j]);
        }
        printf("\n");
    }
}

void print_assignments(int n, int k, int **assignments) {
    for (int i = 0; i < n; i++) {
        printf("Assignment %d: ", i);
        for (int j = 0; j < k; j++) {
            printf("%d ", assignments[i][j]);
        }
        printf("\n");
    }
}

void update_centroids(int n, int k, int **assignments, double **centroids) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            centroids[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            centroids[assignments[i][j]][j] += i;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            centroids[i][j] /= n;
        }
    }
}

int** create_assignments(int n, int k) {
    int **assignments = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        assignments[i] = malloc(k * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            assignments[i][j] = rand() % k;
        }
    }

    return assignments;
}

int** create_centroids(int k, int n) {
    int **centroids = malloc(k * sizeof(int*));
    for (int i = 0; i < k; i++) {
        centroids[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            centroids[i][j] = rand() % 100;
        }
    }

    return centroids;
}

int main() {
    int n = 10;
    int k = 3;
    int **assignments = create_assignments(n, k);
    double **centroids = create_centroids(k, n);

    for (int iter = 0; iter < MAX_ITER; iter++) {
        update_centroids(n, k, assignments, centroids);
        print_centroids(k, n, centroids);
    }

    return 0;
}