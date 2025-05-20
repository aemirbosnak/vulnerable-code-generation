//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QR_SIZE 100
#define MAX_QR_CODE_WORDS 1000

typedef struct {
    int size;
    int *data;
} QRCode;

int *createQRCode(int size, char *data) {
    int *qrCode = (int *) malloc(size * sizeof(int));
    int i, j, index = 0;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (data[index] == '1') {
                qrCode[i * size + j] = 1;
            } else {
                qrCode[i * size + j] = 0;
            }
            index++;
        }
    }

    return qrCode;
}

void readQRCode(QRCode *qrCode) {
    int i, j;

    for (i = 0; i < qrCode->size; i++) {
        for (j = 0; j < qrCode->size; j++) {
            if (qrCode->data[i * qrCode->size + j] == 1) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }
}

int main() {
    char data[MAX_QR_CODE_WORDS];
    int size, i;

    printf("Enter QR code data: ");
    scanf("%s", data);

    size = strlen(data);

    if (size < 1 || size > MAX_QR_CODE_WORDS) {
        printf("Invalid QR code data\n");
        return 1;
    }

    QRCode qrCode = {size, createQRCode(size, data)};

    readQRCode(&qrCode);

    free(qrCode.data);

    return 0;
}