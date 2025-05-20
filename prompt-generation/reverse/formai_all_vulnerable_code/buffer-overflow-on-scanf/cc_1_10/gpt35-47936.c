//FormAI DATASET v1.0 Category: QR code reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t version;
    uint8_t type;
    uint8_t mode;
    uint8_t data_length;
    uint8_t data[255];
    uint16_t crc;
} QRcode;

bool check_crc(QRcode code) {
    uint16_t crc = 0xFFFF;
    uint8_t data_length = code.data_length ? code.data_length : 1;

    for (int i = 0; i < data_length; i++) {
        crc ^= code.data[i];
        for (int j = 0; j < 8; j++) {
            if (crc & 0x0001) {
                crc >>= 1;
                crc ^= 0x8408;
            } else {
                crc >>= 1;
            }
        }
    }
    return (code.crc == crc);
}

int main() {
    printf("Please enter a QR code in the following format:\n");
    printf("version (1 byte) | type (1 byte) | mode (1 byte) | data_length (1 byte) | data (up to 255 bytes) | crc (2 bytes)\n");

    QRcode qr;

    scanf("%hhu %hhu %hhu %hhu", &qr.version, &qr.type, &qr.mode, &qr.data_length);

    if (qr.data_length > 255) {
        printf("Error: data length cannot exceed 255 bytes\n");
        return 1;
    }

    for (int i = 0; i < qr.data_length; i++) {
        scanf("%hhu", &qr.data[i]);
    }

    scanf("%hu", &qr.crc);

    if (!check_crc(qr)) {
        printf("Error: the CRC check failed\n");
        return 1;
    }

    printf("QR code accepted! Here's the data:\n");
    for (int i = 0; i < qr.data_length; i++) {
        printf("%c", qr.data[i]);
    }
    printf("\n");

    return 0;
}