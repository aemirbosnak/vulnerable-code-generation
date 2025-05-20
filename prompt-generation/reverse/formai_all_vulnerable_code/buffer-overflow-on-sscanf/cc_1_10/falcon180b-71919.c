//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_QR_CODE_SIZE 1000
#define BLACK 0
#define WHITE 1

typedef struct {
    int x, y;
} Point;

typedef struct {
    int size;
    int **data;
} QRCode;

int get_qrcode_size(char *filename) {
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp) / 4;
    fclose(fp);
    return size;
}

int load_qrcode(char *filename, QRCode *qrcode) {
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    int size = get_qrcode_size(filename);
    qrcode->size = size;
    qrcode->data = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        qrcode->data[i] = (int *)malloc(size * sizeof(int));
    }
    int x, y;
    int value;
    char buf[1024];
    while (fgets(buf, sizeof(buf), fp)!= NULL) {
        sscanf(buf, "%d %d %d", &x, &y, &value);
        if (value == WHITE) {
            qrcode->data[x][y] = BLACK;
        } else {
            qrcode->data[x][y] = WHITE;
        }
    }
    fclose(fp);
    return TRUE;
}

void print_qrcode(QRCode *qrcode) {
    for (int i = 0; i < qrcode->size; i++) {
        for (int j = 0; j < qrcode->size; j++) {
            if (qrcode->data[i][j] == BLACK) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    QRCode qrcode;
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    load_qrcode(argv[1], &qrcode);
    print_qrcode(&qrcode);
    return 0;
}