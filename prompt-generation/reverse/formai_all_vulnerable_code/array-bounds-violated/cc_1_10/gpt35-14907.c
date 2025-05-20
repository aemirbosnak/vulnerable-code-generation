//FormAI DATASET v1.0 Category: QR code reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to check if a string is a valid QR code format
bool isValidQRCode(char* qrCode) {
    if (strlen(qrCode) != 11) {
        return false;
    }
    if (qrCode[0] != 'C' || qrCode[1] != '-') {
        return false;
    }
    for (int i = 2; i < 11; i++) {
        if (qrCode[i] < '0' || qrCode[i] > '9') {
            return false;
        }
    }
    return true;
}

// Function to read QR code and return the numeric value
int readQRCode(char* qrCode) {
    if (!isValidQRCode(qrCode)) {
        return -1;
    }
    int value = 0;
    for (int i = 2; i < 11; i++) {
        value = value * 10 + (qrCode[i] - '0');
    }
    return value;
}

// Main function
int main() {
    char qrCode[MAX_LENGTH];
    printf("Enter the QR code: ");
    fgets(qrCode, MAX_LENGTH, stdin);
    // Remove newline character if present
    if (qrCode[strlen(qrCode) - 1] == '\n') {
        qrCode[strlen(qrCode) - 1] = '\0';
    }
    int value = readQRCode(qrCode);
    if (value == -1) {
        printf("Invalid QR code!\n");
        return -1;
    }
    printf("QR code value: %d\n", value);
    return 0;
}