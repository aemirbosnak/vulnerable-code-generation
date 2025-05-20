//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void welcomeMessage();
unsigned long long decimalToBinary(int decimal);
void displayBinary(unsigned long long binary);
void askForAnotherConversion();

int main() {
    welcomeMessage(); // Display welcome message
    int decimal;

    while (1) {
        printf("Please enter a decimal number (0 to exit): ");
        scanf("%d", &decimal);

        if (decimal < 0) {
            printf("Only non-negative integers are allowed. Please try again!\n");
            continue;
        }
        if (decimal == 0) {
            printf("Exiting the program. Goodbye!\n");
            break; // Exit condition
        }

        unsigned long long binary = decimalToBinary(decimal); // Convert to binary
        printf("The binary representation of %d is: ", decimal);
        displayBinary(binary); // Display the binary representation

        askForAnotherConversion(); // Ask user if they want to convert another number
    }

    return 0; // Exit the program successfully
}

// Function to display a welcome message
void welcomeMessage() {
    printf("*************************************\n");
    printf("*  Welcome to the Decimal to Binary  *\n");
    printf("*            Converter                *\n");
    printf("*************************************\n");
}

// Function to convert decimal to binary
unsigned long long decimalToBinary(int decimal) {
    unsigned long long binary = 0;
    unsigned long long place = 1;

    while (decimal > 0) {
        int remainder = decimal % 2;
        binary += remainder * place; // Build the binary number
        decimal /= 2;
        place *= 10; // Move to the next place
    }

    return binary; // Return the binary number
}

// Function to display the binary number
void displayBinary(unsigned long long binary) {
    printf("%llu\n", binary);
}

// Function to ask if the user wants to convert another decimal number
void askForAnotherConversion() {
    printf("Would you like to convert another decimal number? (y/n): ");
    char answer;
    while (1) {
        scanf(" %c", &answer); // Reading the user's response
        if (answer == 'y' || answer == 'Y') {
            printf("Great! Let's convert another number.\n");
            break;
        } else if (answer == 'n' || answer == 'N') {
            printf("Thank you for using the Decimal to Binary Converter!\n");
            printf("See you next time!\n");
            exit(0); // Exit the program
        } else {
            printf("Invalid input. Please enter 'y' or 'n': "); // Handling invalid input
        }
    }
}