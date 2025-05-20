//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void toHexadecimal(int decimal, int uppercase);
void displayMenu();
void clearInputBuffer();

int main() {
    int decimalNumber;
    char choice;
    int mode;

    while (1) {
        displayMenu();
        // Take user input for decimal number
        printf("Enter a decimal number (or type 'q' to quit): ");
        if (scanf("%d", &decimalNumber) != 1) {
            clearInputBuffer(); // Clear invalid input
            if (getchar() == 'q') break; // Quit if user types 'q'
            printf("Invalid input. Please enter a valid integer.\n");
            continue;
        }

        printf("Choose conversion mode:\n1. Uppercase Hexadecimal\n2. Lowercase Hexadecimal\n");
        if (scanf("%d", &mode) != 1 || (mode < 1 || mode > 2)) {
            clearInputBuffer(); // Clear invalid input
            printf("Invalid choice. Please enter 1 or 2.\n");
            continue;
        }

        // Perform the conversion based on user choice
        toHexadecimal(decimalNumber, mode == 1);
    }
    return 0;
}

// Function to convert decimal to hexadecimal
void toHexadecimal(int decimal, int uppercase) {
    char hex[20]; // Buffer for hexadecimal representation
    int index = 0;

    // Conversion process
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[index++] = remainder + '0'; // Convert to char
        } else {
            hex[index++] = (uppercase ? (remainder - 10 + 'A') : (remainder - 10 + 'a')); // Convert to char
        }
        decimal /= 16; // Reduce decimal
    }

    // Display result
    printf("Hexadecimal equivalent: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]); // Print in reverse order
    }
    putchar('\n');
}

// Function to display the main menu
void displayMenu() {
    printf("\n--- Hexadecimal Converter ---\n");
    printf("Welcome to the Hexagonal Converter!\n");
    printf("You can convert integers from decimal to hexadecimal format.\n");
}

// Function to clear the input buffer
void clearInputBuffer() {
    while (getchar() != '\n'); // Discard remaining input
}