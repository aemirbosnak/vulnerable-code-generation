//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void decimalToHexadecimal(int decimal);
void printHexDigit(int digit);
void displayInstructions();

int main() {
    int decimalInput;
    
    // Display instructions to the user
    displayInstructions();
    
    // Prompt the user for decimal input
    printf("Enter a decimal number (non-negative): ");
    scanf("%d", &decimalInput);
    
    // Validate user input
    if (decimalInput < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1; // Exit with error code
    }
    
    // Call the function to convert and print hexadecimal
    printf("The hexadecimal representation of %d is: ", decimalInput);
    decimalToHexadecimal(decimalInput);
    printf("\n"); // New line for better readability
    return 0; // Successful execution
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    // Temporary variable to store value for conversion
    char hex_string[20]; // Buffer to hold hexadecimal digits
    int index = 0; // Index for filling the hex string
    int remainder; // For storing remainder in conversion
    
    // Handle case where decimal is zero
    if (decimal == 0) {
        printf("0");
        return;
    }

    // Continue while the decimal value is greater than zero
    while (decimal > 0) {
        // Get the remainder of the decimal when divided by 16
        remainder = decimal % 16;
        decimal /= 16; // Reduce the decimal for next iteration
        // Store the hex character in the string
        hex_string[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
    }
    
    // Print the hex digits in reverse order
    for (--index; index >= 0; index--) {
        printHexDigit(hex_string[index]);
    }
}

// Function to print a single hex digit
void printHexDigit(int digit) {
    putchar(digit); // Print the hexadecimal character
}

// Function to display instructions to the user
void displayInstructions() {
    printf("Welcome to the Decimal to Hexadecimal Converter\n");
    printf("In this program, you will input a non-negative decimal number,\n");
    printf("and the program will display its corresponding hexadecimal value.\n");
    printf("Please follow the on-screen instructions to proceed.\n\n");
}