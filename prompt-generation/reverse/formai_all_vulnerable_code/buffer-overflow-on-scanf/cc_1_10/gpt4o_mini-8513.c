//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    printf("Hexadecimal: %X\n", decimal);
}

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    int binary[32];
    int index = 0;

    while (decimal > 0) {
        binary[index] = decimal % 2;
        decimal = decimal / 2;
        index++;
    }

    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to convert decimal to octal
void decimalToOctal(int decimal) {
    printf("Octal: %o\n", decimal);
}

// Function to display the menu
void displayMenu() {
    printf("\nHexadecimal Converter Menu:\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Decimal to Binary\n");
    printf("3. Convert Decimal to Octal\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
}

// Main function
int main() {
    int choice, decimal;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 4) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Enter a positive decimal number: ");
        if (scanf("%d", &decimal) != 1 || decimal < 0) {
            printf("Invalid input! Please enter a positive integer.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                decimalToHexadecimal(decimal);
                break;
            case 2:
                decimalToBinary(decimal);
                break;
            case 3:
                decimalToOctal(decimal);
                break;
        }
    }

    return 0;
}