//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_DATA 10000

typedef struct {
    int x, y;
} Point;

typedef struct {
    int width, height;
    int* data;
} QRCode;

QRCode* createQRCode(int width, int height) {
    QRCode* qrcode = (QRCode*) malloc(sizeof(QRCode));
    qrcode->width = width;
    qrcode->height = height;
    qrcode->data = (int*) malloc(MAX_DATA * sizeof(int));
    memset(qrcode->data, 0, MAX_DATA * sizeof(int));
    return qrcode;
}

void destroyQRCode(QRCode* qrcode) {
    free(qrcode->data);
    free(qrcode);
}

void setQRCodeData(QRCode* qrcode, int x, int y, int value) {
    int index = y * qrcode->width + x;
    if (index >= 0 && index < MAX_DATA) {
        qrcode->data[index] = value;
    }
}

int getQRCodeData(QRCode* qrcode, int x, int y) {
    int index = y * qrcode->width + x;
    if (index >= 0 && index < MAX_DATA) {
        return qrcode->data[index];
    }
    return -1;
}

void printQRCode(QRCode* qrcode) {
    for (int y = 0; y < qrcode->height; y++) {
        for (int x = 0; x < qrcode->width; x++) {
            int value = getQRCodeData(qrcode, x, y);
            printf("%d ", value);
        }
        printf("\n");
    }
}

int main() {
    int width, height;
    printf("Enter the width and height of the QR code: ");
    scanf("%d %d", &width, &height);

    QRCode* qrcode = createQRCode(width, height);

    int x, y;
    char ch;
    while ((ch = getchar())!= EOF) {
        if (isdigit(ch)) {
            setQRCodeData(qrcode, x, y, ch - '0');
        }
        x++;
        if (x == width) {
            x = 0;
            y++;
        }
    }

    printQRCode(qrcode);

    destroyQRCode(qrcode);

    return 0;
}