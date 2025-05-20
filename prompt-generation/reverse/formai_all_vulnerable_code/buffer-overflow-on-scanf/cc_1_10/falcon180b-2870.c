//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: systematic
/* QR Code Generator in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000 // Maximum size of QR code
#define MAX_DATA 4296 // Maximum data that can be encoded

// Struct to hold QR code data
typedef struct {
    int size; // Size of QR code
    int data[MAX_DATA]; // Data to be encoded
} QRCode;

// Function to generate QR code
void generateQRCode(QRCode *qrCode) {
    // Initialize QR code with minimum size
    qrCode->size = 1;

    // Add data to QR code
    int i = 0;
    while (i < qrCode->data[0]) {
        int j = 0;
        while (j < 8 && i < qrCode->data[0]) {
            int bit = qrCode->data[i] & (1 << j);
            if (bit) {
                int x = (i % 3) * 10 + j;
                int y = (i / 3) * 10 + j;
                if (x < qrCode->size && y < qrCode->size) {
                    qrCode->data[(y - 1) * qrCode->size + x - 1] = 1;
                }
            }
            j++;
        }
        i++;
    }
}

// Function to print QR code
void printQRCode(QRCode *qrCode) {
    int i, j;
    for (i = 0; i < qrCode->size; i++) {
        for (j = 0; j < qrCode->size; j++) {
            if (qrCode->data[(i - 1) * qrCode->size + j - 1]) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

// Function to read input data
void readInput(QRCode *qrCode) {
    printf("Enter data to be encoded: ");
    scanf("%s", qrCode->data);
    qrCode->data[0] = strlen(qrCode->data);
}

// Main function
int main() {
    QRCode qrCode;

    // Read input data
    readInput(&qrCode);

    // Generate QR code
    generateQRCode(&qrCode);

    // Print QR code
    printf("QR Code:\n");
    printQRCode(&qrCode);

    return 0;
}