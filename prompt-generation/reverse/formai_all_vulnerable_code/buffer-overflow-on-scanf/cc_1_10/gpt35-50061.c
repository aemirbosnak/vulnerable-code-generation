//FormAI DATASET v1.0 Category: QR code reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the structure of the QR code
typedef struct {
    char data[50];
} QRCode;

// Declare the structure of the scanner
typedef struct {
    QRCode *codes;
    int size;
} QRScanner;

// Function to initialize the QR scanner
void initQRScanner(QRScanner *scanner, int size) {
    scanner->codes = (QRCode*)malloc(size * sizeof(QRCode));
    scanner->size = size;
}

// Function to read the QR code and store it in the scanner
void readQRCode(QRScanner *scanner, int codeIndex, char* codeString) {
    if (codeIndex >= 0 && codeIndex < scanner->size) {
        QRCode qrCode;
        strcpy(qrCode.data, codeString);
        scanner->codes[codeIndex] = qrCode;
    }
}

// Function to print all the QR codes in the scanner
void printQRCodes(QRScanner *scanner) {
    for (int i = 0; i < scanner->size; i++) {
        if (strlen(scanner->codes[i].data) > 0)
            printf("QR Code %d: %s\n", i+1, scanner->codes[i].data);
        else
            printf("QR Code %d: EMPTY\n", i+1);
    }
}

int main() {
    // Initialize the QR scanner with a size of 5
    QRScanner scanner;
    initQRScanner(&scanner, 5);

    // Print the introduction message
    printf("Welcome to the QR Code scanner!\n");

    // Start reading in the QR codes
    char codeString[50];
    for (int i = 0; i < scanner.size; i++) {
        printf("Please scan QR code %d: ", i+1);
        scanf("%s", codeString);
        readQRCode(&scanner, i, codeString);
    }

    // Print all the QR codes
    printf("\nAll QR codes scanned:\n");
    printQRCodes(&scanner);

    // Clean up the memory used by the QR scanner
    free(scanner.codes);

    return 0;
}