//FormAI DATASET v1.0 Category: QR code reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_QR_CODE_SIZE 200

// Function to check if a given string is a valid QR code
bool isValidQRCode(char* qrCodeString) {
    int len = strlen(qrCodeString);

    // Check if string starts with "QR:"
    if (strncmp(qrCodeString, "QR:", 3) != 0) {
        return false;
    }

    // Check if string has valid characters
    for (int i = 3; i < len; i++) {
        if (!isalnum(qrCodeString[i])) {
            return false;
        }
    }

    // Check if string has valid length
    if (len > MAX_QR_CODE_SIZE) {
        return false;
    }

    // String is a valid QR code
    return true;
}

// Main function to read a QR code and print its contents
int main() {
    // Initialize variables
    char qrCodeString[MAX_QR_CODE_SIZE + 1];
    char qrCodeContents[MAX_QR_CODE_SIZE + 1];
    int i = 0;

    // Read QR code string from user
    printf("Please enter a QR code: ");
    scanf("%s", qrCodeString);

    // Check if string is a valid QR code
    if (!isValidQRCode(qrCodeString)) {
        printf("Invalid QR code!\n");
        return 1;
    }

    // If string is a valid QR code, extract its contents
    for (i = 3; i < strlen(qrCodeString); i++) {
        qrCodeContents[i - 3] = qrCodeString[i];
    }
    qrCodeContents[i - 3] = '\0';

    // Print QR code contents
    printf("QR code contents: %s\n", qrCodeContents);

    return 0;
}