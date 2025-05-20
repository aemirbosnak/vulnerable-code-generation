//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    int binary[32]; // Array to hold binary digits
    int index = 0; // Index for the binary array

    // If the number is zero, the binary representation is simply 0
    if (n == 0) {
        printf("Binary representation: 0\n");
        return;
    }

    // Build the binary number by continuously dividing by 2
    while (n > 0) {
        binary[index] = n % 2; // Get the remainder (0 or 1)
        n = n / 2;              // Divide the number by 2
        index++;                // Move to the next index
    }

    printf("Binary representation: ");
    // Since the binary array stores the digits in reverse order, we need to print it in reverse
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to get user input
void getUserInput() {
    int number;

    // Prompt the user for input
    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("Please enter a decimal number to convert: ");
    
    // Check for valid input
    while (1) {
        if (scanf("%d", &number) != 1) {
            printf("That's not a valid number! Please try again: ");
            while (getchar() != '\n'); // Clear invalid input
        } else {
            break; // Break the loop if input is valid
        }
    }

    // Confirm before converting
    printf("You entered: %d\n", number);
    decimalToBinary(number); // Call the function to convert
}

// Main function
int main() {
    // Keep converting numbers until the user decides to exit
    while (1) {
        getUserInput(); // Get input and convert

        // Ask the user if they want to continue
        char choice;
        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &choice); // Use a space before %c to skip whitespace

        if (choice != 'y' && choice != 'Y') {
            printf("Thank you for using the Decimal to Binary Converter. Goodbye!\n");
            break; // Exit the loop if the user does not want to continue
        }
    }
    return 0; // Indicate successful completion
}