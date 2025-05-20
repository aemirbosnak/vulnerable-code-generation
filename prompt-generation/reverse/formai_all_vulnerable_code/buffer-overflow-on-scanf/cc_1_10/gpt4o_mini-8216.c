//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Function prototypes for clarity and organization
void printHexadecimal(int number);
void convertToHex(int number, char *hexStr);

// The main function, the gateway to our hexadecimal universe
int main() {
    int inputNumber;

    // Introduction to our Hexadecimal Converter
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("This program converts decimal integers into hexadecimal format.\n");
    printf("Please enter a non-negative integer (or a negative number to exit): ");

    // Infinite loop to allow multiple conversions until a negative number is entered
    while (1) {
        // Taking user input
        if (scanf("%d", &inputNumber) != 1) {
            printf("Invalid input. Please enter a non-negative integer.\n");
            // Clear invalid input
            while (getchar() != '\n');
            continue;
        }

        // Condition to exit the program
        if (inputNumber < 0) {
            printf("Exiting the Hexadecimal Converter. Goodbye!\n");
            break;
        }

        // Call the function to print the hexadecimal representation
        printHexadecimal(inputNumber);
        printf("Please enter another non-negative integer (or a negative number to exit): ");
    }

    return 0;
}

// This function takes an integer and prints its hexadecimal representation
void printHexadecimal(int number) {
    // Creating a buffer to store the hexadecimal string representation
    char hexStr[20]; // Should be large enough for a typical integer
    convertToHex(number, hexStr);
    
    // Displaying the result to the user
    printf("The hexadecimal representation of %d is: %s\n", number, hexStr);
}

// Function to convert an integer to a hexadecimal string
void convertToHex(int number, char *hexStr) {
    // Format the number using sprintf, a precision tool for such tasks
    sprintf(hexStr, "0x%x", number);
}