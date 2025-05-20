//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    // An array to store the binary number
    int binary[32];
    int index = 0;

    // Special case for zero
    if (n == 0) {
        printf("The binary representation of 0 is 0\n");
        return;
    }

    // Continue dividing by 2 and storing remainders
    while (n > 0) {
        binary[index] = n % 2; // Store remainder
        n = n / 2;              // Reduce n
        index++;                // Move to the next index
    }

    // Print the binary representation in reverse order
    printf("The binary representation is: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to get input from the user
int getInput() {
    int num;
    printf("Enter a decimal number to convert to binary: ");
    while (scanf("%d", &num) != 1) {
        // Clear the invalid input
        while (getchar() != '\n');
        printf("That's not a valid number! Please enter a valid decimal number: ");
    }
    return num;
}

// Main function
int main() {
    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("--------------------------------------------------\n");

    // Loop until the user decides to quit
    char choice;
    do {
        int number = getInput(); // Get user input
        decimalToBinary(number); // Convert to binary

        // Ask user if they want to perform another conversion
        printf("Would you like to convert another number? (y/n): ");
        scanf(" %c", &choice);
        
        // Ensure the choice is either 'y' or 'n'
        while (choice != 'y' && choice != 'n') {
            printf("Invalid input! Please enter 'y' for yes or 'n' for no: ");
            scanf(" %c", &choice);
        }

    } while (choice == 'y');

    printf("Thank you for using the Decimal to Binary Converter!\n");
    printf("Goodbye!\n");

    return 0;
}