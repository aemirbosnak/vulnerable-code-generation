//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printBinary(int n);
void convertDecimalToBinary();
void welcomeMessage();

int main() {
    welcomeMessage(); // Show the welcoming message to the user
    convertDecimalToBinary(); // Start the conversion process
    return 0; // End the program successfully
}

// This function displays a whimsical welcome message to the user
void welcomeMessage() {
    printf("------------------------------------------------------------\n");
    printf("✨ Welcome to the Decimal to Binary Converter! ✨\n");
    printf("------------------------------------------------------------\n");
    printf("Let's embark on this binary adventure together!\n\n");
    printf("We'll convert a number you choose into its binary form. 🎉\n");
    printf("Get ready to see some fun binary magic! 🔮\n");
}

// This function converts a decimal number into binary and displays it
void convertDecimalToBinary() {
    int decimalNumber;

    printf("Enter a positive decimal number (0 to stop): ");
    
    while (1) {
        scanf("%d", &decimalNumber); // Take input from user

        if (decimalNumber < 0) {
            printf("Oops! Negative numbers are not allowed. Try again!\n");
        } else if (decimalNumber == 0) {
            printf("You chose to exit! Thank you for playing! 😊\n");
            break; // Exit if the user inputs 0
        } else {
            printf("Decimal: %d -> ", decimalNumber);
            printf("Binary: ");
            printBinary(decimalNumber); // Call to binary printing function
            printf("\n"); // New line for better readability
        }

        printf("Enter another positive decimal number (0 to stop): ");
    }
}

// This function prints the binary representation of the decimal number
void printBinary(int n) {
    if (n == 0) {
        printf("0"); // Edge case for 0
        return;
    }

    int binary[32]; // Array to store binary digits
    int index = 0; // Index for current position in array

    while (n > 0) {
        binary[index] = n % 2; // Storing remainder (binary digit)
        n = n / 2; // Reduce n for next iteration
        index++; // Move to next binary position
    }

    // Print the binary representation in the correct order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]); // Print array in reverse
    }
}