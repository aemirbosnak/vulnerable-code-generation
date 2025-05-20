//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to hexadecimal
void decimalToHex(int decimal, char *hex) {
    int index = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[index] = remainder + '0';
        } else {
            hex[index] = remainder - 10 + 'A';
        }
        decimal /= 16;
        index++;
    }
    hex[index] = '\0';
    
    // Reverse the hex string
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }
}

// Function to convert hexadecimal to decimal
int hexToDecimal(const char *hex) {
    int decimal = 0;
    int base = 1; // 16^0
    int length = strlen(hex);
    
    for (int i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 'a' + 10) * base;
        }
        base *= 16; // Increment base
    }
    
    return decimal;
}

// Function to display menu options
void displayMenu() {
    printf("Hexadecimal Converter\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

// Main function implementing a console application
int main() {
    int choice;
    char hex[20];
    int decimal;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        // Handling menu options
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToHex(decimal, hex);
                printf("Hexadecimal: %s\n\n", hex);
                break;
            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                decimal = hexToDecimal(hex);
                printf("Decimal: %d\n\n", decimal);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }
    
    return 0;
}