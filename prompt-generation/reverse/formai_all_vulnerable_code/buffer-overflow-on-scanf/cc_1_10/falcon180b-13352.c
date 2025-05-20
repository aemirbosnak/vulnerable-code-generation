//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    int x, y;
    int size;
    char data[MAX_SIZE];
} QRCode;

void initQRCode(QRCode* qrcode) {
    qrcode->x = 0;
    qrcode->y = 0;
    qrcode->size = 0;
    memset(qrcode->data, 0, MAX_SIZE);
}

int readQRCode(QRCode* qrcode, char* input) {
    int i, j;
    int x = 0, y = 0;
    int size = 0;
    int value = 0;
    int count = 0;

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '1') {
            value = 1;
        } else {
            value = 0;
        }

        for (j = 0; j < 3; j++) {
            if (value == 1) {
                if (x >= MAX_SIZE || y >= MAX_SIZE) {
                    return -1;
                }

                qrcode->data[y * MAX_SIZE + x] = 1;
                x++;
            } else {
                x++;
            }
        }

        if (x >= MAX_SIZE) {
            y++;
            x = 0;
        }

        if (y >= MAX_SIZE) {
            return -1;
        }

        size++;
        count++;
    }

    qrcode->x = 0;
    qrcode->y = 0;
    qrcode->size = size;

    return count;
}

int main() {
    QRCode qrcode;
    char input[MAX_SIZE];
    int count;

    initQRCode(&qrcode);

    printf("Enter QR code data: ");
    scanf("%s", input);

    count = readQRCode(&qrcode, input);

    if (count > 0) {
        printf("QR code data read successfully.\n");
        printf("Size: %d x %d\n", qrcode.size, qrcode.size);
    } else {
        printf("Error reading QR code data.\n");
    }

    return 0;
}