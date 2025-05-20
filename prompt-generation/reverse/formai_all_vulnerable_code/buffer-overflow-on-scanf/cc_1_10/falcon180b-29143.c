//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_MAX_SIZE 1024 // maximum size of QR code
#define QR_MIN_SIZE 21 // minimum size of QR code

// QR code structure
typedef struct {
    int size;
    char *data;
} QRCode;

// generate QR code
QRCode *generate_qrcode(char *input) {
    int len = strlen(input);
    int size = QR_MIN_SIZE;
    while (size < QR_MAX_SIZE && (len + 4) * size / 8 >= len) {
        size++;
    }
    QRCode *qrcode = malloc(sizeof(QRCode));
    qrcode->size = size;
    qrcode->data = malloc(size * size);
    memset(qrcode->data, 0, size * size);
    int pos = 0;
    for (int i = 0; i < len; i++) {
        int bit = input[i] - '0';
        int j = (pos / 8) * size + (pos % 8);
        int k = 0;
        while (k < 8 && j < size * size) {
            qrcode->data[j] |= (bit << (7 - k));
            j++;
            k++;
        }
        pos++;
    }
    int mask = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (qrcode->data[i * size + j] == 0) {
                int count = 0;
                while (count < 5 && (i + count < size || j + count >= 0)) {
                    if (qrcode->data[(i + count) * size + j + count] == 1) {
                        count++;
                    } else {
                        break;
                    }
                }
                if (count == 5) {
                    qrcode->data[i * size + j] = 1;
                }
            }
        }
    }
    return qrcode;
}

// print QR code
void print_qrcode(QRCode *qrcode) {
    int size = qrcode->size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (qrcode->data[i * size + j] == 1) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

// main function
int main() {
    char input[1024];
    printf("Enter input: ");
    scanf("%s", input);
    QRCode *qrcode = generate_qrcode(input);
    printf("QR code size: %d\n", qrcode->size);
    print_qrcode(qrcode);
    free(qrcode->data);
    free(qrcode);
    return 0;
}