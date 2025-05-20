//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void decimalToBinary(int decimalNumber);
void printBinary(int binaryArray[], int size);
void printInstructions();

int main() {
    int number;

    printInstructions(); // Show the instructions

    while (1) {
        printf("\nEnter a decimal number (or -1 to exit): ");
        scanf("%d", &number);
        
        if (number == -1) {
            printf("Thank you for using the delightful Decimal to Binary Converter! Goodbye!\n");
            break; // Exit the loop if the user wants to quit
        }
        
        if (number < 0) {
            printf("Oops! We only accept positive numbers. Try again!\n");
            continue; // Skip the rest of the loop and prompt again
        }

        printf("The binary representation of %d is: ", number);
        decimalToBinary(number);
    }

    return 0;
}

void decimalToBinary(int decimalNumber) {
    int binaryArray[32]; // Array to store binary bits
    int index = 0; // Index for the binaryArray

    // Convert decimal to binary
    while (decimalNumber > 0) {
        binaryArray[index] = decimalNumber % 2; // Store the bit
        decimalNumber = decimalNumber / 2; // Reduce decimal number
        index++;
    }

    // Print the binary number in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binaryArray[i]);
    }
    printf("\n");
}

void printInstructions() {
    printf("Welcome to the Fun Decimal to Binary Converter!\n");
    printf("You can convert any positive decimal number into binary.\n");
    printf("Type -1 if you want to exit. Let's have some fun!\n");
    printf("---------------------------------------------------\n");
}