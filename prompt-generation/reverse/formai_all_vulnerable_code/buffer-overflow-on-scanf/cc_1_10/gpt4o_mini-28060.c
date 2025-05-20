//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to hexadecimal
void decimalToHex(int decimal, char *hex) {
    int index = 0;
    
    // Handle zero
    if (decimal == 0) {
        strcpy(hex, "0");
        return;
    }

    while (decimal != 0) {
        int remainder = decimal % 16;

        // Convert remainder to corresponding hex character
        if (remainder < 10) {
            hex[index] = remainder + '0'; // Convert int to char
        } else {
            hex[index] = (remainder - 10) + 'A'; // Convert int to char (A-F)
        }
        index++;
        decimal /= 16; // Reduce the decimal number
    }
    hex[index] = '\0'; // Null-terminate the string

    // Reverse the hex string
    for (int start = 0, end = index - 1; start < end; start++, end--) {
        char temp = hex[start];
        hex[start] = hex[end];
        hex[end] = temp;
    }
}

// Function to convert hexadecimal to decimal
int hexToDecimal(const char *hex) {
    int decimal = 0;
    int base = 1; // Base is 16^0

    // Process each character from right to left
    for (int i = strlen(hex) - 1; i >= 0; i--) {
        char c = hex[i];

        // Convert character to value
        int value;
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else {
            printf("Invalid hexadecimal character detected: %c\n", c);
            return -1; // Error code for invalid input
        }
        
        // Add value to the decimal number
        decimal += value * base;
        base *= 16; // Move to the next power of 16
    }
    return decimal;
}

// Function to display menu
void displayMenu() {
    printf("\n--- Hexadecimal Converter ---\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("-----------------------------\n");
    printf("Enter your choice: ");
}

// Main function
int main() {
    int choice;
    int decimal;
    char hex[20]; // Buffer for hexadecimal representation

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Decimal to Hexadecimal
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToHex(decimal, hex);
                printf("Hexadecimal representation: %s\n", hex);
                break;

            case 2:
                // Hexadecimal to Decimal
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                int result = hexToDecimal(hex);
                
                if (result != -1) { // If conversion was successful
                    printf("Decimal representation: %d\n", result);
                }
                break;

            case 3:
                // Exit
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}