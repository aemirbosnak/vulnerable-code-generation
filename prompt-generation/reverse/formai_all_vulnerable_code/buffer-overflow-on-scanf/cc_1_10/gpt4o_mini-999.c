//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    if (decimal == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }
    
    char hex[20]; // Buffer to hold hexadecimal digits
    int index = 0; // Index to track position in hex buffer

    while (decimal > 0) {
        int remainder = decimal % 16; // Get remainder for hex digit

        // Convert remainder to corresponding hex character
        if (remainder < 10) {
            hex[index++] = remainder + '0'; // 0-9
        } else {
            hex[index++] = (remainder - 10) + 'A'; // A-F
        }

        decimal /= 16; // Divide decimal by 16
    }

    // Print the result starting from the last character added
    printf("Hexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]); // Output each hex character
    }
    printf("\n");
}

// Function to display an interactive menu
void displayMenu() {
    printf("********************************\n");
    printf("* Welcome to Decimal to Hex Converter! *\n");
    printf("********************************\n");
    printf("1. Convert a decimal number\n");
    printf("2. Exit\n");
    printf("********************************\n");
}

// Main function
int main() {
    int choice; // Variable to store user's choice
    int decimalNumber; // Variable to hold the number to be converted

    do {
        displayMenu(); // Show the menu
        printf("Enter your choice: ");
        scanf("%d", &choice); // Take input for menu choice

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber); // Take input of decimal number
                decimalToHexadecimal(decimalNumber); // Convert to hex
                break;
            case 2:
                printf("Thank you for using the converter! Goodbye! 🎉\n");
                break;
            default:
                printf("Invalid choice. Please try again! ⚠️\n");
        }
    } while (choice != 2); // Repeat until the user chooses to exit

    return 0; // End of the program
}