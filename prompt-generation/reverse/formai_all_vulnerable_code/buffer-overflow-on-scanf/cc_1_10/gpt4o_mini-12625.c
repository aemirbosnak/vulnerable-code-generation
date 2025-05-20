//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void decimalToBinary(int n, char *binary);
void reverseString(char *str);
void displayBinaryRepresentation(char *binary);

// Main function
int main() {
    int decimalNumber;
    char binary[33]; // 32 bits + null character for safety
    int continueConversion = 1; // Flag to continue conversions

    // Welcome message
    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("This program can convert a decimal number into its binary representation.\n\n");

    while (continueConversion) {
        // Prompting user for input
        printf("Please enter a decimal integer (0 to exit): ");
        scanf("%d", &decimalNumber);

        if (decimalNumber == 0) {
            printf("Exiting the converter. Goodbye!\n");
            continueConversion = 0;
            continue;
        }

        // Convert decimal to binary
        decimalToBinary(decimalNumber, binary);

        // Display the result
        displayBinaryRepresentation(binary);
        printf("\n");
    }

    return 0;
}

// Function to convert decimal to binary
void decimalToBinary(int n, char *binary) {
    // Initialize binary string
    binary[0] = '\0';

    // Create a temporary variable to work with
    unsigned int number = (unsigned int)n;
    int index = 0;

    // Perform conversion to binary
    do {
        // Prepend the binary digits
        binary[index++] = (number % 2) ? '1' : '0';
        number /= 2;
    } while (number > 0);

    // Terminate the string
    binary[index] = '\0';

    // Reverse the string to get the correct binary representation
    reverseString(binary);
}

// Function to reverse a string
void reverseString(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    // Swap characters from start to end until the midpoint is reached
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to display the binary representation
void displayBinaryRepresentation(char *binary) {
    printf("The binary representation is: %s\n", binary);
}