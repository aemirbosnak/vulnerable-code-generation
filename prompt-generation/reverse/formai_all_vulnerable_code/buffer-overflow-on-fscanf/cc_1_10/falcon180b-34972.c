//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to convert binary string to decimal
int binaryToDecimal(char *binary) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary);

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += (int)pow(2, power);
        }
        power++;
    }

    return decimal;
}

// Function to read QR code and return binary string
char *readQRCode(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char *binary = malloc(10000 * sizeof(char));
    int binaryLength = 0;

    while (fscanf(file, "%c", &binary[binaryLength])!= EOF) {
        binaryLength++;
    }

    fclose(file);

    return binary;
}

// Function to decode QR code and return message
void decodeQRCode(char *binary) {
    int version = binaryToDecimal(binary);
    int errorCorrectionLevel = (binary[2] - '0') * 10 + (binary[3] - '0');

    printf("Version: %d\n", version);
    printf("Error correction level: %d\n", errorCorrectionLevel);
}

int main() {
    char *filename = "qrcode.txt";
    char *binary = readQRCode(filename);
    decodeQRCode(binary);

    return 0;
}