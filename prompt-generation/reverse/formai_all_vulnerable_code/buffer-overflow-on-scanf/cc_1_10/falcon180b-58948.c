//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000
#define BLACK 0
#define WHITE 1

int **create_matrix(int size) {
    int i, j;
    int **matrix = malloc(size * sizeof(int *));
    for (i = 0; i < size; i++) {
        matrix[i] = malloc(size * sizeof(int));
        for (j = 0; j < size; j++) {
            matrix[i][j] = WHITE;
        }
    }
    return matrix;
}

void add_module(int **matrix, int x, int y, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if ((i >= x - size / 2 && i <= x + size / 2) && (j >= y - size / 2 && j <= y + size / 2)) {
                matrix[i][j] = BLACK;
            }
        }
    }
}

void draw_qr_code(int **matrix, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (matrix[i][j] == BLACK) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the size of the QR code: ");
    scanf("%d", &size);
    int **matrix = create_matrix(size);
    int x, y;
    printf("Enter the position of the module (x, y): ");
    scanf("%d %d", &x, &y);
    add_module(matrix, x, y, size);
    draw_qr_code(matrix, size);
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}