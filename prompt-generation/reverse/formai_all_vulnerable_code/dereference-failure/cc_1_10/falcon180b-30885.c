//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100
#define BLACK 0
#define WHITE 1

int **create_matrix(int width, int height) {
    int **matrix = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        matrix[i] = malloc(width * sizeof(int));
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = BLACK;
        }
    }
    return matrix;
}

void draw_matrix(int **matrix, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fill_matrix(int **matrix, int width, int height) {
    srand(time(NULL));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
}

int count_black_cells(int **matrix, int width, int height) {
    int count = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (matrix[i][j] == BLACK) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int width = WIDTH;
    int height = HEIGHT;
    int **matrix = create_matrix(width, height);
    fill_matrix(matrix, width, height);
    draw_matrix(matrix, width, height);
    int count = count_black_cells(matrix, width, height);
    printf("Black cells: %d\n", count);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}