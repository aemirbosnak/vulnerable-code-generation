//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 1000
#define BLACK 0
#define WHITE 1

struct Pixel {
    int x;
    int y;
    int color;
};

struct Pixel QRCode[MAX_SIZE][MAX_SIZE];

void initQRCode() {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            QRCode[i][j].color = WHITE;
        }
    }
}

void drawQRCode(int x, int y, int color) {
    int i, j;
    for (i = 0; i < 21; i++) {
        for (j = 0; j < 21; j++) {
            if ((i + y) >= 0 && (i + y) < MAX_SIZE && (j + x) >= 0 && (j + x) < MAX_SIZE) {
                QRCode[i + y][j + x].color = color;
            }
        }
    }
}

void printQRCode() {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (QRCode[i][j].color == BLACK) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int x, y, i, j, n, m, k, color;
    char input[100];

    printf("Enter QR Code data: ");
    scanf("%s", input);

    n = strlen(input);
    m = n % 8 == 0? n / 8 : n / 8 + 1;
    k = (MAX_SIZE - m * 21) / 2;

    initQRCode();

    for (i = 0; i < m; i++) {
        for (j = 0; j < 21; j++) {
            color = input[i] & (1 << j)? BLACK : WHITE;
            drawQRCode(k + j * 21, k + i * 21, color);
        }
    }

    printQRCode();

    return 0;
}