//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    int binary[32]; // Array to hold binary numbers
    int index = 0; // Index for binary array

    // Special case for zero
    if (n == 0) {
        printf("The binary representation of 0 is: 0\n");
        return;
    }

    // Convert decimal to binary
    while (n > 0) {
        binary[index] = n % 2; // Store the binary digit
        n = n / 2;              // Divide by 2
        index++;
    }

    // Output binary number in reverse order
    printf("The binary representation is: ");
    for (int j = index - 1; j >= 0; j--) {
        printf("%d", binary[j]); // Print binary digits
    }
    printf("\n");
}

// Function to read and validate user input
int readInput() {
    int number;
    char term;

    // Using while loop to validate input
    while (1) {
        printf("Enter a non-negative integer: ");
        if (scanf("%d%c", &number, &term) != 2 || term != '\n' || number < 0) {
            printf("Invalid input. Please enter a valid non-negative integer.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            break; // Break if valid input
        }
    }
    return number;
}

int main() {
    printf("Welcome to the Decimal to Binary Converter!\n");

    while (1) {
        int number = readInput(); // Read and validate user input
        decimalToBinary(number);  // Convert and print the binary representation
        
        // Prompt user to continue or exit
        char choice;
        printf("Would you like to convert another number? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'n' || choice == 'N') {
            printf("Thank you for using the Decimal to Binary Converter. Goodbye!\n");
            break; // Exit the loop
        } else if (choice != 'y' && choice != 'Y') {
            printf("Invalid choice, exiting!\n");
            break; // Exit on invalid choice
        }
    }
    
    return 0; // End of program
}