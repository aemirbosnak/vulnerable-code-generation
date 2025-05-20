//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QRCODE_SIZE 21
#define QRCODE_MAX_DATA (QRCODE_SIZE * QRCODE_SIZE - 1)

typedef struct {
    int size;
    int *data;
} QRCode;

void generateQRCode(QRCode *qrcode, char *data) {
    int i, j, mask = 0;
    int size = qrcode->size;
    int dataLen = strlen(data);
    int dataIndex = 0;
    int bitIndex = 0;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            mask = 1 << bitIndex;
            if (mask & (qrcode->data[i] >> (size - j - 1))) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

QRCode *createQRCode(char *data) {
    QRCode *qrcode = malloc(sizeof(QRCode));
    qrcode->size = QRCODE_SIZE;
    qrcode->data = calloc(qrcode->size * qrcode->size, sizeof(int));

    int dataLen = strlen(data);
    int dataIndex = 0;
    int bitIndex = 0;

    for (int i = 0; i < qrcode->size; i++) {
        for (int j = 0; j < qrcode->size; j++) {
            int mask = 1 << bitIndex;
            if (data[dataIndex] == '1' && (i + j) % 2 == 0) {
                qrcode->data[i] |= mask;
            }
            bitIndex++;
            if (bitIndex == 8) {
                bitIndex = 0;
                dataIndex++;
            }
        }
    }

    return qrcode;
}

int main() {
    char *data = "Hello, World!";
    QRCode *qrcode = createQRCode(data);
    generateQRCode(qrcode, data);
    free(qrcode->data);
    free(qrcode);
    return 0;
}