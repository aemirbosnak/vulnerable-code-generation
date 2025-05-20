//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void toBinary(int n);
void displayMenu();
void inputNumber(int *num);
void convertAndDisplay(int num);
void repeatAction();
void handleInvalidInput();

// Main function
int main() {
    int num;
    char choice;

    do {
        displayMenu();
        inputNumber(&num);
        convertAndDisplay(num);
        repeatAction();
        printf("Would you like to convert another number? (y/n): ");
        while ((getchar()) != '\n'); // Clear the input buffer
        choice = getchar();
        printf("\n");
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Binary Converter Program.\n");
    return 0;
}

// Function to convert an integer to binary and display it
void toBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    int binary[32]; // Array to hold binary digits
    int index = 0;

    while (n > 0) {
        binary[index] = n % 2; // Store the remainder
        n = n / 2;
        index++;
    }

    printf("Binary representation: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]); // Print in reverse order
    }
    printf("\n");
}

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Binary Converter!\n");
    printf("Please choose an option from the menu below:\n");
    printf("1. Convert an integer to binary\n");
}

// Function to input a number from the user
void inputNumber(int *num) {
    printf("Enter an integer: ");
    while (scanf("%d", num) != 1) {
        handleInvalidInput();
        printf("Please enter a valid integer: ");
    }
}

// Function to convert and display the binary representation
void convertAndDisplay(int num) {
    printf("Decimal number: %d\n", num);
    printf("Converting to binary...\n");
    toBinary(num);
}

// Function to repeat the action based on user input
void repeatAction() {
    char option[6];
    printf("Do you want to perform another conversion? Type 'yes' or 'no': ");
    scanf("%5s", option);
    
    // Check for valid input
    if (strcmp(option, "yes") == 0 || strcmp(option, "Yes") == 0) {
        return;
    } else if (strcmp(option, "no") == 0 || strcmp(option, "No") == 0) {
        return;
    } else {
        printf("Invalid input! Moving on to the next operation.\n");
    }
}

// Function to handle invalid input
void handleInvalidInput() {
    while (getchar() != '\n'); // Clear input buffer
    printf("Invalid input detected! Please enter a valid integer.\n");
}