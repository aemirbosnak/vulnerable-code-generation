//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000
#define BLACK 'X'
#define WHITE '.'

typedef struct {
    int size;
    char *data;
} QRCode;

QRCode *generateQRCode(char *input) {
    int size = 1;
    while (size < strlen(input) * 2) {
        size *= 2;
    }
    QRCode *qrCode = (QRCode *)malloc(sizeof(QRCode));
    qrCode->size = size;
    qrCode->data = (char *)malloc(size * size * sizeof(char));
    memset(qrCode->data, WHITE, size * size);
    for (int i = 0; i < strlen(input); i++) {
        int bit = input[i] - '0';
        int x = i * 2;
        int y = 0;
        while (bit > 0) {
            qrCode->data[(y * size) + x] = BLACK;
            bit--;
            x++;
            if (x == size) {
                x = 0;
                y++;
            }
        }
    }
    return qrCode;
}

void printQRCode(QRCode *qrCode) {
    for (int i = 0; i < qrCode->size; i++) {
        for (int j = 0; j < qrCode->size; j++) {
            printf("%c", qrCode->data[(i * qrCode->size) + j]);
        }
        printf("\n");
    }
}

int main() {
    char *input = "Hello, World!";
    QRCode *qrCode = generateQRCode(input);
    printf("QR Code:\n");
    printQRCode(qrCode);
    free(qrCode->data);
    free(qrCode);
    return 0;
}