//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal, char *hexadecimal) {
    int remainder;
    int index = 0;

    // Handle the case of 0 explicitly
    if (decimal == 0) {
        hexadecimal[index++] = '0';
        hexadecimal[index] = '\0';
        return;
    }

    // Loop to convert decimal to hexadecimal
    while (decimal > 0) {
        remainder = decimal % 16;

        // Handle the conversion of remainder to hexadecimal character
        if (remainder < 10) {
            hexadecimal[index++] = remainder + '0'; // For 0-9
        } else {
            hexadecimal[index++] = (remainder - 10) + 'A'; // For A-F
        }

        // Dividing the number by 16 for the next iteration
        decimal /= 16;
    }

    hexadecimal[index] = '\0'; // Null-terminate the string

    // Reverse the string to get the correct hexadecimal representation
    for (int i = 0; i < index / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[index - i - 1];
        hexadecimal[index - i - 1] = temp;
    }
}

// Function to display the result
void displayResult(int decimal, const char *hexadecimal) {
    printf("The decimal number %d is represented in hexadecimal as: %s\n", decimal, hexadecimal);
}

int main() {
    int decimalNumber;
    char hexadecimalRepresentation[20]; // Buffer for hexadecimal representation

    // Prompting the user for input
    printf("Enter a decimal number to convert to hexadecimal: ");
    scanf("%d", &decimalNumber);

    // Ensure the input is non-negative
    if (decimalNumber < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    // Call the conversion function
    decimalToHexadecimal(decimalNumber, hexadecimalRepresentation);

    // Display the result
    displayResult(decimalNumber, hexadecimalRepresentation);

    return 0;
}