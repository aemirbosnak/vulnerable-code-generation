//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("  0");
        return;
    }

    char binary[32];
    int index = 0;
    
    while (n > 0) {
        binary[index] = (n % 2) + '0'; // Store the character representation of the bit
        n = n / 2;
        index++;
    }

    // Print the binary representation in reverse
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(binary[i]);
    }
}

// Function to convert a binary string to decimal
int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int base = 1; // 2^0

    int length = strlen(binary);
    
    // Iterate from the end of the string
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2; // Move to the next bit
    }

    return decimal;
}

// Function to provide a cheerful banner
void printWelcomeBanner() {
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*     Welcome to the Happy Binary Converter!   *\n");
    printf("*                                              *\n");
    printf("************************************************\n");
}

// Main function to drive the program
int main() {
    printWelcomeBanner();
    
    int decimalNumber;
    char binaryString[33];

    // Ask the user for a decimal number
    printf("Please enter a decimal number to convert to binary (0 to exit): ");
    while (1) {
        printf("Decimal number: ");
        scanf("%d", &decimalNumber);

        // Check for exit condition
        if (decimalNumber == 0) {
            printf("Goodbye! Happy converting!\n");
            break; // Exit the loop if 0 is entered
        }

        // Convert and display the binary representation
        printf("Your decimal number is: %d\n", decimalNumber);
        decimalToBinary(decimalNumber);
        printf("\n");

        // Ask for binary input to convert to decimal
        printf("Now please enter a binary number to convert to decimal: ");
        scanf("%s", binaryString);

        // Convert and display the decimal representation
        int convertedDecimal = binaryToDecimal(binaryString);
        printf("The binary number %s in decimal is: %d\n", binaryString, convertedDecimal);
        printf("\n");
    }

    return 0;
}