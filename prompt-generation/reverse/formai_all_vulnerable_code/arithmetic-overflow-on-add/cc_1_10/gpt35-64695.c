//FormAI DATASET v1.0 Category: QR code generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>
#include "qrencode.h"

#define MAX_STRING_LENGTH 1024
#define QR_CODE_SIZE 5 // in cm
#define BORDER_SIZE 1 // in modules
#define VERSION 1.0

typedef struct {
    char string[MAX_STRING_LENGTH];
    int size;
} QRCode;

QRCode generate_qr_code(char* input_string);
void print_qr_code(QRCode qrcode);

int main(void) {
    char input_string[MAX_STRING_LENGTH];
    printf("Enter input string: ");
    scanf("%[^\n]%*c", input_string);

    QRCode qrcode = generate_qr_code(input_string);
    print_qr_code(qrcode);

    return 0;
}

QRCode generate_qr_code(char* input_string) {
    QRcode* qrcode_qr = NULL;
    QRCode qrcode;

    qrcode_qr = QRcode_encodeString(input_string, BORDER_SIZE, QR_ECLEVEL_Q, QR_MODE_8, 1);
    if (qrcode_qr == NULL) {
        strcpy(qrcode.string, "Error generating QR code");
        qrcode.size = -1;
        return qrcode;
    }

    qrcode.size = qrcode_qr->width;
    uint8_t* qrcode_data = qrcode_qr->data;

    char* qr_code = (char*) calloc((qrcode.size * QR_CODE_SIZE + 1) * (qrcode.size * QR_CODE_SIZE + 1), sizeof(char));
    if (qr_code == NULL) {
        strcpy(qrcode.string, "Error generating QR code");
        qrcode.size = -1;
        return qrcode;
    }

    for (int i = 0; i < qrcode.size; i++) {
        for (int j = 0; j < qrcode.size; j++) {
            int idx = (i * qrcode.size) + j;
            if (qrcode_data[idx] & 1) {
                sprintf(&qr_code[((i * QR_CODE_SIZE) + 1) * (qrcode.size * QR_CODE_SIZE + 1) + (j * QR_CODE_SIZE) + 1], "%*c", QR_CODE_SIZE, ' ');
            } else {
                sprintf(&qr_code[((i * QR_CODE_SIZE) + 1) * (qrcode.size * QR_CODE_SIZE + 1) + (j * QR_CODE_SIZE) + 1], "%*c", QR_CODE_SIZE, '0');
            }
        }
    }

    QRcode_free(qrcode_qr);
    memset(&qrcode, 0, sizeof(QRCode));
    strcpy(qrcode.string, qr_code);
    free(qr_code);

    return qrcode;
}

void print_qr_code(QRCode qrcode) {
    if (qrcode.size == -1) {
        printf("%s\n", qrcode.string);
        return;
    }

    for (int i = 0; i < qrcode.size * QR_CODE_SIZE + 2; i++) {
        printf("-");
    }
    printf("\n");

    for (int i = 0; i < qrcode.size * QR_CODE_SIZE + 2; i++) {
        if (i == 0 || i == qrcode.size * QR_CODE_SIZE + 1) {
            printf("|");
        } else {
            printf(" ");
        }
    }
    printf("\n");

    for (int i = 0; i < qrcode.size; i++) {
        printf("| ");
        for (int j = 0; j < qrcode.size; j++) {
            printf("%c", qrcode.string[((i * QR_CODE_SIZE) + 1) * (qrcode.size * QR_CODE_SIZE + 1) + (j * QR_CODE_SIZE) + 1]);
        }
        printf(" |\n");
    }

    for (int i = 0; i < qrcode.size * QR_CODE_SIZE + 2; i++) {
        if (i == 0 || i == qrcode.size * QR_CODE_SIZE + 1) {
            printf("|");
        } else {
            printf(" ");
        }
    }
    printf("\n");

    for (int i = 0; i < qrcode.size * QR_CODE_SIZE + 2; i++) {
        printf("-");
    }
    printf("\n");
}