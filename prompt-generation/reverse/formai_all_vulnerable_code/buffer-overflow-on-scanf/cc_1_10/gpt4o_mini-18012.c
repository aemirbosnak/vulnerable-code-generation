//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void convertToHex(int decimalNumber);
void printHex(int value);
void getUserInput();

int main() {
    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    getUserInput();
    return 0;
}

// Function to get user input and validate it
void getUserInput() {
    int decimalNumber;

    printf("Please enter a non-negative integer: ");
    // Using scanf to read user input, checking if it was successful
    if (scanf("%d", &decimalNumber) != 1 || decimalNumber < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        // Clear input buffer
        while (getchar() != '\n');
        getUserInput();
    } else {
        convertToHex(decimalNumber);
    }
}

// Function to convert decimal number to hexadecimal
void convertToHex(int decimalNumber) {
    printf("Decimal: %d\n", decimalNumber);
    printf("Hexadecimal: ");
    
    // Print hexadecimal representation
    printHex(decimalNumber);
    
    printf("\nThank you for using the converter. Goodbye!\n");
}

// Function to print hexadecimal representation of the decimal number
void printHex(int value) {
    if (value < 16) {
        // Base case for smaller values
        if (value < 10) {
            printf("%d", value);
        } else {
            printf("%c", value - 10 + 'A');
        }
        return;
    } else {
        // Recursive call to handle larger values 
        printHex(value / 16);
        
        // Handling the current digit after the recursive call
        int remainder = value % 16;
        if (remainder < 10) {
            printf("%d", remainder);
        } else {
            printf("%c", remainder - 10 + 'A');
        }
    }
}