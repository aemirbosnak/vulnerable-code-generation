//Code Llama-13B DATASET v1.0 Category: QR code generator ; Style: standalone
/*
 * QR code generator example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_VERSION 40
#define MAX_QR_MODULE_SIZE 100
#define MAX_QR_CODE_SIZE (MAX_QR_VERSION * MAX_QR_MODULE_SIZE)

typedef struct {
    bool **data;
    int version;
} QRCode;

QRCode* create_qr_code(int version) {
    QRCode *qr = malloc(sizeof(QRCode));
    qr->data = malloc(sizeof(bool*) * version);
    for (int i = 0; i < version; i++) {
        qr->data[i] = malloc(sizeof(bool) * version);
    }
    qr->version = version;
    return qr;
}

void free_qr_code(QRCode *qr) {
    for (int i = 0; i < qr->version; i++) {
        free(qr->data[i]);
    }
    free(qr->data);
    free(qr);
}

void set_qr_code_data(QRCode *qr, int x, int y, bool value) {
    qr->data[x][y] = value;
}

bool get_qr_code_data(QRCode *qr, int x, int y) {
    return qr->data[x][y];
}

void print_qr_code(QRCode *qr) {
    for (int i = 0; i < qr->version; i++) {
        for (int j = 0; j < qr->version; j++) {
            if (get_qr_code_data(qr, i, j)) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    QRCode *qr = create_qr_code(10);
    set_qr_code_data(qr, 2, 3, true);
    set_qr_code_data(qr, 5, 5, true);
    set_qr_code_data(qr, 7, 8, true);
    print_qr_code(qr);
    free_qr_code(qr);
    return 0;
}