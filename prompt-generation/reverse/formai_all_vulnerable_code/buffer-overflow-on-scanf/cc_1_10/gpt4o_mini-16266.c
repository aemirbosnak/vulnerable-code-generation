//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimal, char *hexadecimal) {
    int i = 0;
    if (decimal == 0) {
        hexadecimal[i++] = '0';
        hexadecimal[i] = '\0';
        return;
    }

    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[i++] = 48 + remainder; // 48 is ASCII for '0'
        } else {
            hexadecimal[i++] = 87 + remainder; // 87 is ASCII for 'a'
        }
        decimal = decimal / 16;
    }
    hexadecimal[i] = '\0';

    // Reverse the string
    for (int j = 0; j < i / 2; j++) {
        char temp = hexadecimal[j];
        hexadecimal[j] = hexadecimal[i - j - 1];
        hexadecimal[i - j - 1] = temp;
    }
}

int main() {
    int decimalNumber;
    char hexadecimalNumber[20];

    printf("Surprise! 🎉 Welcome to the Decimal to Hexadecimal Converter! 🎊\n");
    printf("============================================\n");

    while (1) {
        printf("Please enter a non-negative decimal number (or -1 to exit): ");
        if (scanf("%d", &decimalNumber) != 1) {
            printf("Oops! Invalid input. Please enter an integer.\n");
            scanf("%*s"); // clear invalid input
            continue;
        }

        if (decimalNumber == -1) {
            printf("Thank you for using the converter! Goodbye! 😃\n");
            break;
        }

        if (decimalNumber < 0) {
            printf("Oh no! Negative numbers are not allowed. Please try again.\n");
            continue;
        }

        decimalToHexadecimal(decimalNumber, hexadecimalNumber);
        
        printf("Here's your decimal number: %d\n", decimalNumber);
        printf("And its glorious hexadecimal representation is: %s\n", hexadecimalNumber);
        printf("============================================\n");
    }

    return 0;
}