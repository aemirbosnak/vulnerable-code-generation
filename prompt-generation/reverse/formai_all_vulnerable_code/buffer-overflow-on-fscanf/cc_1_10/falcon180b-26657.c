//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_QR_SIZE 1000
#define MAX_QR_DATA 5000

typedef struct {
    int size;
    int data[MAX_QR_DATA];
} QRCode;

void init_qrcode(QRCode *qr) {
    qr->size = 0;
}

void add_data_to_qrcode(QRCode *qr, int data) {
    if (qr->size >= MAX_QR_DATA) {
        printf("Error: QR code is full.\n");
        exit(1);
    }
    qr->data[qr->size] = data;
    qr->size++;
}

void print_qrcode(QRCode *qr) {
    printf("QR code size: %d\n", qr->size);
    printf("QR code data:\n");
    for (int i = 0; i < qr->size; i++) {
        printf("%d ", qr->data[i]);
    }
    printf("\n");
}

int main() {
    QRCode qr;
    init_qrcode(&qr);

    char filename[100];
    printf("Enter filename of QR code image: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    int data = 0;
    int count = 0;
    while ((fscanf(fp, "%d", &data))!= EOF) {
        if (count == 0) {
            printf("QR code found!\n");
        }
        add_data_to_qrcode(&qr, data);
        count++;
    }

    fclose(fp);
    print_qrcode(&qr);

    return 0;
}