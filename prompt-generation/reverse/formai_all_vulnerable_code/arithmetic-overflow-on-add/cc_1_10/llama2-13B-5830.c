//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define N 100000
#define M 100

struct point {
    int x;
    int y;
};

struct matrix {
    int rows;
    int cols;
    struct point data[N];
};

void init_matrix(struct matrix *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            m->data[i * m->cols + j].x = rand() % 100;
            m->data[i * m->cols + j].y = rand() % 100;
        }
    }
}

void print_matrix(struct matrix *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%d, %d ", m->data[i * m->cols + j].x, m->data[i * m->cols + j].y);
        }
        printf("\n");
    }
}

int main() {
    struct matrix m;
    init_matrix(&m);

    double start_time, end_time;
    double execution_time;

    for (int i = 0; i < M; i++) {
        start_time = clock();
        for (int j = 0; j < N; j++) {
            m.data[j].x = m.data[j].x + m.data[j].y;
        }
        end_time = clock();
        execution_time = (end_time - start_time) / CLOCKS_PER_SEC;
        printf("Execution time for %d iterations: %f seconds\n", i, execution_time);
    }

    return 0;
}