//FormAI DATASET v1.0 Category: QR code reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define global variables
#define MAX_WIDTH 200
#define MAX_HEIGHT 200

// Define a struct to represent a QR code
typedef struct qrcode {
    int width;
    int height;
    int data[MAX_WIDTH][MAX_HEIGHT];
} QRCode;

// Function to read a QR code from a file
QRCode readQRCode(char *filename) {
    QRCode qr;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file. Could not read QR code.\n");
        exit(1);
    }
    // Read in the width and height of the QR code
    fscanf(fp, "%d,%d", &qr.width, &qr.height);
    // Read in the data of the QR code
    for (int i = 0; i < qr.height; i++) {
        for (int j = 0; j < qr.width; j++) {
            fscanf(fp, "%d", &qr.data[i][j]);
        }
    }
    fclose(fp);
    return qr;
}

// Function to print out the QR code data
void printQRCode(QRCode qr) {
    printf("QR Code:\n");
    for (int i = 0; i < qr.height; i++) {
        for (int j = 0; j < qr.width; j++) {
            printf("%d ", qr.data[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a QR code is valid
bool isValidQRCode(QRCode qr) {
    // Check if the QR code is square
    if (qr.width != qr.height) {
        printf("QR code is not square. Invalid.\n");
        return false;
    }
    // Check if the QR code is at least 21x21 pixels
    if (qr.width < 21) {
        printf("QR code is too small. Invalid.\n");
        return false;
    }
    // Check if the top-left pixel is black
    if (qr.data[0][0] != 0) {
        printf("Top-left pixel is not black. Invalid.\n");
        return false;
    }
    // Check if the top-right and bottom-left pixels are white
    if (qr.data[0][qr.width-1] != 1 || qr.data[qr.height-1][0] != 1) {
        printf("Top-right or bottom-left pixel is not white. Invalid.\n");
        return false;
    }
    return true;
}

int main() {
    char *filename = "qrcode.txt";
    QRCode qr = readQRCode(filename);
    printQRCode(qr);
    if (isValidQRCode(qr)) {
        printf("QR code is valid.\n");
    }
    else {
        printf("QR code is invalid.\n");
    }
    return 0;
}