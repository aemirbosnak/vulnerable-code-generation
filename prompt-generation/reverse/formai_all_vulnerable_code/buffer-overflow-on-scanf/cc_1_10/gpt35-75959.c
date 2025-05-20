//FormAI DATASET v1.0 Category: QR code reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct QRCode {
    char data[256];
};

bool isValidQRCode(char *qrCode) {
    int len = strlen(qrCode);
    if (len != 25) {
        return false;
    }
    for(int i = 0; i < len; i++) {
        if (i < 5) {
            if (qrCode[i] != 'A') {
                return false;
            }
        } else if (i >= 5 && i < 10) {
            if (qrCode[i] != 'B') {
                return false;
            }
        } else if (i >= 10 && i < 15) {
            if (qrCode[i] != 'C') {
                return false;
            }
        } else if (i >= 15 && i < 20) {
            if (qrCode[i] != 'D') {
                return false;
            }
        } else {
            if (qrCode[i] != 'E') {
                return false;
            }
        }
    }
    return true;
}

void decodeQRCode(struct QRCode *qrCode) {
    printf("Decoded QR code: %s\n", qrCode->data);
}

void readQRCode() {
    printf("Ready to scan QR code...\n");
    char input[256];
    scanf("%s", input);
    if (isValidQRCode(input)) {
        struct QRCode qrCode;
        strcpy(qrCode.data, input);
        decodeQRCode(&qrCode);
    } else {
        printf("Invalid QR code.\n");
    }
}

int main() {
    printf("Welcome to the QR code reader!\n");
    while (true) {
        printf("Press any key to scan a QR code, or 'q' to quit.\n");
        char choice;
        scanf("%c", &choice);
        if (choice == 'q') {
            break;
        } else {
            readQRCode();           
        }
    }
    printf("Goodbye!\n");
    return 0;
}