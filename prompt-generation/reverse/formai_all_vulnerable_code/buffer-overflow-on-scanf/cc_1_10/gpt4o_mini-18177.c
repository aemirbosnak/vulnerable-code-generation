//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int decimal, int bits) {
    if (bits <= 0) {
        printf("Error: Number of bits must be greater than 0.\n");
        return;
    }

    unsigned int mask = 1 << (bits - 1);
    printf("Binary representation: ");
    
    // Print the binary representation
    for (int i = 0; i < bits; i++) {
        putchar((decimal & mask) ? '1' : '0');
        mask >>= 1;
    }
    printf("\n");
}

void displayMenu() {
    printf("\nDecimal to Binary Converter\n");
    printf("1. Convert decimal to binary\n");
    printf("2. Change number of bits\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option = 0;
    int decimalNumber;
    int bits = 8; // Default number of bits

    while (1) {
        displayMenu();

        // Get user choice
        if (scanf("%d", &option) != 1 || option < 1 || option > 3) {
            printf("Invalid option. Please enter a number between 1 and 3.\n");
            while(getchar() != '\n'); // clear the input buffer
            continue; // ask for option again
        }

        switch (option) {
            case 1:
                printf("Enter a decimal number: ");
                if (scanf("%d", &decimalNumber) != 1) {
                    printf("Invalid input. Please enter an integer.\n");
                    while(getchar() != '\n'); // clear the input buffer
                } else {
                    decimalToBinary(decimalNumber, bits);
                }
                break;

            case 2:
                printf("Enter number of bits (must be > 0): ");
                if (scanf("%d", &bits) != 1 || bits <= 0) {
                    printf("Invalid number of bits. Must be greater than 0.\n");
                    while(getchar() != '\n'); // clear the input buffer
                } else {
                    printf("Number of bits set to %d.\n", bits);
                }
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0); // Exit the program
                break;
        }
    }

    return 0;
}