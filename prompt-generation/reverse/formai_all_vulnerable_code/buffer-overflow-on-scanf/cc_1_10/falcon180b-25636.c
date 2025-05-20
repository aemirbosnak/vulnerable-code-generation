//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

// Function to convert hexadecimal string to decimal
int hexToDec(char* hexStr) {
    int len = strlen(hexStr);
    int dec = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(hexStr[i])) {
            dec = dec * 16 + hexStr[i] - '0';
        } else if (isalpha(hexStr[i])) {
            if (hexStr[i] >= 'A') {
                dec = dec * 16 + hexStr[i] - 'A' + 10;
            } else {
                dec = dec * 16 + hexStr[i] - 'a' + 10;
            }
        } else {
            return -1;
        }
    }
    return dec;
}

// Function to convert decimal to hexadecimal
void decToHex(int dec, char* hexStr) {
    char hex[MAX_LEN];
    int len = 0;
    while (dec > 0) {
        if (dec % 16 < 10) {
            hex[len++] = dec % 16 + '0';
        } else {
            hex[len++] = dec % 16 + 'A' - 10;
        }
        dec /= 16;
    }
    strcpy(hexStr, &hex[len - 1]);
}

// Function to convert RGB to hexadecimal
void rgbToHex(int r, int g, int b, char* hexStr) {
    sprintf(hexStr, "#%02X%02X%02X", r, g, b);
}

// Function to convert hexadecimal to RGB
void hexToRgb(char* hexStr, int* r, int* g, int* b) {
    if (strlen(hexStr)!= 7) {
        printf("Invalid hexadecimal string\n");
        return;
    }
    *r = hexToDec(&hexStr[1]) * 16 + hexToDec(&hexStr[3]);
    *g = hexToDec(&hexStr[5]) * 16 + hexToDec(&hexStr[7]);
    *b = hexToDec(&hexStr[9]) * 16 + hexToDec(&hexStr[11]);
}

int main() {
    char hexStr[MAX_LEN];
    int dec, r, g, b;
    printf("Enter a hexadecimal string: ");
    scanf("%s", hexStr);
    dec = hexToDec(hexStr);
    if (dec == -1) {
        printf("Invalid hexadecimal string\n");
    } else {
        printf("Decimal value: %d\n", dec);
        rgbToHex(dec / (256 * 256), (dec / 256) % 256, dec % 256, hexStr);
        printf("RGB value: %s\n", hexStr);
        hexToRgb(hexStr, &r, &g, &b);
        printf("RGB values: %d %d %d\n", r, g, b);
    }
    return 0;
}