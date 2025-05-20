//FormAI DATASET v1.0 Category: QR code reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

// Function to display QR code
void displayQRCode(int qrCode[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (qrCode[i][j] == 1) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

// Function to scan and read QR code
bool readQRCode(int qrCode[MAX][MAX], int size) {
    char data[size*size+1];
    printf("Scan QR Code (Enter %d digits - 0 or 1): ", size*size);
    scanf("%s", data);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (data[i*size+j] == '0') {
                qrCode[i][j] = 0;
            } else if (data[i*size+j] == '1') {
                qrCode[i][j] = 1;
            } else {
                printf("Invalid QR Code!\n");
                return false;
            }
        }
    }
    return true;
}

// Function to check if QR code is valid
bool isValidQRCode(int qrCode[MAX][MAX], int size) {
    // Check if patterns are present in the QR code
    for (int i = 0; i < 7; i++) {
        if (qrCode[i][0] != 0 || qrCode[i][size-1] != 0 ||
            qrCode[size-7+i][0] != 0 || qrCode[size-7+i][6] != 0 ||
            qrCode[0][i] != 0 || qrCode[size-1][size-7+i] != 0) {
            return false;
        }
    }
    for (int i = 0; i < 8; i++) {
        if (qrCode[size-8][i] != 0 || qrCode[i][size-8] != 0) {
            return false;
        }
    }
    if (qrCode[size-8][8] != 0) {
        return false;
    }
    // Check if timing patterns are present in the QR code
    for (int i = 8; i < size-8; i++) {
        if (qrCode[6][i] != (i%2) || qrCode[i][6] != (i%2)) {
            return false;
        }
    }
    // Check if dark module is present in the QR code
    if (qrCode[size-8][size-8] != 1) {
        return false;
    }
    // Check if all data and error correction codewords are present in the QR code
    for (int i = 0; i < size-8; i++) {
        for (int j = 0; j < size-8; j++) {
            if (qrCode[i][j] != 0 && qrCode[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Initialize QR code array with all 0s
    int qrCode[MAX][MAX] = {0};
    int size;
    printf("Enter the size of the QR code: ");
    scanf("%d", &size);
    if (size < 21 || size%4 != 1) {
        printf("Invalid QR Code size!\n");
        return 0;
    }
    // Read QR code from user input
    if (!readQRCode(qrCode, size)) {
        return 0;
    }
    // Display QR code
    printf("\nQR Code:\n");
    displayQRCode(qrCode, size);
    // Check if QR code is valid
    if (isValidQRCode(qrCode, size)) {
        printf("\nValid QR Code!\n");
    } else {
        printf("\nInvalid QR Code!\n");
    }
    return 0;
}