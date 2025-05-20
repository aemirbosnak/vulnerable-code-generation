//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Convert Hexadecimal to Binary
void hexToBinary(char *hexString, int *binString, int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (hexString[i] >= '0' && hexString[i] <= '9') {
            *binString = *binString * 2 + (hexString[i] - '0');
        }
        else if (hexString[i] >= 'A' && hexString[i] <= 'F') {
            *binString = *binString * 2 + (hexString[i] - 'A' + 10);
        }
        else if (hexString[i] >= 'a' && hexString[i] <= 'f') {
            *binString = *binString * 2 + (hexString[i] - 'a' + 10);
        }
        else {
            printf("Invalid character: %c\n", hexString[i]);
            return;
        }
    }
}

// Convert Binary to Hexadecimal
void binaryToHex(int *binString, int length, char *hexString) {
    int i;
    for (i = 0; i < length; i++) {
        if (binString[i] < 10) {
            hexString[i] = binString[i];
        }
        else {
            hexString[i] = 'a' + binString[i] - 10;
        }
    }
}

int main() {
    char hexString[10] = "0x1a";
    int binString[10];
    int i;

    // Convert Hexadecimal to Binary
    hexToBinary(hexString, binString, 10);
    printf("Binary: ");
    for (i = 0; i < 10; i++) {
        printf("%d", binString[i]);
    }
    printf("\n");

    // Convert Binary to Hexadecimal
    binaryToHex(binString, 10, hexString);
    printf("Hexadecimal: ");
    for (i = 0; i < 10; i++) {
        printf("%c", hexString[i]);
    }
    printf("\n");

    return 0;
}