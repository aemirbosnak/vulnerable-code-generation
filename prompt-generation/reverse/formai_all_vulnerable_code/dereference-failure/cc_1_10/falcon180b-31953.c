//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QR_MAX_SIZE 1000
#define QR_MAX_DATA 1024

typedef struct {
    int size;
    int data[QR_MAX_DATA];
} QRCode;

QRCode *generateQRCode(int data[], int dataSize) {
    QRCode *qrCode = malloc(sizeof(QRCode));
    qrCode->size = QR_MAX_SIZE;
    qrCode->data[0] = 0;
    int i, j;
    for (i = 0; i < dataSize; i++) {
        qrCode->data[i + 1] = data[i];
    }
    for (i = 0; i < qrCode->size; i++) {
        for (j = 0; j < qrCode->size; j++) {
            if (i == j) {
                qrCode->data[i * qrCode->size + j] = 1;
            } else if (i == qrCode->size - j - 1) {
                qrCode->data[i * qrCode->size + j] = 1;
            } else if (j == qrCode->size - i - 1) {
                qrCode->data[i * qrCode->size + j] = 1;
            }
        }
    }
    return qrCode;
}

void printQRCode(QRCode *qrCode) {
    int i, j;
    for (i = 0; i < qrCode->size; i++) {
        for (j = 0; j < qrCode->size; j++) {
            if (qrCode->data[i * qrCode->size + j] == 1) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int main() {
    int data[QR_MAX_DATA];
    int dataSize;
    printf("Enter data to generate QR code (up to %d bytes):\n", QR_MAX_DATA);
    fgets(data, QR_MAX_DATA, stdin);
    dataSize = strlen(data);
    QRCode *qrCode = generateQRCode(data, dataSize);
    printf("QR code generated:\n");
    printQRCode(qrCode);
    free(qrCode);
    return 0;
}