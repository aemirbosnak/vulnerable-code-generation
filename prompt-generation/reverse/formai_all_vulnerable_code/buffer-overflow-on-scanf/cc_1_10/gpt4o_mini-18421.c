//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void convertToBinary(int num);
void displayInstructions();

int main() {
    int decimalNumber;

    // Displaying instructions for the user
    displayInstructions();

    // Getting user input
    printf("Enter an integer to convert to binary: ");
    
    // Handling invalid input
    while (scanf("%d", &decimalNumber) != 1) {
        printf("Invalid input. Please enter an integer: ");
        // Clear the invalid input
        while (getchar() != '\n');
    }

    // Convert to binary and display result
    printf("Decimal Number: %d\nBinary Equivalent: ", decimalNumber);
    convertToBinary(decimalNumber);
    printf("\n");

    return 0;
}

// Function to convert a decimal number to binary
void convertToBinary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }

    // Array to store binary digits
    int binaryDigits[32]; 
    int index = 0;

    // Converting decimal to binary
    while (num > 0) {
        binaryDigits[index] = num % 2; // Store remainder in binaryDigits
        num = num / 2; // Divide the number by 2
        index++; // Increment index
    }

    // Displaying binary digits in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binaryDigits[i]);
    }
}

// Function to display instructions to the user
void displayInstructions() {
    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("---------------------------------------------------\n");
    printf("Instructions:\n");
    printf("1. You will be prompted to enter an integer.\n");
    printf("2. The program will convert this integer into binary.\n");
    printf("3. The binary equivalent will be displayed on the screen.\n");
    printf("---------------------------------------------------\n");
}