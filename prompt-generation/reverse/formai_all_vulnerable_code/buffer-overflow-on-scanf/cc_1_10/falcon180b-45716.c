//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hexToDec(char hex[]) {
    int decimal = 0, base = 1, len = strlen(hex);
    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(hex[i])) {
            decimal += (hex[i] - '0') * base;
        } else {
            switch (hex[i]) {
                case 'A':
                    decimal += 10 * base;
                    break;
                case 'B':
                    decimal += 11 * base;
                    break;
                case 'C':
                    decimal += 12 * base;
                    break;
                case 'D':
                    decimal += 13 * base;
                    break;
                case 'E':
                    decimal += 14 * base;
                    break;
                case 'F':
                    decimal += 15 * base;
                    break;
            }
        }
        base *= 16;
    }
    return decimal;
}

// Function to convert decimal to hexadecimal
void decToHex(int dec, char hex[]) {
    int base = 16, remainder, i = 0;
    while (dec!= 0) {
        remainder = dec % base;
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder + 'A' - 10;
        }
        dec /= base;
        i++;
    }
    hex[i] = '\0';
}

int main() {
    char hex[100];
    int decimal;

    // Prompt user for input
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // Convert hexadecimal to decimal
    decimal = hexToDec(hex);

    // Convert decimal to hexadecimal
    decToHex(decimal, hex);

    // Print the results
    printf("Decimal equivalent: %s\n", hex);
    return 0;
}