//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void decimalToHexadecimal(int decimal);
int hexadecimalToDecimal(const char* hex);
void displayMenu();
void executeOption(int option);

// Main function
int main() {
    int option;

    do {
        displayMenu();
        printf("Enter your choice (1-3) or 0 to exit: ");
        scanf("%d", &option);
        executeOption(option);
    } while (option != 0);

    printf("Exiting the Hexadecimal Converter. Goodbye!\n");
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n======================\n");
    printf(" Hexadecimal Converter\n");
    printf("======================\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Convert a String to Hexadecimal Representation\n");
    printf("0. Exit\n");
}

// Function to execute user's chosen option
void executeOption(int option) {
    char hex[20];
    int decimal;

    switch (option) {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            decimalToHexadecimal(decimal);
            break;

        case 2:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hex);
            decimal = hexadecimalToDecimal(hex);
            if (decimal != -1) {
                printf("Decimal equivalent: %d\n", decimal);
            }
            break;

        case 3:
            printf("Enter a string to convert to hexadecimal: ");
            char inputString[256];
            getchar();  // Clearing newline from buffer
            fgets(inputString, sizeof(inputString), stdin);
            inputString[strcspn(inputString, "\n")] = 0;  // Remove newline character

            printf("Hexadecimal representation: ");
            for (int i = 0; inputString[i] != '\0'; i++) {
                printf("%02X ", (unsigned char)inputString[i]);
            }
            printf("\n");
            break;

        case 0:
            // Exit the program
            break;

        default:
            printf("Invalid option, please try again.\n");
            break;
    }
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    if (decimal < 0) {
        printf("Please enter a positive integer.\n");
        return;
    }
    
    printf("Hexadecimal representation: %X\n", decimal);
}

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(const char* hex) {
    int decimal = 0;
    char* endptr;
    
    // Convert hex string to decimal
    decimal = (int)strtol(hex, &endptr, 16);

    // Check if conversion went as expected
    if (*endptr != '\0') {
        printf("Invalid hexadecimal input.\n");
        return -1;  // Indicate an error
    }
    
    return decimal;
}