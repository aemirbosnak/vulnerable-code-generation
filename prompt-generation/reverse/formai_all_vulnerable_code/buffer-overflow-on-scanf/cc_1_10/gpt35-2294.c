//FormAI DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hexToDec(char hex[]) {
    int len = strlen(hex);
    int base = 1;
    int dec = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - 48) * base;
            base = base * 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 55) * base;
            base = base * 16;
        }
    }

    return dec;
}

// Function to convert decimal to hexadecimal
void decToHex(int dec, char hex[]) {
    char hexChars[] = "0123456789ABCDEF";
    int quotient = dec;
    int remainder = 0;
    int i = 0;

    while (quotient != 0) {
        remainder = quotient % 16;
        hex[i] = hexChars[remainder];
        i++;
        quotient = quotient / 16;
    }

    // Reverse the characters in the hexadecimal string
    int len = strlen(hex);
    char temp;

    for (int j = 0; j < len / 2; j++) {
        temp = hex[j];
        hex[j] = hex[len - j - 1];
        hex[len - j - 1] = temp;
    }
}

int main() {
    char colorInHex[7];
    char rHex[3];
    char gHex[3];
    char bHex[3];

    printf("Enter a color in hexadecimal format (RRGGBB): ");
    scanf("%s", colorInHex);

    // Separate the different components of the color code
    strncpy(rHex, colorInHex, 2);
    rHex[2] = '\0';

    strncpy(gHex, colorInHex + 2, 2);
    gHex[2] = '\0';

    strncpy(bHex, colorInHex + 4, 2);
    bHex[2] = '\0';

    // Convert each component from hexadecimal to decimal
    int red = hexToDec(rHex);
    int green = hexToDec(gHex);
    int blue = hexToDec(bHex);

    printf("RGB color values: %d,%d,%d\n", red, green, blue);

    // Convert each component from decimal to hexadecimal
    char rHexNew[3];
    char gHexNew[3];
    char bHexNew[3];

    decToHex(red, rHexNew);
    decToHex(green, gHexNew);
    decToHex(blue, bHexNew);

    // Output the color code in hexadecimal format
    printf("New color code in hexadecimal format: #%s%s%s\n", rHexNew, gHexNew, bHexNew);

    return 0;
}