//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256

void printMenu() {
    printf("\nHexadecimal Converter Program\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

void decimalToHexadecimal() {
    long decimalNumber;
    printf("Enter a decimal number: ");
    if (scanf("%ld", &decimalNumber) != 1 || decimalNumber < 0) {
        printf("Invalid input. Please enter a valid non-negative integer.\n");
        while(getchar() != '\n'); // Clear buffer
        return;
    }
    
    char hexNumber[MAX_INPUT_SIZE];
    snprintf(hexNumber, sizeof(hexNumber), "%lX", decimalNumber);
    
    printf("Decimal: %ld = Hexadecimal: %s\n", decimalNumber, hexNumber);
}

void hexadecimalToDecimal() {
    char hexNumber[MAX_INPUT_SIZE];
    printf("Enter a hexadecimal number (without 0x prefix): ");
    scanf("%s", hexNumber);
    
    // Validate input for hexadecimal characters
    for (int i = 0; hexNumber[i] != '\0'; i++) {
        hexNumber[i] = toupper(hexNumber[i]); // Convert to uppercase
        if (!((hexNumber[i] >= '0' && hexNumber[i] <= '9') || 
               (hexNumber[i] >= 'A' && hexNumber[i] <= 'F'))) {
            printf("Invalid hexadecimal input. Please use digits 0-9 and letters A-F.\n");
            return;
        }
    }

    long decimalNumber = strtol(hexNumber, NULL, 16);
    printf("Hexadecimal: %s = Decimal: %ld\n", hexNumber, decimalNumber);
}

int main() {
    int choice;
    
    do {
        printMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter an integer between 1 and 3.\n");
            while(getchar() != '\n'); // Clear buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                decimalToHexadecimal();
                break;
            case 2:
                hexadecimalToDecimal();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select an option from the menu.\n");
        }
    } while (choice != 3);

    return 0;
}