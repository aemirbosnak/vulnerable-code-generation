//Code Llama-13B DATASET v1.0 Category: Percolation Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define PERCENTAGE 25

typedef struct {
    int rows;
    int cols;
    int** matrix;
} Percolation;

void create_matrix(Percolation* p) {
    int i, j;
    p->matrix = (int**)malloc(p->rows * sizeof(int*));
    for (i = 0; i < p->rows; i++) {
        p->matrix[i] = (int*)malloc(p->cols * sizeof(int));
        for (j = 0; j < p->cols; j++) {
            p->matrix[i][j] = 0;
        }
    }
}

void fill_matrix(Percolation* p) {
    int i, j;
    for (i = 0; i < p->rows; i++) {
        for (j = 0; j < p->cols; j++) {
            if (rand() % 100 < PERCENTAGE) {
                p->matrix[i][j] = 1;
            }
        }
    }
}

void display_matrix(Percolation* p) {
    int i, j;
    for (i = 0; i < p->rows; i++) {
        for (j = 0; j < p->cols; j++) {
            printf("%d ", p->matrix[i][j]);
        }
        printf("\n");
    }
}

int is_percolated(Percolation* p) {
    int i, j;
    for (i = 0; i < p->rows; i++) {
        for (j = 0; j < p->cols; j++) {
            if (p->matrix[i][j] == 1) {
                if ((i > 0 && p->matrix[i-1][j] == 1) || (j > 0 && p->matrix[i][j-1] == 1)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    Percolation p;
    p.rows = MAX_ROWS;
    p.cols = MAX_COLS;
    create_matrix(&p);
    fill_matrix(&p);
    display_matrix(&p);
    printf("Percolation: %s\n", is_percolated(&p) ? "Yes" : "No");
    return 0;
}