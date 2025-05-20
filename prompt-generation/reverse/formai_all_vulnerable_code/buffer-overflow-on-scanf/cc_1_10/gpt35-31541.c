//FormAI DATASET v1.0 Category: QR code generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_CODE_SIZE 25 // size of QR code
#define BLOCK_SIZE 8 // size of each block of QR code
#define WHITE ' ' // character to represent white
#define BLACK '#' // character to represent black

// Function to print QR code
void printQRCode(char qrCode[QR_CODE_SIZE][QR_CODE_SIZE]) {
    for(int i = 0; i < QR_CODE_SIZE; i++) {
        for(int j = 0; j < QR_CODE_SIZE; j++) {
            printf("%c", qrCode[i][j]);
        }
        printf("\n");
    }
}

// Function to generate QR code
void generateQRCode(char data[]) {
    // Initialize QR code to all white cells
    char qrCode[QR_CODE_SIZE][QR_CODE_SIZE];
    for(int i = 0; i < QR_CODE_SIZE; i++) {
        for(int j = 0; j < QR_CODE_SIZE; j++) {
            qrCode[i][j] = WHITE;
        }
    }

    // Add a border around QR code
    for(int i = 0; i < QR_CODE_SIZE; i++) {
        qrCode[0][i] = qrCode[i][0] = qrCode[QR_CODE_SIZE-1][i] = qrCode[i][QR_CODE_SIZE-1] = BLACK;
    }

    // Encode message in QR code using 8-bit block encoding
    int dataLength = strlen(data);
    int blockCount = dataLength / BLOCK_SIZE + (dataLength % BLOCK_SIZE ? 1 : 0); // calculate number of blocks required
    char block[blockCount][BLOCK_SIZE];
    for(int i = 0; i < dataLength; i++) {
        int blockIndex = i / BLOCK_SIZE;
        int charIndex = i % BLOCK_SIZE;
        block[blockIndex][charIndex] = data[i];
    }

    // Place blocks in QR code
    int x = 2, y = 2; // start placing blocks from (2,2)
    for(int i = 0; i < blockCount; i++) {
        char currentBlock[BLOCK_SIZE+1];
        strncpy(currentBlock, block[i], BLOCK_SIZE);
        currentBlock[BLOCK_SIZE] = '\0';

        // Place block in QR code
        for(int j = 0; j < BLOCK_SIZE; j++) {
            qrCode[x][y+j] = currentBlock[j] == '0' ? WHITE : BLACK; // place white cell for '0' and black cell for '1'
        }

        // Move to next block position
        y += BLOCK_SIZE; // move right by size of block
        if(y >= QR_CODE_SIZE-BLOCK_SIZE) { // if we have reached the right edge of QR code
            x += BLOCK_SIZE; // move down by size of block
            y = 2; // start from beginning of next row
        }
    }

    // Print QR code
    printQRCode(qrCode);
}

int main() {
    char data[100];
    printf("Enter data to encode in QR code: ");
    scanf("%s", data);

    // Generate QR code
    generateQRCode(data);

    return 0;
}