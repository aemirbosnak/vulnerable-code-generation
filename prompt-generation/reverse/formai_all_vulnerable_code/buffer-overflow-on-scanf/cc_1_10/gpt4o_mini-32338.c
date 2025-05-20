//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void displayIntro() {
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("This program will convert decimal numbers to hexadecimal representation.\n");
    printf("-------------------------------------------------------------\n");
}

void displayInstructions() {
    printf("Instructions:\n");
    printf("1. Enter a decimal number (0 to 2147483647).\n");
    printf("2. Enter -1 to exit the program.\n");
    printf("-------------------------------------------------------------\n");
}

void convertToHex(int decimal) {
    char hex[20]; // Buffer to store hexadecimal representation
    int i = 0;

    if (decimal == 0) {
        printf("Hexadecimal: 0x0\n");
        return;
    }

    while (decimal != 0) {
        int remainder = decimal % 16;

        // Convert remainder to hexadecimal
        if (remainder < 10) {
            hex[i++] = 48 + remainder; // ASCII '0' to '9'
        } else {
            hex[i++] = 87 + remainder; // ASCII 'a' to 'f'
        }

        decimal = decimal / 16;
    }

    // Hexadecimal output reversed
    printf("Hexadecimal: 0x");
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    printf("\n");
}

void executeConversion() {
    int decimal;

    while (1) {
        printf("Enter your decimal number: ");
        scanf("%d", &decimal);

        if (decimal == -1) {
            printf("Exiting the Hexadecimal Converter. Goodbye!\n");
            break;
        } else if (decimal < 0 || decimal > 2147483647) {
            printf("Please enter a valid decimal number between 0 and 2147483647.\n");
        } else {
            convertToHex(decimal);
        }
    }
}

int main() {
    displayIntro();
    displayInstructions();
    executeConversion();

    return 0;
}