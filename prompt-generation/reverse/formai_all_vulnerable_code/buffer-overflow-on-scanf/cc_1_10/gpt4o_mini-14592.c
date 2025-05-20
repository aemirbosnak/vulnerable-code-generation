//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal number to binary
void decimalToBinary(int n, char *binary) {
    int i = 0;
    while (n > 0) {
        binary[i++] = (n % 2) + '0'; // Store binary digit
        n = n / 2; // Divide n by 2
    }
    binary[i] = '\0'; // Null-terminate the string
}

// Function to reverse the binary string
void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        // Swap characters
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to format and print the binary representation
void printBinary(int n) {
    char binary[32]; // Array to hold binary representation
    decimalToBinary(n, binary); // Convert to binary
    reverseString(binary); // Reverse the string to get correct order
    printf("Decimal: %d | Binary: %s\n", n, binary); // Print result
}

// Main function to execute the program
int main() {
    int choice, number;

    printf("Welcome to the Binary Converter!\n");
    printf("Select an option:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Exit\n");

    // Loop until user decides to exit
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter a decimal number: ");
            scanf("%d", &number);

            // Check if the number is negative
            if (number < 0) {
                printf("Please enter a non-negative integer.\n");
                continue; // Skip the rest of the loop
            }

            printBinary(number); // Convert and print binary
        } else if (choice == 2) {
            printf("Thank you for using the Binary Converter. Goodbye!\n");
            break; // Exit the program
        } else {
            printf("Invalid choice! Please enter 1 to convert, or 2 to exit.\n");
        }
    }

    return 0; // End of program
}