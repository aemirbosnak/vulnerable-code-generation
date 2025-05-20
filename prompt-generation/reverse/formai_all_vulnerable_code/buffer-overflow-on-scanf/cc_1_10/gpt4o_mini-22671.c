//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void decimalToBinary(int n);
void printBinary(int n);
void interactiveMenu();

int main() {
    printf("Welcome to the Energetic C Binary Converter!\n");
    printf("Get ready to convert decimal numbers into their binary counterparts!\n\n");

    interactiveMenu();

    return 0;
}

void interactiveMenu() {
    int choice;
    int number;

    do {
        printf("Choose an option:\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number to convert: ");
                scanf("%d", &number);
                if (number < 0) {
                    printf("Oops! Please enter a non-negative number.\n");
                } else {
                    printf("The binary representation of %d is: ", number);
                    decimalToBinary(number);
                }
                printf("\n");
                break;
            case 2:
                printf("Thanks for using the Energetic C Binary Converter! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 2);
}

// Function to convert decimal to binary and print it
void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    int binary[32];
    int index = 0;

    while (n > 0) {
        binary[index] = n % 2;
        n = n / 2;
        index++;
    }

    // Print binary number in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

// Function to print binary representation using recursion (as an extra!)
void printBinary(int n) {
    if (n > 1) {
        printBinary(n / 2);
    }
    printf("%d", n % 2);
}

void customInstructions() {
    printf("If you're curious about how binary works, here's a little extra:\n");
    printf("Binary is a base-2 numeral system, using only 0s and 1s.\n");
    printf("Each digit represents a power of 2. For example:\n");
    printf("The binary number 1011 represents:\n");
    printf("1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 1 * 2^0 = 8 + 0 + 2 + 1 = 11 in decimal!\n\n");
}

void debugFeature() {
    printf("Debugging Feature: Let's see how numbers convert!\n");
    for (int i = 0; i < 16; i++) {
        printf("Decimal: %d -> Binary: ", i);
        decimalToBinary(i);
        printf("\n");
    }
    printf("End of debugging feature.\n\n");
}

void outroMessage() {
    printf("You've been a fantastic user! Remember, the world of binary is always at your fingertips!\n");
    printf("Stay curious and keep coding, my energetic friend!\n");
}

// Finalize the program with a flourish
int mainFinal() {
    main();
    outroMessage();
    return 0;
}