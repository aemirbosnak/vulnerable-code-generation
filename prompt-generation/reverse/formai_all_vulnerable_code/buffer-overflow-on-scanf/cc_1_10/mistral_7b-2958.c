//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Ada Lovelace, the pioneering computer programmer, would have
// embraced the power of the imaginary and the sublime. Let us
// create a hexadecimal converter that not only converts numbers
// but also conjures enchanting hexadecimal strings.

typedef struct hexString {
    char str[33]; // Allocating an extra character for null terminator
} hexString;

void decimalToHex(int decimalNumber, hexString *hex) {
    int decimal, divisor = 16, i = 0;

    hex->str[32] = '\0'; // Initialize the string with null terminator

    while (decimalNumber > 0) {
        decimal = decimalNumber % divisor;
        decimalNumber /= divisor;

        if (decimal <= 9) {
            hex->str[i++] = '0' + decimal;
        } else {
            hex->str[i++] = 'A' + (decimal - 10);
        }
    }

    if (decimalNumber > 0) { // If decimal number was zero, add leading zero
        hex->str[i++] = '0';
        hex->str[i] = '\0';
    }

    // Reverse the string since output is expected in reverse order
    for (int j = 0; j < i / 2; j++) {
        char temp = hex->str[j];
        hex->str[j] = hex->str[i - j - 1];
        hex->str[i - j - 1] = temp;
    }
}

void printHexString(hexString hex) {
    printf("The hexadecimal representation of the decimal number is: %s\n", hex.str);
}

int main() {
    int decimalNumber;
    hexString hex;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    decimalToHex(decimalNumber, &hex);
    printHexString(hex);

    return 0;
}