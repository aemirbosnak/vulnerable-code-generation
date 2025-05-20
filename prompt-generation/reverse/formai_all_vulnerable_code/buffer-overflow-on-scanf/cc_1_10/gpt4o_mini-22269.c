//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void decimalToBinary(int n);
void displayMenu();
int getChoice();
int getNumber();

int main() {
    int choice, number;

    while (1) {
        displayMenu();
        choice = getChoice();
        
        if (choice == 3) {
            printf("Exiting the program.\n");
            break;
        }

        number = getNumber();

        switch (choice) {
            case 1:
                printf("Decimal to Binary Conversion of %d: ", number);
                decimalToBinary(number);
                printf("\n");
                break;
            case 2:
                printf("Binary to Decimal Conversion is not supported in this version.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

// Function to convert decimal to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    char binary[32]; // Assuming 32 bits for binary representation
    int index = 0;

    while (n > 0) {
        binary[index++] = (n % 2) + '0'; // Store binary digits as characters
        n /= 2;
    }

    // Print the binary digits in reverse order
    for (int j = index - 1; j >= 0; j--) {
        putchar(binary[j]);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Binary Converter Menu ---\n");
    printf("1. Decimal to Binary Conversion\n");
    printf("2. Binary to Decimal Conversion (Not Implemented)\n");
    printf("3. Exit\n");
    printf("-----------------------------\n");
}

// Function to get user's choice
int getChoice() {
    int choice;
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n'); // Clear invalid input
        choice = 0;
    }
    return choice;
}

// Function to get number input from the user
int getNumber() {
    int number;
    printf("Enter a decimal number: ");
    while (scanf("%d", &number) != 1) {
        while (getchar() != '\n'); // Clear invalid input
        printf("Invalid input. Please enter a decimal number: ");
    }
    return number;
}