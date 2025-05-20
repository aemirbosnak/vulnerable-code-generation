//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

// Function to convert an integer to binary string
void intToBinary(int number, char *binaryStr) {
    for (int i = 0; i < MAX_BITS; i++) {
        binaryStr[MAX_BITS - 1 - i] = (number & (1 << i)) ? '1' : '0';
    }
    binaryStr[MAX_BITS] = '\0'; // Null-terminate the string
}

// Function to convert binary string to integer
int binaryToInt(const char *binaryStr) {
    int number = 0;
    for (int i = 0; i < MAX_BITS; i++) {
        if (binaryStr[i] == '1') {
            number |= (1 << (MAX_BITS - 1 - i));
        }
    }
    return number;
}

// Function to display binary representation with formatting
void displayBinary(const char *binaryStr) {
    printf("Binary Representation: ");
    for (int i = 0; i < MAX_BITS; i++) {
        if (i > 0 && i % 4 == 0) {
            printf(" "); // Print space for readability
        }
        printf("%c", binaryStr[i]);
    }
    printf("\n");
}

// Function to check if the input is a valid integer
int isValidInput(const char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] < '0' || input[i] > '9') {
            return 0; // Invalid if any character is not a digit
        }
    }
    return 1; // Valid input
}

// Main program
int main() {
    char binaryStr[MAX_BITS + 1]; // +1 for null-terminator
    char input[20]; // Buffer for user input
    int number = 0;

    printf("Welcome to the Binary Converter!\n");
    
    while (1) {
        printf("\nPlease enter a positive integer (or 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        // Check if the user wants to exit
        if (strcmp(input, "exit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Validate the input
        if (!isValidInput(input)) {
            printf("Invalid input. Please enter a valid positive integer.\n");
            continue;
        }

        // Convert input string to integer
        number = atoi(input);

        // Check if the number is within the valid range
        if (number < 0 || number >= (1 << MAX_BITS)) {
            printf("Please enter a positive integer within range (0 - %d).\n", (1 << MAX_BITS) - 1);
            continue;
        }

        // Convert to binary and display
        intToBinary(number, binaryStr);
        displayBinary(binaryStr);
        printf("Decimal Value: %d\n", number);

        // Convert back and verify correctness
        int convertedBack = binaryToInt(binaryStr);
        printf("Converted Back to Decimal: %d\n", convertedBack);

        if (number == convertedBack) {
            printf("Conversion successful!\n");
        } else {
            printf("Conversion mismatch! Something went wrong.\n");
        }
    }

    return 0;
}