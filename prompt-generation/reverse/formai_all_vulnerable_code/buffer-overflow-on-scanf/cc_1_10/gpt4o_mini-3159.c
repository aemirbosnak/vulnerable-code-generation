//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    char binary[32];
    int index = 0;

    while (n > 0) {
        binary[index++] = (n % 2) + '0';
        n = n / 2;
    }

    // Printing binary in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }
}

// Function to prompt user for a number
int getUserInput() {
    int number;
    printf("Enter a positive decimal number: ");
    while (scanf("%d", &number) != 1 || number < 0) {
        printf("That's not a valid positive number! Try again: ");
        while(getchar() != '\n'); // Clear invalid input
    }
    return number;
}

// Function to display a welcome message and instructions
void displayWelcomeMessage() {
    printf("========== Welcome to the Magical Decimal to Binary Converter! ==========\n");
    printf("In this enchanted realm, you shall input a positive whole number,\n");
    printf("and witness the majestic transformation into the mystical binary world!\n");
    printf("Let the conversion commence...\n");
    printf("=======================================================================\n");
}

// Function to ask the user if they want to convert another number
char askToContinue() {
    char choice;
    printf("Would you like to convert another number? (y/n): ");
    while (scanf(" %c", &choice) != 1 || (choice != 'y' && choice != 'n')) {
        printf("Please enter 'y' for yes or 'n' for no: ");
    }
    return choice;
}

// Main function
int main() {
    int number;
    char continueChoice;

    displayWelcomeMessage();

    do {
        number = getUserInput();
        printf("The binary representation of %d is: ", number);
        decimalToBinary(number);
        printf("\n");
        
        continueChoice = askToContinue();
    } while (continueChoice == 'y');

    printf("Thank you for visiting our magical world of numbers! Until next time!\n");
    return 0;
}