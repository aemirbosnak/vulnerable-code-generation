//FormAI DATASET v1.0 Category: QR code reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct qrcode {
    int version;
    char mode[5];
    char data[2000];
    int eclevel;
    char mask[3];
} QRCode;

bool checkFormat(QRCode qrdata) {
    // Check the correct format of the data
    if (strlen(qrdata.mode) != 4) {
        return false;
    }
    if (strlen(qrdata.mask) != 2) {
        return false;
    }
    if (qrdata.eclevel < 0 || qrdata.eclevel > 3) {
        return false;
    }
    return true;
}

void printQRData(QRCode qrdata) {
    // Print all the relevant data of the QR code
    printf("QR Version: %d\n", qrdata.version);
    printf("QR Mode: %s\n", qrdata.mode);
    printf("QR Data: %s\n", qrdata.data);
    printf("QR Error Correction Level: %d\n", qrdata.eclevel);
    printf("QR Mask: %s\n", qrdata.mask);
}

void decodeQRCode(char* qrstring) {
    // Decode the QR code from string input
    QRCode qrcode;
    qrcode.version = qrstring[0] - '0'; // Version number is first character in string

    char mode[5];
    strncpy(mode, qrstring + 1, 4); // Mode is the next 4 characters after version number
    mode[4] = '\0'; // Null-terminate the mode string
    strcpy(qrcode.mode, mode);

    char data[2000];
    int dataStartIndex = 5; // Data starts after mode
    int dataIndex = 0;
    while (qrstring[dataStartIndex] != '\0') {
        data[dataIndex] = qrstring[dataStartIndex];
        dataIndex++;
        dataStartIndex++;
    }
    data[dataIndex] = '\0'; // Null-terminate the data string
    strcpy(qrcode.data, data);

    char eclevel[2];
    eclevel[0] = qrstring[strlen(qrstring) - 2]; // Error correction level is second to last character in string
    eclevel[1] = '\0'; // Null-terminate the error correction level string
    qrcode.eclevel = atoi(eclevel);

    char mask[3];
    mask[0] = qrstring[strlen(qrstring) - 1]; // Mask is last character in string
    mask[1] = '\0'; // Null-terminate the mask string
    strcpy(qrcode.mask, mask);

    if (checkFormat(qrcode)) {
        printQRData(qrcode);
    }
    else {
        printf("Invalid QR code format.\n");
    }
}

int main() {
    // Example usage of the QR code reader
    char qrstring[2000];
    printf("Enter a QR code string: ");
    scanf("%s", qrstring);
    decodeQRCode(qrstring);

    return 0;
}