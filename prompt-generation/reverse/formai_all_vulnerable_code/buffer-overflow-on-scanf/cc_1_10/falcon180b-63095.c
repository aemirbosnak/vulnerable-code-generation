//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define BLACK 0
#define WHITE 1

int **createMatrix(int size) {
    int **matrix = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *) malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = WHITE;
        }
    }
    return matrix;
}

void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fillMatrix(int **matrix, int size) {
    int x, y, count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == WHITE) {
                x = i;
                y = j;
                count = 0;
                while (count < 4 && (x < size - 1 && matrix[x + 1][y] == WHITE) && (y < size - 1 && matrix[x][y + 1] == WHITE)) {
                    matrix[x][y] = BLACK;
                    x++;
                    y++;
                    count++;
                }
            }
        }
    }
}

void generateQRCode(char *data, int size) {
    int **matrix = createMatrix(size);
    fillMatrix(matrix, size);

    int x = 0, y = 0;
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == '0') {
            x = 0;
            y = 0;
        } else if (data[i] == '1') {
            x = 0;
            y = 1;
        }
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if ((j + x) < size && (k + y) < size) {
                    if ((j + x) % 2 == 0 && (k + y) % 2 == 0) {
                        matrix[j + x][k + y] = BLACK;
                    }
                }
            }
            x++;
            y++;
        }
    }

    printMatrix(matrix, size);

    freeMatrix(matrix, size);
}

int main() {
    char data[MAX_SIZE];
    printf("Enter data to generate QR code: ");
    scanf("%s", data);
    int size = atoi(data);
    generateQRCode(data, size);
    return 0;
}