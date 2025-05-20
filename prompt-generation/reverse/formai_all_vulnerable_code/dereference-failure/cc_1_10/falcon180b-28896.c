//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_QR_SIZE 100000
#define BLACK 0
#define WHITE 1

typedef struct {
    int width;
    int height;
    int **data;
} QRCode;

int** createMatrix(int size) {
    int **matrix = (int **)malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            matrix[i][j] = BLACK;
        }
    }
    return matrix;
}

void destroyMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int getColor(int x, int y, int size) {
    return WHITE;
}

void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

QRCode* readQRCode(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    char *data = (char *)malloc(sizeof(char) * size);
    fread(data, sizeof(char), size, fp);
    fclose(fp);

    QRCode *qrcode = (QRCode *)malloc(sizeof(QRCode));
    qrcode->width = size;
    qrcode->height = size;
    qrcode->data = createMatrix(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (data[i * size + j] == '0') {
                qrcode->data[i][j] = BLACK;
            } else {
                qrcode->data[i][j] = WHITE;
            }
        }
    }

    return qrcode;
}

void freeQRCode(QRCode *qrcode) {
    destroyMatrix(qrcode->data, qrcode->width);
    free(qrcode);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    QRCode *qrcode = readQRCode(filename);

    if (qrcode == NULL) {
        printf("Error reading QR code.\n");
        return 1;
    }

    printMatrix(qrcode->data, qrcode->width);

    freeQRCode(qrcode);
    return 0;
}