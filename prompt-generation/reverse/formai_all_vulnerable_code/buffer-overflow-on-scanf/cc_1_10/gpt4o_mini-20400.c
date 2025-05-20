//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void convertToBinary(int decimal);
void printBinary(int decimal, int inverted);
void showMenu();
int getUserInput();

int main() {
    int decimalNumber;
    char continueConversion = 'y';

    showMenu();

    while (continueConversion == 'y' || continueConversion == 'Y') {
        decimalNumber = getUserInput();

        if (decimalNumber < 0) {
            printf("Only non-negative integers are allowed.\n");
        } else {
            convertToBinary(decimalNumber);
        }

        printf("Would you like to convert another number? (y/n): ");
        scanf(" %c", &continueConversion);
    }

    printf("Thank you for using the Binary Converter. Goodbye!\n");
    return 0;
}

void showMenu() {
    printf("----------------------------------------------------\n");
    printf("            Welcome to the Binary Converter        \n");
    printf("----------------------------------------------------\n");
    printf("This program will help you convert decimal numbers to binary.\n");
    printf("You will see both normal and inverted binary representations.\n");
    printf("----------------------------------------------------\n");
}

int getUserInput() {
    int number;
    printf("Please enter a non-negative integer: ");
    while (scanf("%d", &number) != 1 || number < 0) {
        printf("Invalid input! Please enter a non-negative integer: ");
        while (getchar() != '\n'); // Clear buffer
    }
    return number;
}

void convertToBinary(int decimal) {
    printf("Binary representation of %d:\n", decimal);
    printBinary(decimal, 0);
    printf("Inverted binary representation of %d:\n", decimal);
    printBinary(decimal, 1);
}

void printBinary(int decimal, int inverted) {
    int binary[32]; // Array to hold binary digits
    int index = 0;

    // Edge case for zero
    if (decimal == 0) {
        printf("0\n");
        return;
    }

    // Filling binary array
    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }

    // Print binary in reverse order for normal representation
    if (inverted) {
        for (int i = index - 1; i >= 0; i--) {
            printf("%d", binary[i] ^ 1); // Invert each bit
        }
    } else {
        for (int i = index - 1; i >= 0; i--) {
            printf("%d", binary[i]); // Normal representation
        }
    }
    printf("\n");
}