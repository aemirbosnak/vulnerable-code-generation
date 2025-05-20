//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void printHex(int num) {
    printf("Hexadecimal: %X\n", num);
}

void printBinary(int num) {
    if (num > 1) {
        printBinary(num >> 1);
    }
    printf("%d", num & 1);
}

void displayWelcomeMessage() {
    printf("Welcome to the C Hexadecimal Converter!\n");
    printf("You can convert decimal numbers to hexadecimal and view them in binary as well.\n");
    printf("_____________________________________________________\n");
}

void handleInput() {
    int number;
    printf("Please enter a decimal number (positive integer): ");
    if (scanf("%d", &number) != 1 || number < 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return;
    }

    // Call functions to display results
    printHex(number);
    printf("Binary representation: ");
    printBinary(number);
    printf("\n");
}

void repeatConversion() {
    char choice;
    do {
        handleInput();
        printf("Would you like to convert another number? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n'); // Clear newline from buffer
    } while (choice == 'y' || choice == 'Y');
}

int main() {
    displayWelcomeMessage();
    repeatConversion();
    printf("Thank you for using the C Hexadecimal Converter. Goodbye!\n");
    return 0;
}