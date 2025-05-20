//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display the menu
void displayMenu() {
    printf("\n");
    printf("=================================\n");
    printf("    HEXADECIMAL CONVERTER\n");
    printf("=================================\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("=================================\n");
    printf("Choose an option (1-3): ");
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    char hex[100];
    int index = 0;
    
    // Converting to hexadecimal representation
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[index++] = 48 + remainder; // 0-9
        } else {
            hex[index++] = 55 + remainder; // A-F
        }
        decimal /= 16;
    }
    
    // Print the hexadecimal value in reverse order
    printf("Hexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]);
    }
    printf("\n");
}

// Function to convert hexadecimal to decimal
void hexadecimalToDecimal(char hex[]) {
    int decimal = 0;
    int base = 1; // 16^0

    // Length of hexadecimal string
    int len = strlen(hex);
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base; // 0-9
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base; // A-F
        }
        base *= 16;
    }

    printf("Decimal: %d\n", decimal);
}

// Main function
int main() {
    int choice;
    int decimal;
    char hex[100];

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToHexadecimal(decimal);
                break;
            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);

                // Convert to uppercase for consistency
                for (int i = 0; hex[i]; i++) {
                    hex[i] = toupper(hex[i]);
                }
                hexadecimalToDecimal(hex);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}