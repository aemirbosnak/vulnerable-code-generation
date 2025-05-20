//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert hexadecimal to decimal
int hexToDec(char hex) {
    if (isdigit(hex)) {
        return hex - '0';
    } else {
        return toupper(hex) - 'A' + 10;
    }
}

// Function to convert decimal to hexadecimal
char decToHex(int dec) {
    char hex[2];
    sprintf(hex, "%X", dec);
    return hex[0];
}

// Function to convert RGB to hexadecimal
void rgbToHex(int r, int g, int b, char hex[7]) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

// Function to convert hexadecimal to RGB
void hexToRgb(char hex[7], int *r, int *g, int *b) {
    int len = strlen(hex);
    if (len == 4) {
        *r = hexToDec(hex[1]) * 16 + hexToDec(hex[2]);
        *g = hexToDec(hex[3]) * 16 + hexToDec(hex[4]);
        *b = hexToDec(hex[5]) * 16 + hexToDec(hex[6]);
    } else if (len == 7) {
        *r = hexToDec(hex[1]) * 16 + hexToDec(hex[2]);
        *g = hexToDec(hex[3]) * 16 + hexToDec(hex[4]);
        *b = hexToDec(hex[5]) * 16 + hexToDec(hex[6]);
    } else {
        printf("Invalid hexadecimal color code.\n");
        exit(1);
    }
}

int main() {
    char hex[7];
    int r, g, b;
    printf("Enter a hexadecimal color code (e.g. #FF0000): ");
    scanf("%s", hex);
    hexToRgb(hex, &r, &g, &b);
    printf("RGB: %d %d %d\n", r, g, b);
    return 0;
}