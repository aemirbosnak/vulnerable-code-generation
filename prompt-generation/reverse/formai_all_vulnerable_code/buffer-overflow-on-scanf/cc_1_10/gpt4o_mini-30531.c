//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

// Function prototypes
void convertToBinary(int number, char* binaryRepresentation);
void displayResult(int number, const char* binaryRepresentation);
void binaryOperations(int number);
void promptUser();
void clearBuffer();

int main() {
    int number;
    char binaryRepresentation[MAX_BITS + 1];

    // User prompting section
    promptUser();

    // Continue asking for input until user chooses to exit
    while (1) {
        printf("Enter a decimal number (or -1 to exit): ");
        if (scanf("%d", &number) != 1 || number < -1) {
            // Clear the input buffer in case of invalid input
            clearBuffer();
            printf("Invalid input. Please enter a valid decimal number.\n");
            continue;
        }

        if (number == -1) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Convert number to binary
        convertToBinary(number, binaryRepresentation);
        
        // Display results
        displayResult(number, binaryRepresentation);
        
        // Perform binary operations
        binaryOperations(number);
    }

    return 0;
}

// Function to convert a decimal number to a binary string
void convertToBinary(int number, char* binaryRepresentation) {
    binaryRepresentation[MAX_BITS] = '\0'; // Ensure null-termination
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        binaryRepresentation[i] = (number & 1) ? '1' : '0';
        number >>= 1;
    }
}

// Function to display the number and its binary representation
void displayResult(int number, const char* binaryRepresentation) {
    printf("Decimal: %d\n", number);
    printf("Binary: %s\n", binaryRepresentation);
}

// Function to perform simple binary operations
void binaryOperations(int number) {
    int additionValue, subtractionValue;

    printf("Enter a number to add to %d: ", number);
    scanf("%d", &additionValue);
    printf("Result of %d + %d = %d\n", number, additionValue, number + additionValue);
    
    printf("Enter a number to subtract from %d: ", number);
    scanf("%d", &subtractionValue);
    printf("Result of %d - %d = %d\n", number, subtractionValue, number - subtractionValue);
}

// Function to prompt the user for instructions
void promptUser() {
    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("You can convert a decimal number to its binary representation.\n");
    printf("Input -1 to exit the program.\n");
}

// Function to clear the input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}