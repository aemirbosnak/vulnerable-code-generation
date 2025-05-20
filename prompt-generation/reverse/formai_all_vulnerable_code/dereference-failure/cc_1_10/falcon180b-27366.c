//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QRCODE_MAX_NUM_MODULES 256

typedef struct {
    int num_modules;
    int **modules;
} QRCode;

void QRCode_create(QRCode *qr, int num_modules) {
    qr->num_modules = num_modules;
    qr->modules = (int **)malloc(num_modules * sizeof(int *));
    for (int i = 0; i < num_modules; i++) {
        qr->modules[i] = (int *)malloc(num_modules * sizeof(int));
        for (int j = 0; j < num_modules; j++) {
            qr->modules[i][j] = 0;
        }
    }
}

void QRCode_destroy(QRCode *qr) {
    for (int i = 0; i < qr->num_modules; i++) {
        free(qr->modules[i]);
    }
    free(qr->modules);
}

void QRCode_set_module(QRCode *qr, int x, int y, int value) {
    qr->modules[y][x] = value;
}

int QRCode_get_module(QRCode *qr, int x, int y) {
    return qr->modules[y][x];
}

void QRCode_print(QRCode *qr) {
    for (int y = 0; y < qr->num_modules; y++) {
        for (int x = 0; x < qr->num_modules; x++) {
            printf("%d ", qr->modules[y][x]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int num_modules = QRCODE_MAX_NUM_MODULES;
    QRCode qr;
    QRCode_create(&qr, num_modules);

    for (int i = 0; i < num_modules; i++) {
        for (int j = 0; j < num_modules; j++) {
            int value = rand() % 2;
            QRCode_set_module(&qr, i, j, value);
        }
    }

    QRCode_print(&qr);

    QRCode_destroy(&qr);

    return 0;
}