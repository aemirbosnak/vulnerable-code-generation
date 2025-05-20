//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold decimal and hexadecimal values
typedef struct {
    int decimal;
    char hex[20];
} HexConverter;

// Function prototypes
void decimalToHex(int decimal, char *hex);
void printMenu();
void handleUserInput();

// Main function
int main() {
    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    handleUserInput();
    return 0;
}

// Function to convert decimal to hexadecimal
void decimalToHex(int decimal, char *hex) {
    int index = 0;
    if (decimal == 0) {
        strcpy(hex, "0");
        return;
    }
    
    while (decimal > 0) {
        int remainder = decimal % 16;
        
        // Convert remainder to hex character
        if (remainder < 10) {
            hex[index++] = remainder + '0';
        } else {
            hex[index++] = (remainder - 10) + 'A';
        }
        decimal /= 16;
    }
    
    // Reverse the hex string
    hex[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }
}

// Function to print the main menu
void printMenu() {
    printf("\nMenu:\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
}

// Function to handle user input
void handleUserInput() {
    int choice;
    int decimal;
    HexConverter converter;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                
                // Convert and store in the structure
                converter.decimal = decimal;
                decimalToHex(decimal, converter.hex);
                
                // Print the result
                printf("Decimal: %d\n", converter.decimal);
                printf("Hexadecimal: %s\n", converter.hex);
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);
}