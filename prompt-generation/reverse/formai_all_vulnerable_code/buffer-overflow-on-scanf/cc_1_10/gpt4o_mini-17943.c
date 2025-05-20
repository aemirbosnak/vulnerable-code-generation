//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void printBinary(int n) {
    // Create a buffer to hold the binary representation
    char binary[33]; // 32 bits for an integer + 1 for the null terminator
    binary[32] = '\0'; // Null terminate the string

    // Fill the binary array from back to front
    for (int i = 31; i >= 0; i--) {
        binary[i] = (n % 2) ? '1' : '0'; // Set the bit at this position
        n /= 2; // Shift right
    }

    // Print the binary representation
    printf("Binary representation: %s\n", binary);
}

void convertDecimalToBinary() {
    int decimalNumber;

    // Welcome message
    printf("Welcome to the Peaceful Binary Converter!\n");
    printf("Please enter a decimal number (non-negative integer): ");

    // Input handling in a calm manner
    while (scanf("%d", &decimalNumber) != 1 || decimalNumber < 0) {
        printf("That's not a valid non-negative integer. Please try again: ");
        while (getchar() != '\n'); // Clear the buffer
    }

    // Call the function to print binary format of the input
    printBinary(decimalNumber);
}

void menu() {
    int choice;

    printf("\n--- Peaceful Binary Converter Menu ---\n");
    printf("1. Convert a Decimal Number to Binary\n");
    printf("2. Exit\n");
    printf("---------------------------------------\n");
    printf("Please choose an option (1-2): ");

    // Input handling for menu choice
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 2) {
        printf("Invalid choice! Please select 1 or 2: ");
        while (getchar() != '\n'); // Clear the buffer
    }

    // Process user's choice
    if (choice == 1) {
        convertDecimalToBinary();
    } else {
        printf("Thank you for using the Peaceful Binary Converter. Have a lovely day!\n");
        exit(0); // Exit the program gracefully
    }
}

int main() {
    // Simple infinite loop to keep the program running
    while (1) {
        menu(); // Display the menu and handle user input
    }
    return 0; // End of main
}