//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#define N 3
#define M 3
#define SEED 13

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    float elements[N][M];
} matrix;

void initMatrix(matrix *m) {
    int i, j;
    srand(SEED);
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            m->elements[i][j] = (float)rand() / RAND_MAX;
        }
    }
}

void printMatrix(const matrix *m) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%.2f ", m->elements[i][j]);
        }
        printf("\n");
    }
}

matrix multiplyMatrices(const matrix *a, const matrix *b) {
    matrix result;
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            result.elements[i][j] = 0;
            for (k = 0; k < M; k++) {
                result.elements[i][j] += a->elements[i][k] * b->elements[k][j];
            }
        }
    }
    return result;
}

int main() {
    matrix a, b, c;
    clock_t start;
    initMatrix(&a);
    initMatrix(&b);
    start = clock();
    c = multiplyMatrices(&a, &b);
    printMatrix(&c);
    printf("Time taken: %.6fs\n", (float)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}