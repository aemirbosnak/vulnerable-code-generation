//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 21
#define MOD 10

int createMatrix(int matrix[WIDTH][HEIGHT], int data);
void printMatrix(int matrix[WIDTH][HEIGHT]);
int calculateCheckDigit(int matrix[WIDTH][HEIGHT]);

int main() {
    int data = 0;
    int matrix[WIDTH][HEIGHT];

    printf("Enter data to encode: ");
    scanf("%d", &data);

    createMatrix(matrix, data);
    printMatrix(matrix);
    printf("Check digit: %d\n", calculateCheckDigit(matrix));

    return 0;
}

int createMatrix(int matrix[WIDTH][HEIGHT], int data) {
    int i, j;
    int value;

    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            value = 0;
            if ((i + j) % 2 == 0) {
                value = 1;
            }

            if (i == HEIGHT - 1 && j == WIDTH - 1) {
                value = 4;
            }

            if (i == HEIGHT - 1 && j == WIDTH - 2) {
                value = 8;
            }

            if (i == HEIGHT - 2 && j == WIDTH - 1) {
                value = 2;
            }

            if (i == HEIGHT - 2 && j == WIDTH - 2) {
                value = 1;
            }

            matrix[i][j] = value;
        }
    }

    int pos = 0;
    int bit = 1;
    int mask = 1;

    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            if (matrix[i][j] == 1) {
                matrix[i][j] = (data & bit)? 1 : 0;
                data ^= (mask << pos);
                pos += 1;
            }

            bit <<= 1;
        }

        mask <<= 1;
    }

    return 0;
}

void printMatrix(int matrix[WIDTH][HEIGHT]) {
    int i, j;

    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            printf("%d", matrix[i][j]);
        }

        printf("\n");
    }
}

int calculateCheckDigit(int matrix[WIDTH][HEIGHT]) {
    int sum = 0;
    int i, j;

    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            sum += matrix[i][j];
        }
    }

    return (10 - (sum % 10)) % 10;
}