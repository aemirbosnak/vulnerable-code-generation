//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimalNumber, char hexadecimal[20]) {
    int remainder, index = 0;

    // Special case for 0
    if(decimalNumber == 0) {
        hexadecimal[index++] = '0';
        hexadecimal[index] = '\0';
        return;
    }

    while (decimalNumber != 0) {
        remainder = decimalNumber % 16;

        // Convert to appropriate hexadecimal character
        if (remainder < 10) {
            hexadecimal[index++] = 48 + remainder; // 48 is ASCII for '0'
        } else {
            hexadecimal[index++] = 87 + remainder; // 87 is ASCII for 'a'
        }
        decimalNumber /= 16;
    }

    hexadecimal[index] = '\0';

    // Reverse the string since we've constructed it backwards
    for (int i = 0; i < index / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[index - i - 1];
        hexadecimal[index - i - 1] = temp;
    }
}

int main() {
    int decimalNumber;
    char hexadecimal[20];

    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("Please enter a decimal number (0 to exit): ");
    
    while (1) {
        if (scanf("%d", &decimalNumber) != 1) {
            printf("Invalid input! Please enter a valid decimal number.\n");
            // clear the input buffer
            while (getchar() != '\n');
            continue;
        }
        
        if (decimalNumber == 0) {
            printf("Exiting the converter. Goodbye!\n");
            break;
        }

        decimalToHexadecimal(decimalNumber, hexadecimal);

        printf("The hexadecimal representation of %d is: %s\n", decimalNumber, hexadecimal);
        printf("Please enter another decimal number (0 to exit): ");
    }

    return 0;
}