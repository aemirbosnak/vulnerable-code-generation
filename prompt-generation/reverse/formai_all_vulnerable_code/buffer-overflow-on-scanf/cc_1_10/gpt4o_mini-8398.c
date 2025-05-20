//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: enthusiastic
#include <stdio.h>

// Function to convert a decimal number to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("Binary: 0\n");
        return;
    }

    // Array to store binary number
    int binary[32];
    int index = 0;

    // Generate binary representation
    while (n > 0) {
        binary[index] = n % 2; // Store the remainder
        n = n / 2;              // Reduce the number by dividing it by 2
        index++;
    }

    // Print binary representation in reverse order
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n"); // New line for better readability
}

// Main function
int main() {
    int num;
    char choice;

    printf("========================================\n");
    printf(" Welcome to the Decimal to Binary Converter!\n");
    printf("========================================\n");

    do {
        printf("Please enter a positive integer: ");
        scanf("%d", &num);

        // Ensure the entered number is non-negative
        if (num < 0) {
            printf("Oops! Please enter a non-negative integer only.\n");
            continue; // Prompt again if a negative number is entered
        }

        decimalToBinary(num); // Convert the number to binary

        // Ask user if they want to convert another number
        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &choice); // Space before %c to prevent reading newline

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the converter! Goodbye! 🎉\n");
    return 0;
}