//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimal) {
    // Create an array to store the hexadecimal representation
    char hex[20];
    int index = 0;

    // Edge case for zero
    if (decimal == 0) {
        printf("Hexadecimal: 0x0\n");
        return;
    }

    // Convert decimal to hexadecimal
    while (decimal != 0) {
        int remainder = decimal % 16;
        
        // Convert to appropriate hexadecimal character
        if (remainder < 10) {
            hex[index++] = remainder + '0'; // Convert to character '0'-'9'
        } else {
            hex[index++] = (remainder - 10) + 'A'; // Convert to character 'A'-'F'
        }
        
        decimal /= 16;
    }

    // Print the hexadecimal in reverse order
    printf("Hexadecimal: 0x");
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]);
    }
    printf("\n");
}

int main() {
    int decimal, choice;

    // Display welcome message
    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    
    do {
        printf("\nEnter a decimal number (or -1 to exit): ");
        if (scanf("%d", &decimal) != 1) {
            // If input is invalid, clear input buffer
            while (getchar() != '\n');
            printf("Invalid input! Please enter a valid integer.\n");
            continue;
        }
        
        if (decimal == -1) {
            break; // Exit the loop if user enters -1
        } else if (decimal < 0) {
            printf("Only non-negative integers are allowed.\n");
            continue;
        }

        // Convert decimal to hexadecimal
        decimalToHexadecimal(decimal);
        
        printf("Do you want to convert another number? (1: Yes, 0: No): ");
        choice = 0;
        while (choice < 1 || choice > 2) {
            if (scanf("%d", &choice) != 1) {
                while (getchar() != '\n');
                printf("Invalid input! Please enter 1 for Yes or 0 for No: ");
                choice = 0; // Reset choice to an invalid value
            }
        }
    } while (choice == 1);

    printf("Thank you for using the converter! Goodbye!\n");
    return 0;
}