//FormAI DATASET v1.0 Category: QR code generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_CODE_SIZE 21 // Size of generated QR code (number of pixels in each row/column)

typedef enum { false, true } bool;

bool qrCodeBoard[QR_CODE_SIZE][QR_CODE_SIZE]; // QR code board array 
char encodedData[256]; // User data array to be encoded
int dataSize; // Size of user data

// Function to set QR code pixel to true or false
void setQRCodePixel(int x, int y, bool value) {
    qrCodeBoard[x][y] = value;
}

// Function to print QR code board
void printQRCodeBoard() {
    for(int i = 0; i < QR_CODE_SIZE; i++) {
        for(int j = 0; j < QR_CODE_SIZE; j++) {
            printf("%c ", qrCodeBoard[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the QR code generator!\n\n");

    // Get user data to be encoded
    printf("Enter data to be encoded (maximum 255 characters):\n");
    fgets(encodedData, sizeof(encodedData), stdin);
    dataSize = strlen(encodedData) - 1;
    encodedData[dataSize] = '\0';

    // Set first 3 pixels of QR code as true to identify it as a QR code
    setQRCodePixel(0, 0, true);
    setQRCodePixel(0, 1, true);
    setQRCodePixel(1, 0, true);

    // Encode data into QR code
    for(int i = 0; i < dataSize; i++) {
        int asciiValue = (int)encodedData[i]; // Get ASCII value of character
        for(int j = 0; j < 8; j++) {
            int bitValue = (asciiValue >> j) & 1; // Get bit value of character at index j
            setQRCodePixel(j + 2, i, bitValue ? true : false); // Set corresponding pixel in QR code board
        }
    }

    // Print QR code board
    printf("\nGenerated QR code:\n");
    printQRCodeBoard();

    return 0;
}