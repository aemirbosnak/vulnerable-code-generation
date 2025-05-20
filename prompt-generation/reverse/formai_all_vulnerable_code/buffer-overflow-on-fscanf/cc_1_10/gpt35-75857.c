//FormAI DATASET v1.0 Category: QR code reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 30

// Struct to hold the QR code data
typedef struct {
    int version;
    int size;
    char data[WIDTH][HEIGHT];
} QRCode;

// Function to read QR code from file and return QRCode struct
QRCode readQRCodeFromFile(const char* filename) {
    QRCode qrCode;
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("File not found.");
        exit(1);
    }
    fscanf(file, "%d,%d\n", &qrCode.version, &qrCode.size);
    for(int i = 0; i < qrCode.size; i++) {
        for(int j = 0; j < qrCode.size; j++) {
            char c = fgetc(file);
            if(c == EOF || c == '\n') {
                printf("Error reading QR code data.");
                exit(1);
            }
            qrCode.data[j][i] = c;
        }
        fgetc(file); // Skip the newline character
    }
    fclose(file);
    return qrCode;
}

// Function to print QR code data to console
void printQRCode(QRCode qrCode) {
    for(int i = 0; i < qrCode.size; i++) {
        for(int j = 0; j < qrCode.size; j++) {
            printf("%c", qrCode.data[j][i]);
        }
        printf("\n");
    }
}

// Function to detect if a QR code is valid
bool isQRCodeValid(QRCode qrCode) {
    // Version must be between 1 and 40
    if(qrCode.version < 1 || qrCode.version > 40) {
        return false;
    }
    // Size must be between 21 and 177
    if(qrCode.size < 21 || qrCode.size > 177) {
        return false;
    }
    // Check if alternating pattern is correct
    char pattern[] = {' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'};
    for(int i = 0; i < 16; i++) {
        char expected = pattern[i];
        char actual = qrCode.data[i][8];
        if(expected != actual) {
            return false;
        }
        expected = pattern[i];
        actual = qrCode.data[8][i];
        if(expected != actual) {
            return false;
        }
    }
    return true;
}

// Main function to read QR code and print validity
int main() {
    QRCode qrCode = readQRCodeFromFile("qrcode.txt");
    printf("QR Code version: %d\n", qrCode.version);
    printf("QR Code size: %d\n", qrCode.size);
    printf("QR Code data:\n");
    printQRCode(qrCode);
    bool isValid = isQRCodeValid(qrCode);
    if(isValid) {
        printf("QR Code is valid.\n");
    } else {
        printf("QR Code is invalid.\n");
    }
    return 0;
}