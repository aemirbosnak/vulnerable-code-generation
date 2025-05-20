//FormAI DATASET v1.0 Category: QR code reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check whether a given string is a valid QR code
bool isValidQRCode(char* qrCode) {
    // Check if the length is correct
    if (strlen(qrCode) != 25) {
        return false;
    }
    // Check if the prefix is correct
    if (strncmp(qrCode, "CQR-", 4) != 0) {
        return false;
    }
    // Check if the suffix is correct
    if (strcmp(qrCode + 21, "-CQR") != 0) {
        return false;
    }
    // Check if the remaining characters are digits
    for (int i = 4; i < 21; i++) {
        if (!isdigit(qrCode[i])) {
            return false;
        }
    }
    // If all checks pass, the QR code is valid
    return true;
}

// Function to read a QR code from the user and check if it is valid
void readQRCode() {
    char qrCode[26];
    printf("Please enter a CQR code: ");
    scanf("%s", qrCode);
    if (isValidQRCode(qrCode)) {
        printf("Valid CQR code!\n");
    } else {
        printf("Invalid CQR code :(\n");
    }
}

// Main function to run the program
int main() {
    printf("Welcome to the CQR code reader!\n\n");
    printf("Instructions:\n");
    printf("- CQR codes must be 25 characters long\n");
    printf("- CQR codes must begin with 'CQR-'\n");
    printf("- CQR codes must end with '-CQR'\n");
    printf("- The characters in between must all be digits\n\n");
    // Keep prompting the user for a QR code until they enter one that is valid
    while (true) {
        readQRCode();
    }
    return 0;
}