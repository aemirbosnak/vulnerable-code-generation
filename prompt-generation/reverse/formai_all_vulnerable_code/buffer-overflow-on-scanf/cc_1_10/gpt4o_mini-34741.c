//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    // An array to hold binary numbers
    int binary[32];
    int index = 0;

    // Edge case for zero
    if (n == 0) {
        printf("The binary representation of 0 is 0\n");
        return;
    }
    
    // Fill the binary array by dividing the number by 2
    while (n > 0) {
        binary[index] = n % 2;
        n = n / 2;
        index++;
    }

    // Print the binary representation in reverse
    printf("Binary representation: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to prompt user input
int getUserInput() {
    int num;
    printf("Please enter a decimal number to convert to binary: ");
    
    // Reading user input
    while (scanf("%d", &num) != 1) {
        printf("That's not a valid number! Please try again: ");
        while(getchar() != '\n'); // clear the input buffer
    }
    return num;
}

// Main function
int main() {
    int decimalNumber;
    char choice;

    printf("Welcome to the Decimal to Binary Converter!\n");

    // Loop until user chooses to exit
    do {
        decimalNumber = getUserInput();
        decimalToBinary(decimalNumber);

        // Check if user wants to convert another number
        printf("Would you like to convert another number? (y/n): ");
        while (getchar() != '\n'); // clear input buffer
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the converter! Goodbye!\n");
    return 0;
}