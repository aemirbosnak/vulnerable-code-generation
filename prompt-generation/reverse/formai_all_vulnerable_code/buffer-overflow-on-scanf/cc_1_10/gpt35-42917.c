//FormAI DATASET v1.0 Category: QR code reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct to hold QR code data.
typedef struct {
    int version;
    char mode;
    char *data;
} QRCode;

// Function to extract QR code data from provided string.
QRCode* extractQRCodeData(char *qrCodeString) {
    // Allocate memory for QR code struct.
    QRCode *qrCode = malloc(sizeof(QRCode));
    qrCode->data = NULL;
    // Extract mode and version from string.
    sscanf(qrCodeString, "%d%c", &qrCode->version, &qrCode->mode);
    // Move pointer to the beginning of the data.
    while (*qrCodeString != ',') {
        qrCodeString++;
    }
    qrCodeString++;
    // Get length of data and allocate memory for it.
    int dataLength = strlen(qrCodeString);
    qrCode->data = malloc(sizeof(char) * dataLength);
    // Copy data into QR code struct.
    strcpy(qrCode->data, qrCodeString);
    return qrCode;
}

// Function to print QR code data.
void printQRCodeData(QRCode *qrCode) {
    printf("Version: %d\n", qrCode->version);
    printf("Mode: %c\n", qrCode->mode);
    printf("Data: %s\n", qrCode->data);
}

int main() {
    char qrCodeString[100];
    printf("Enter QR code: ");
    scanf("%s", qrCodeString);
    // Validate QR code string.
    char validModes[] = {'M', 'Q', 'H', 'L'};
    if (strlen(qrCodeString) < 3 || !isdigit(qrCodeString[0]) || !strchr(validModes, toupper(qrCodeString[1]))) {
        printf("Invalid QR code.\n");
        return 1;
    }
    QRCode *qrCode = extractQRCodeData(qrCodeString);
    printQRCodeData(qrCode);
    // Free memory allocated for QR code data.
    free(qrCode->data);
    free(qrCode);
    return 0;
}