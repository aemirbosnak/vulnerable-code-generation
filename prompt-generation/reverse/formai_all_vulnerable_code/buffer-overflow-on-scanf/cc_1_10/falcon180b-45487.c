//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int i = strlen(binary) - 1;

    // Iterate through the binary string from right to left
    while (i >= 0) {
        // Check if the current character is a '1'
        if (binary[i] == '1') {
            // If it is, add 2^power to the decimal value
            decimal += pow(2, power);
        }
        // Increment the power variable
        power++;
        // Move to the next character in the string
        i--;
    }

    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal, char* binary) {
    int i = 0;

    // Iterate until the decimal value becomes 0
    while (decimal > 0) {
        // Add the remainder of the division to the binary string
        binary[i] = (decimal % 2) + '0';
        // Divide the decimal value by 2
        decimal /= 2;
        // Increment the index variable
        i++;
    }

    // Terminate the binary string with a null character
    binary[i] = '\0';
}

// Function to reverse a string
void reverseString(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    char temp;

    // Iterate through the string, swapping characters
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char binary[MAX_SIZE];
    char decimal[MAX_SIZE];
    int choice;
    int decimalValue;

    do {
        // Display the menu options
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Exit\n");

        // Prompt the user to choose an option
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Convert the input to uppercase
        choice = toupper(choice);

        // Perform the selected conversion
        switch (choice) {
            case '1': // Binary to Decimal
                printf("Enter a binary number: ");
                scanf("%s", binary);

                // Convert the binary string to decimal
                decimalValue = binaryToDecimal(binary);

                // Output the result
                printf("The decimal equivalent of %s is %d.\n", binary, decimalValue);
                break;

            case '2': // Decimal to Binary
                printf("Enter a decimal number: ");
                scanf("%d", &decimalValue);

                // Convert the decimal value to binary
                sprintf(binary, "%b", decimalValue);

                // Output the result
                printf("The binary equivalent of %d is %s.\n", decimalValue, binary);
                break;

            case '3': // Exit
                printf("Exiting...\n");
                break;

            default: // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }

        // Ask the user if they want to continue
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

        // Convert the input to uppercase
        choice = toupper(choice);

        // Exit the loop if the user chooses 'n'
        if (choice == 'N') {
            break;
        }

    } while (1);

    return 0;
}