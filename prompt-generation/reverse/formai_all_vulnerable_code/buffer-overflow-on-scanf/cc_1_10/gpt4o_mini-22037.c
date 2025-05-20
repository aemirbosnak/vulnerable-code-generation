//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void convertToBinary(int number, char *binary);
void printBinaryRepresentation(int number);
void handleConversionMenu();

int main() {
    // Main program loop
    handleConversionMenu();
    return 0;
}

// Function to convert decimal number to binary
void convertToBinary(int number, char *binary) {
    int index = 0;
    // Fill the binary representation in reverse order
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        binary[index++] = (number & (1 << i)) ? '1' : '0';
    }
    binary[index] = '\0'; // Null-terminate the string
}

// Function to print the binary representation of a number
void printBinaryRepresentation(int number) {
    char binary[sizeof(int) * 8 + 1]; // +1 for null character

    // Convert to binary representation
    convertToBinary(number, binary);

    // Print the binary representation
    printf("Decimal: %d\nBinary: %s\n", number, binary);
}

// Function to display the conversion menu
void handleConversionMenu() {
    int choice = 0;
    int number = 0;

    while (1) {
        printf("\n--- Decimal to Binary Converter ---\n");
        printf("1. Convert a number\n");
        printf("2. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                
                // Check for the negative number
                if (number < 0) {
                    printf("Error: Please enter a non-negative decimal number.\n");
                    continue;
                }

                // Print binary representation
                printBinaryRepresentation(number);
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                return;

            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    }
}