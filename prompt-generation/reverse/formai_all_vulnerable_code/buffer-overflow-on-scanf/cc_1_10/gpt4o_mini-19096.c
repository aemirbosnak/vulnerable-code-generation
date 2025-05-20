//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    char hex[100];
    int index = 0;

    // Edge case for zero
    if (decimal == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    // Convert decimal to hexadecimal
    while (decimal != 0) {
        int remainder = decimal % 16;

        // Convert remainder to appropriate hexadecimal character
        if (remainder < 10) {
            hex[index++] = 48 + remainder;  // ASCII '0' = 48
        } else {
            hex[index++] = 87 + remainder;  // ASCII 'a' = 97
        }
        decimal /= 16;
    }

    // Print the hexadecimal number in reverse order
    printf("Hexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]);
    }
    putchar('\n');
}

// Function to get a positive integer from user with validation
int getPositiveInteger() {
    int number;
    char term;

    printf("Please enter a positive integer: ");
    while (1) {
        if (scanf("%d%c", &number, &term) != 2 || term != '\n' || number < 0) {
            printf("Invalid input! Make sure to enter a positive integer.\n");
            while (getchar() != '\n'); // Clear input buffer
            printf("Try again: ");
        } else {
            break; // Input is valid
        }
    }
    
    return number;
}

// Program main function
int main() {
    printf("Welcome to the Mystical Decimal to Hexadecimal Converter!\n");
    printf("--------------------------------------------------------\n");

    while (1) {
        int decimal = getPositiveInteger();
        decimalToHexadecimal(decimal);

        char choice;
        printf("Would you like to convert another number? (y/n): ");
        scanf(" %c", &choice); // Space before %c to discard white space

        if (choice != 'y' && choice != 'Y') {
            printf("Thank you for using the converter! Until next time!\n");
            break;
        }
        printf("\n");
    }

    return 0;
}