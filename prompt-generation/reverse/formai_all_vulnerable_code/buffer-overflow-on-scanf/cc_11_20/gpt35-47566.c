//FormAI DATASET v1.0 Category: QR code reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Welcome to the QR Code Reader!\n\n");

    // Variables
    int qrCode[21][21];
    int qrSize;
    int row, col;

    // Get QR Code size
    printf("Enter QR Code size (between 1 and 21): ");
    scanf("%d", &qrSize);

    // Get QR Code
    printf("Enter QR Code (0 for white, 1 for black):\n");
    for (row = 0; row < qrSize; row++) {
        printf("Row %d: ", row+1);
        for (col = 0; col < qrSize; col++) {
            scanf("%d", &qrCode[row][col]);
        }
    }

    // Check QR Code format
    if (qrSize < 1 || qrSize > 21) {
        printf("Invalid QR Code size!\n");
        return 0;
    }
    if (qrCode[0][0] != 1 || qrCode[qrSize-1][0] != 1 || qrCode[0][qrSize-1] != 1) {
        printf("Invalid QR Code format! Missing finder patterns.\n");
        return 0;
    }

    // Print QR Code
    printf("\nQR Code:\n");
    for (row = 0; row < qrSize; row++) {
        for (col = 0; col < qrSize; col++) {
            if (qrCode[row][col] == 1) {
                printf("████");
            }
            else {
                printf("    ");
            }
        }
        printf("\n");
    }

    printf("\nQR Code successfully read! Now what? I am a code, I have no idea :P\n");

    return 0;
}