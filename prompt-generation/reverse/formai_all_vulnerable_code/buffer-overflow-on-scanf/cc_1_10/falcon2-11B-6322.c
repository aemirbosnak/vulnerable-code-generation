//Falcon2-11B DATASET v1.0 Category: QR code generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// function to convert binary string to decimal integer
int binaryToDecimal(char *binaryString) {
    int decimal = 0;
    int i;
    for (i = 0; i < strlen(binaryString); i++) {
        decimal += pow(2, strlen(binaryString) - i - 1) * (binaryString[i] - '0');
    }
    return decimal;
}

// function to generate QR code
void generateQRCode(char *text) {
    // calculate width and height of QR code
    int width = (4 * strlen(text)) + 6;
    int height = (4 * strlen(text)) + 6;

    // create a QR code matrix
    int qrCode[width][height];
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            qrCode[i][j] = 0;
        }
    }

    // fill in the QR code matrix with data
    int pos = 0;
    for (int i = 0; i < strlen(text); i++) {
        char binaryString[8] = "";
        sprintf(binaryString, "%03d", binaryToDecimal(text + i));
        for (int j = 0; j < strlen(binaryString); j++) {
            int bit = 0;
            if (binaryString[j] == '1') {
                bit = 1;
            }
            qrCode[pos][j] = bit;
            pos++;
        }
    }

    // print the QR code matrix
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (qrCode[i][j] == 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    char text[100];
    printf("Enter text to generate QR code: ");
    scanf("%s", text);
    generateQRCode(text);
    return 0;
}