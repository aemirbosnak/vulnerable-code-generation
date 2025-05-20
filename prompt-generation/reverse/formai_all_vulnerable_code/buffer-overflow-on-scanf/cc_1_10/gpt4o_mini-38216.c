//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 20

void printMenu() {
    printf("\nHexadecimal Converter\n");
    printf("======================\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

void convertDecimalToHexadecimal() {
    unsigned int decimalValue;
    printf("Enter a decimal number: ");
    if (scanf("%u", &decimalValue) != 1) {
        while (getchar() != '\n'); // Clear the stdin buffer
        printf("Invalid input. Please enter a valid decimal number.\n");
        return;
    }

    char hexValue[9]; // 8 characters for hex + 1 for null terminator
    snprintf(hexValue, sizeof(hexValue), "%X", decimalValue);
    
    printf("Decimal: %u -> Hexadecimal: %s\n", decimalValue, hexValue);
}

void convertHexadecimalToDecimal() {
    char hexInput[MAX_INPUT_LENGTH + 1];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hexInput);
    
    for (int i = 0; hexInput[i]; i++) {
        hexInput[i] = toupper(hexInput[i]); // Convert to uppercase
    }

    char *endPtr;
    unsigned long decimalValue = strtoul(hexInput, &endPtr, 16);
    
    if (endPtr == hexInput || *endPtr != '\0') {
        printf("Invalid input. Please enter a valid hexadecimal number.\n");
    } else {
        printf("Hexadecimal: %s -> Decimal: %lu\n", hexInput, decimalValue);
    }
}

void handleInput() {
    int option;
    do {
        printMenu();
        if (scanf("%d", &option) != 1) {
            while (getchar() != '\n'); // Clear the stdin buffer
            printf("Invalid selection. Please enter a number corresponding to an option.\n");
            option = 0; // Reset option to continue loop
        }
        
        switch (option) {
            case 1: 
                convertDecimalToHexadecimal();
                break;
            case 2:
                convertHexadecimalToDecimal();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please choose a valid option from the menu.\n");
        }
        
        sleep(1); // Pause for a second before re-displaying the menu
    } while (option != 3);
}

int main() {
    printf("Welcome to the Hexadecimal Converter!\n");
    handleInput();
    
    return 0;
}