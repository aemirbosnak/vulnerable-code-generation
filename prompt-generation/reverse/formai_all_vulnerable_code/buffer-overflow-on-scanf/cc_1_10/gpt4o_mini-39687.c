//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Function prototype to convert decimal to binary
void decimalToBinary(int n);

// Function prototype for user interaction
void userInteraction();

// Function: Decimal to binary converter
void decimalToBinary(int n) {
    // A fascinating array to hold binary digits
    int binary[32];
    int index = 0;

    // Careful observation while dividing the number by 2
    while (n > 0) {
        binary[index] = n % 2; // Store the remainder
        n = n / 2;              // Update the number
        index++;
    }

    // The binary representation is reversed
    printf("Binary representation is: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function: Start the user interaction process
void userInteraction() {
    int number;
    char choice;

    // A warm welcome to our curious user
    printf("Welcome to the Decimal to Binary Converter!\n");

    do {
        // Asking our inquisitive user for a decimal number
        printf("Enter a decimal number (non-negative integer): ");
        scanf("%d", &number);

        // Check for non-negative input
        if (number < 0) {
            printf("Please enter a non-negative integer!\n");
        } else {
            // Proceed with conversion if the input is valid
            decimalToBinary(number);
        }

        // Curious minds may want to explore further
        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume newline

    } while (choice == 'y' || choice == 'Y');

    // Parting words for our user
    printf("Thank you for using the Decimal to Binary Converter. Goodbye!\n");
}

// Entry point of the program
int main() {
    // Initiating user interaction
    userInteraction();
    return 0;
}