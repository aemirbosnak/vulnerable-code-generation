//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QR_SIZE 10000
#define MAX_DATA_BITS 4296

typedef struct {
    int size;
    int *data;
} QRCode;

QRCode* createQRCode(int size) {
    QRCode *qrcode = (QRCode*)malloc(sizeof(QRCode));
    qrcode->size = size;
    qrcode->data = (int*)malloc(MAX_QR_SIZE * sizeof(int));
    memset(qrcode->data, 0, MAX_QR_SIZE * sizeof(int));
    return qrcode;
}

void destroyQRCode(QRCode *qrcode) {
    free(qrcode->data);
    free(qrcode);
}

void addData(QRCode *qrcode, int data) {
    int *dataPtr = &qrcode->data[qrcode->size];
    *dataPtr = data;
    qrcode->size++;
}

void addByte(QRCode *qrcode, char byte) {
    int data = 0;
    for (int i = 0; i < 8; i++) {
        data <<= 1;
        if (byte & 0x80) {
            data |= 1;
        }
        byte <<= 1;
    }
    addData(qrcode, data);
}

void addBytes(QRCode *qrcode, char *bytes, int length) {
    for (int i = 0; i < length; i++) {
        addByte(qrcode, bytes[i]);
    }
}

int getQRCodeSize(QRCode *qrcode) {
    return qrcode->size;
}

int getQRCodeData(QRCode *qrcode, int index) {
    return qrcode->data[index];
}

void printQRCode(QRCode *qrcode) {
    for (int i = 0; i < qrcode->size; i++) {
        printf("%d ", qrcode->data[i]);
    }
    printf("\n");
}

int main() {
    char *data = "Hello, world!";
    QRCode *qrcode = createQRCode(MAX_QR_SIZE);
    addBytes(qrcode, data, strlen(data));
    printQRCode(qrcode);
    destroyQRCode(qrcode);
    return 0;
}