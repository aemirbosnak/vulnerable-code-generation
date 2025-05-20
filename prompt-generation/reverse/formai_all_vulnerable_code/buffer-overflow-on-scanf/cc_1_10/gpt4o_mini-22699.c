//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to hexadecimal
void decimalToHexadecimal(int decimal) {
    // Maximum size for hexadecimal representation with null terminator
    char hex[20];
    int index = 0;

    if (decimal == 0) {
        printf("The hexadecimal representation is: 0\n");
        return;
    }

    while (decimal > 0) {
        int remainder = decimal % 16;
        // Convert remainder to hexadecimal character
        if (remainder < 10) {
            hex[index++] = remainder + '0';  // For 0-9
        } else {
            hex[index++] = (remainder - 10) + 'A';  // For A-F
        }
        decimal /= 16;  // Reduce decimal
    }

    // The hex array needs to be reversed
    printf("The hexadecimal representation is: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]);
    }
    putchar('\n');  // New line for cleanliness
}

// Main function - the entry point of the program
int main() {
    int number;

    // Welcome message
    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("------------------------------------------------\n");
    printf("Please input a non-negative integer to convert:\n");

    // Read input from user
    if (scanf("%d", &number) != 1 || number < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;  // Exit the program with an error code
    }

    // Invoke the conversion function
    decimalToHexadecimal(number);

    // Concluding message
    printf("Thank you for using the converter! Goodbye.\n");
    return 0;  // Successful completion of the program
}