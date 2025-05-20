//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QR_CODE_SIZE 10000

typedef struct {
    int x, y;
    int size;
    int value;
} QRCodePixel;

void print_qrcode(QRCodePixel *qrcode, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (qrcode[i * size + j].value == 0) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int read_qrcode(FILE *fp, QRCodePixel *qrcode, int size) {
    fseek(fp, 0, SEEK_SET);
    char data[MAX_QR_CODE_SIZE];
    fread(data, 1, MAX_QR_CODE_SIZE, fp);
    int pos = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (data[pos] == '0') {
                qrcode[i * size + j].value = 0;
            } else {
                qrcode[i * size + j].value = 1;
            }
            pos++;
        }
    }
    return 0;
}

int main() {
    QRCodePixel qrcode[MAX_QR_CODE_SIZE];
    int size;
    FILE *fp;
    char filename[100];
    printf("Enter the QR code filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    size = ftell(fp) / (MAX_QR_CODE_SIZE / 2);
    fseek(fp, 0, SEEK_SET);
    read_qrcode(fp, qrcode, size);
    printf("QR code data:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", qrcode[i * size + j].value);
        }
        printf("\n");
    }
    print_qrcode(qrcode, size);
    return 0;
}