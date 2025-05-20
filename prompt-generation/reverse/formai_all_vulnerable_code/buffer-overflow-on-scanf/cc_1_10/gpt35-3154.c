//FormAI DATASET v1.0 Category: QR code reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define QRCODE_SIZE 25

bool verify_QRcode(char* qrCode);
void print_QRcode_info(char* qrCode);

int main() {
    char qrCode[QRCODE_SIZE];
    printf("Please scan the QR code: ");
    scanf("%s", qrCode);

    if (verify_QRcode(qrCode)) {
        print_QRcode_info(qrCode);
    } else {
        printf("Invalid QR code. Please try again.\n");
    }

    return 0;
}

bool verify_QRcode(char* qrCode) {
    if (strlen(qrCode) != QRCODE_SIZE) {
        return false;
    }

    for (int i = 0; i < QRCODE_SIZE; i++) {
        if (!(qrCode[i] >= '0' && qrCode[i] <= '9') && !(qrCode[i] >= 'a' && qrCode[i] <= 'f') && !(qrCode[i] >= 'A' && qrCode[i] <= 'F')) {
            return false;
        }
    }

    return true;
}

void print_QRcode_info(char* qrCode) {
    printf("QR Code: %s\n", qrCode);

    int version = (qrCode[0] - '0') * 10 + (qrCode[1] - '0');
    printf("Version: %d\n", version);

    int data_length = (qrCode[2] - '0') * 100 + (qrCode[3] - '0') * 10 + (qrCode[4] - '0');
    printf("Data Length: %d\n", data_length);

    char* data = (char*) malloc(data_length + 1);
    strncpy(data, qrCode + 5, data_length);
    data[data_length] = '\0';
    printf("Data: %s\n", data);
    free(data);

    printf("Checksum: %c%c\n", qrCode[QRCODE_SIZE - 2], qrCode[QRCODE_SIZE - 1]);
}