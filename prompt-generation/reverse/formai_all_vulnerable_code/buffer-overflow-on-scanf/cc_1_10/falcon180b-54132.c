//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if a character is a hexadecimal digit
int isHex(char c) {
    if (isdigit(c))
        return 1;
    else if (c >= 'A' && c <= 'F')
        return 1;
    else if (c >= 'a' && c <= 'f')
        return 1;
    else
        return 0;
}

// Function to convert a hexadecimal string to decimal
int hexToDec(char *hex) {
    int dec = 0, i = 0;
    while (hex[i]) {
        if (isHex(hex[i])) {
            if (hex[i] >= 'A' && hex[i] <= 'F')
                dec += hex[i] - 'A' + 10;
            else
                dec += hex[i] - '0';
        } else {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            return 0;
        }
        i++;
    }
    return dec;
}

// Function to convert a decimal integer to hexadecimal
void decToHex(int dec, char *hex) {
    int i = 0;
    while (dec > 0) {
        char c;
        if (dec % 16 < 10)
            c = dec % 16 + '0';
        else
            c = dec % 16 + 'A' - 10;
        hex[i++] = c;
        dec /= 16;
    }
    hex[i] = '\0';
}

int main() {
    char hex[MAX_SIZE], dec[MAX_SIZE];
    int i, j, decVal;

    // Prompt the user to enter a hexadecimal string
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex);

    // Check if the input string is a valid hexadecimal string
    for (i = 0; hex[i]; i++) {
        if (!isHex(hex[i])) {
            printf("Invalid hexadecimal string\n");
            return 0;
        }
    }

    // Convert the hexadecimal string to decimal
    decVal = hexToDec(hex);

    // Convert the decimal integer to hexadecimal
    decToHex(decVal, dec);

    // Print the result
    printf("Hexadecimal: %s\nDecimal: %s\n", hex, dec);

    return 0;
}