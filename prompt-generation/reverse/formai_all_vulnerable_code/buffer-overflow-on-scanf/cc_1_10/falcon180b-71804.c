//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: ultraprecise
#include <stdio.h>

#define MAX_SIZE 100
#define MAX_DATA_SIZE ((MAX_SIZE - 7) / 4) * 3

void generate_qrcode(char* data, int size) {
    int i, j, bit, byte, mask, value;
    char qrcode[MAX_SIZE];
    int qrcode_size = 0;

    printf("Generating QR code...\n");

    // Add data
    for (i = 0; i < strlen(data); i++) {
        byte = data[i];
        for (j = 0; j < 8; j++) {
            bit = (byte >> (7 - j)) & 1;
            mask = 1 << (7 - j);
            value = 0;

            if (bit == 1) {
                value |= mask;
            }

            if (qrcode_size % 8 == 0) {
                qrcode[qrcode_size++] = '0' + value;
            }
        }
    }

    // Add padding
    int padding = (MAX_DATA_SIZE - strlen(data)) % 8;
    for (i = 0; i < padding; i++) {
        qrcode[qrcode_size++] = '0';
    }

    // Add format information
    qrcode[qrcode_size++] = '0';
    qrcode[qrcode_size++] = '0';

    // Add size information
    int num_modules = (size - 21) / 4 + 1;
    for (i = 0; i < num_modules; i++) {
        qrcode[qrcode_size++] = '1';
    }
    for (i = 0; i < (size - 21) % 4; i++) {
        qrcode[qrcode_size++] = '0';
    }

    // Add data
    for (i = 0; i < qrcode_size; i++) {
        printf("%c", qrcode[i]);
    }
}

int main() {
    char data[MAX_DATA_SIZE];
    printf("Enter data to encode: ");
    scanf("%s", data);

    int size;
    printf("Enter size of QR code: ");
    scanf("%d", &size);

    generate_qrcode(data, size);

    return 0;
}