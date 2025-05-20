//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int width;
    int height;
    char *data;
} QRCode;

QRCode *create_qrcode(int width, int height) {
    QRCode *qrcode = (QRCode *)malloc(sizeof(QRCode));
    qrcode->width = width;
    qrcode->height = height;
    qrcode->data = (char *)malloc(width * height);
    for (int i = 0; i < width * height; i++) {
        qrcode->data[i] = '0';
    }
    return qrcode;
}

int is_valid_qrcode(QRCode *qrcode) {
    int count = 0;
    for (int i = 0; i < qrcode->width; i++) {
        for (int j = 0; j < qrcode->height; j++) {
            if (qrcode->data[i * qrcode->height + j] == '1') {
                count++;
            }
        }
    }
    if (count % 2 == 0) {
        return 0;
    } else {
        return 1;
    }
}

int count_bits(QRCode *qrcode) {
    int count = 0;
    for (int i = 0; i < qrcode->width * qrcode->height; i++) {
        if (qrcode->data[i] == '1') {
            count++;
        }
    }
    return count;
}

int main() {
    int width, height;
    printf("Enter QR Code width: ");
    scanf("%d", &width);
    printf("Enter QR Code height: ");
    scanf("%d", &height);

    QRCode *qrcode = create_qrcode(width, height);

    // write your own code to generate QR code data and fill qrcode->data with 0's and 1's

    int is_valid = is_valid_qrcode(qrcode);
    int bit_count = count_bits(qrcode);

    if (is_valid) {
        printf("QR Code is valid and contains %d bits.\n", bit_count);
    } else {
        printf("QR Code is invalid.\n");
    }

    free(qrcode->data);
    free(qrcode);

    return 0;
}