//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: genius
/*
 * C Hexadecimal Converter Program
 * -------------------------------
 * This program converts hexadecimal numbers to decimal numbers and vice versa.
 *
 * Usage:
 * ------
 * Enter a hexadecimal number (e.g. 0x1234) and press enter to convert to decimal.
 * Enter a decimal number (e.g. 4321) and press enter to convert to hexadecimal.
 *
 * Conversion:
 * ----------
 * To convert a hexadecimal number to decimal, the program uses the following formula:
 *
 * Decimal = Hexadecimal * 16^0 + Hexadecimal * 16^1 + ... + Hexadecimal * 16^(n-1)
 *
 * Where n is the number of hexadecimal digits.
 *
 * To convert a decimal number to hexadecimal, the program uses the following formula:
 *
 * Hexadecimal = Decimal / 16^0 + Decimal / 16^1 + ... + Decimal / 16^(n-1)
 *
 * Where n is the number of hexadecimal digits.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[20];
    int decimal, hexadecimal;
    int i, n;

    printf("Enter a hexadecimal number (e.g. 0x1234): ");
    scanf("%s", input);

    // Convert hexadecimal to decimal
    n = strlen(input) - 2;
    decimal = 0;
    for (i = 0; i < n; i++) {
        hexadecimal = input[i] - '0';
        decimal += hexadecimal * pow(16, n - i - 1);
    }
    printf("Decimal: %d\n", decimal);

    // Convert decimal to hexadecimal
    n = 4;
    hexadecimal = 0;
    for (i = 0; i < n; i++) {
        decimal = input[i] - '0';
        hexadecimal += decimal * pow(16, n - i - 1);
    }
    printf("Hexadecimal: %x\n", hexadecimal);

    return 0;
}