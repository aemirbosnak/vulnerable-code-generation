//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("0\n");
        return;
    }

    int binary[sizeof(int) * CHAR_BIT]; // Array to hold binary representation
    int index = 0;

    while (n > 0) {
        binary[index++] = n % 2; // Store the remainder of division by 2
        n = n / 2; // Divide n by 2
    }

    // Print the binary representation in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to handle user input and conversion
void userInputAndConversion() {
    int choice;
    do {
        printf("Welcome to the Decimal to Binary Converter!\n");
        printf("1. Convert an Unsigned Decimal to Binary\n");
        printf("2. Convert a Signed Decimal to Binary\n");
        printf("0. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            int number;
            printf("Enter a decimal number: ");
            scanf("%d", &number);

            // Input validation for signed integers
            if (choice == 2 && number < INT_MIN) {
                printf("Error: Number is below the signed integer limit.\n");
                continue;
            } else if (number < 0) {
                printf("Note: Signed negative numbers will be converted as their positive equivalent.\n");
                number = -number; // Use the absolute value for binary conversion
            }

            printf("Binary representation: ");
            decimalToBinary(number);
        } 
        else if (choice != 0) {
            printf("Invalid choice, please try again.\n");
        }

    } while (choice != 0);

    printf("Exiting the program. Thank you!\n");
}

int main() {
    userInputAndConversion();
    return 0;
}