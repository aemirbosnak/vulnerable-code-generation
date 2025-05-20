//FormAI DATASET v1.0 Category: QR code generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define QR_VERSION 1
#define QR_MODULE_SIZE 10
#define QR_CODE_SIZE 21
#define QR_SIZE (QR_CODE_SIZE * QR_VERSION * QR_MODULE_SIZE)

uint8_t qr_data[QR_VERSION][QR_CODE_SIZE][QR_CODE_SIZE];

void init_qr_data() {
    memset(qr_data, 0, sizeof(qr_data));
}

void print_qr_data() {
    for (int y = 0; y < QR_SIZE; y++) {
        for (int x = 0; x < QR_SIZE; x++) {
            if (qr_data[0][y / QR_VERSION][x / QR_VERSION]) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void set_qr_module(int x, int y) {
    qr_data[0][y][x] = 1;
}

void set_qr_data(const char* data) {
    for (int i = 0; i < strlen(data); i++) {
        int x = i % (QR_SIZE / QR_MODULE_SIZE);
        int y = i / (QR_SIZE / QR_MODULE_SIZE);
        if (x % 2 == 0 && y % 2 == 0 ||
            x % 2 == 1 && y % 2 == 1) {
            set_qr_module(x, y);
        }
    }
}

int main() {
    init_qr_data();
    char data[] = "Hello World!";
    set_qr_data(data);
    print_qr_data();
    return 0;
}