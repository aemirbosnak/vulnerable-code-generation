//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* 
 * Function: hexToDec 
 * Converts hexadecimal number to decimal number
 * 
 * char* hex: hexadecimal number to be converted
 *
 * return: integer value of hexadecimal number in decimal format
 */
int hexToDec(char* hex) {
    int len = strlen(hex);
    int base = 1;
    int decimal = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 'a' + 10) * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base;
        }
        base *= 16;
    }

    return decimal;
}

/* 
 * Function: decToHex 
 * Converts decimal number to hexadecimal number
 * 
 * int decimal: decimal number to be converted
 *
 * return: hexadecimal value of decimal number in string format
 */
char* decToHex(int decimal) {
    char* hex = malloc(sizeof(char) * 100);
    int i = 0;

    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i] = remainder + 48;
        } else {
            hex[i] = remainder + 55;
        }
        i++;
        decimal /= 16;
    }

    // Reverse hex
    int len = strlen(hex);
    for (int j = 0; j < len / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[len - j - 1];
        hex[len - j - 1] = temp;
    }

    return hex;
}

int main() {
    char hex[100];

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    
    // Check if input is a valid hexadecimal number
    for (int i = 0; i < strlen(hex); i++) {
        if (!isxdigit(hex[i])) {
            printf("Invalid hexadecimal number. Try again!\n");
            return 1;
        }
    }

    int decimal = hexToDec(hex);
    printf("Decimal is: %d\n", decimal);

    char* hexAgain = decToHex(decimal);
    printf("Hexadecimal is: %s\n", hexAgain);

    free(hexAgain);
    return 0;
}