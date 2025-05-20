//FormAI DATASET v1.0 Category: QR code generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define QR_VERSIONS 40

// Structure for QR code data
typedef struct {
    uint8_t mode;
    uint8_t *data;
    uint32_t length;
} QRCodeData;

// Structure for QR code image
typedef struct {
    uint8_t **image;
    uint32_t size;
} QRCodeImage;

// Function to generate QR code data
QRCodeData generateQRCodeData(char *inputData) {
    QRCodeData qrCodeData;
    
    // Set mode to alphanumeric
    qrCodeData.mode = 2;
    
    // Calculate length of input data
    qrCodeData.length = strlen(inputData);
    
    // Allocate memory for data
    qrCodeData.data = (uint8_t *)malloc(qrCodeData.length * sizeof(uint8_t));
    
    // Convert input data to alphanumeric mode
    for (int i = 0; i < qrCodeData.length; i++) {
        qrCodeData.data[i] = inputData[i] + 45;
    }
    
    return qrCodeData;
}

// Function to generate QR code image
QRCodeImage generateQRCodeImage(QRCodeData qrCodeData, int qrVersion) {
    // QR code module size
    int moduleSize = 1;
    
    // Base size of QR code image
    int baseSize = (qrVersion - 1) * 4 + 21;
    
    // Size of QR code image
    int size = baseSize + 8;
    
    // Allocate memory for QR code image
    uint8_t **image = (uint8_t **)malloc(size * sizeof(uint8_t *));
    for (int i = 0; i < size; i++) {
        image[i] = (uint8_t *)malloc(size * sizeof(uint8_t));
    }
    
    // Initialize QR code image to white
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            image[i][j] = 255;
        }
    }
    
    // Add QR code data to image
    int bitCount = 0;
    int byteCount = 0;
    int bitBuffer = 0;
    int bitsRemaining = 0;
    int x = size - 1;
    int y = size - 1;
    uint8_t direction = 0;
    while (byteCount < qrCodeData.length) {
        int bit = qrCodeData.data[byteCount] & (1 << (7 - bitCount));
        if (bitCount == 7) {
            bitCount = 0;
            byteCount++;
        } else {
            bitCount++;
        }
        if (bitsRemaining == 0) {
            bitBuffer = 0;
            if (bit == 0) {
                bitsRemaining = 4;
            } else {
                bitsRemaining = 5;
            }
        }
        bitBuffer = (bitBuffer << 1) | bit;
        bitsRemaining--;
        if (bitsRemaining == 0) {
            int xPrev = x;
            int yPrev = y;
            switch (direction) {
                case 0:
                    y--;
                    break;
                case 1:
                    x--;
                    break;
                case 2:
                    y++;
                    break;
                case 3:
                    x++;
                    break;
            }
            if (image[yPrev][xPrev] == 255) {
                image[yPrev][xPrev] = moduleSize * 2;
            } else {
                image[yPrev][xPrev] = image[yPrev][xPrev] + moduleSize;
            }
            if (bitBuffer == 0x0f) {
                direction = (direction + 3) % 4;
            } else if (bitBuffer == 0x11) {
                direction = (direction + 1) % 4;
            } else if (bitBuffer == 0) {
                if (byteCount < qrCodeData.length) {
                    bitsRemaining = 4;
                }
            } else {
                for (int i = 0; i < 5; i++) {
                    int bit = bitBuffer & (1 << (4 - i));
                    if (bit != 0) {
                        if (image[y][x] == 255) {
                            image[y][x] = moduleSize * 2;
                        } else {
                            image[y][x] = image[y][x] + moduleSize;
                        }
                    }
                    switch (direction) {
                        case 0:
                            y--;
                            break;
                        case 1:
                            x--;
                            break;
                        case 2:
                            y++;
                            break;
                        case 3:
                            x++;
                            break;
                    }
                }
            }
        }
    }
    
    QRCodeImage qrCodeImage = {
        .image = image,
        .size = size
    };
    return qrCodeImage;
}

// Function to print QR code image
void printQRCodeImage(QRCodeImage qrCodeImage) {
    printf("\n");
    for (int i = 0; i < qrCodeImage.size; i++) {
        for (int j = 0; j < qrCodeImage.size; j++) {
            if (qrCodeImage.image[i][j] == 0) {
                printf("  ");
            } else {
                printf("%c%c", 219, 219);
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    char inputData[100];
    int qrVersion = 1;
    while (qrVersion < 1 || qrVersion > QR_VERSIONS) {
        printf("Enter QR code version (1-40): ");
        scanf("%d", &qrVersion);
        if (qrVersion < 1 || qrVersion > QR_VERSIONS) {
            printf("Invalid QR code version!\n");
        }
    }
    printf("Enter input data: ");
    scanf("%s", inputData);
    QRCodeData qrCodeData = generateQRCodeData(inputData);
    QRCodeImage qrCodeImage = generateQRCodeImage(qrCodeData, qrVersion);
    printQRCodeImage(qrCodeImage);
    return 0;
}