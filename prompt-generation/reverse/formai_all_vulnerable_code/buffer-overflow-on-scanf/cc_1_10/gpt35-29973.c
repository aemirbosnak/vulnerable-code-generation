//FormAI DATASET v1.0 Category: QR code reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QR_CODE_LENGTH 100

bool validateQRCode(char *qrCode) {
    // validate QR code length
    if (strlen(qrCode) != MAX_QR_CODE_LENGTH) {
        return false;
    }

    // check for valid QR code format
    for (int i = 0; i < MAX_QR_CODE_LENGTH; i++) {
        if (qrCode[i] != '0' && qrCode[i] != '1') {
            return false;
        }
    }

    return true;
}

int decodeQRCode(char *qrCode) {
    int decodedValue = 0;

    // convert QR code from binary to decimal
    for (int i = MAX_QR_CODE_LENGTH - 1; i >= 0; i--) {
        if (qrCode[i] == '1') {
            decodedValue += pow(2, MAX_QR_CODE_LENGTH - i - 1);
        }
    }

    return decodedValue;
}

int main() {
    char qrCode[MAX_QR_CODE_LENGTH+1];
    int decodedValue;

    printf("Enter QR code:\n");
    scanf("%s", qrCode);

    if (!validateQRCode(qrCode)) {
        printf("Invalid QR code format.\n");
        return EXIT_FAILURE;
    }

    decodedValue = decodeQRCode(qrCode);

    printf("Decoded value: %d\n", decodedValue);

    return EXIT_SUCCESS;
}