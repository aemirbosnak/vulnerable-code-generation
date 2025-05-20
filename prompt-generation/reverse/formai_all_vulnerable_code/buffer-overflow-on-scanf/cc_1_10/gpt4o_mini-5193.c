//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to convert decimal to hexadecimal
void decimalToHex(int decimal, char *hex) {
    int index = 0;

    // Handle 0 case
    if (decimal == 0) {
        hex[index++] = '0';
    }

    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[index++] = remainder + '0';
        } else {
            hex[index++] = (remainder - 10) + 'A';
        }
        decimal /= 16;
    }

    // Reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }
    
    hex[index] = '\0'; // Null-terminate the string
}

// Function to print the menu
void printMenu() {
    printf("\nHexadecimal Converter\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

// Function to get input from the user
int getInput() {
    int number;
    printf("Enter a decimal number: ");
    scanf("%d", &number);
    return number;
}

// Function to validate the input
int validateInput(int input) {
    return input >= 0; // We're only interested in non-negative decimals
}

// Main program to execute the converter
int main() {
    int choice;
    char hex[MAX_LENGTH];

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int decimal = getInput();

                // Validate input
                if (!validateInput(decimal)) {
                    printf("Please enter a non-negative decimal number.\n");
                    break;
                }

                decimalToHex(decimal, hex);
                printf("Decimal: %d -> Hexadecimal: %s\n", decimal, hex);
                break;
            }
            case 2:
                printf("Exiting the converter. Goodbye!\n");
                break;
            default:
                printf("Invalid selection, please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}