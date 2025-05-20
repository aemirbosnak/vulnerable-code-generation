//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
void decimalToHexadecimal(int decimal);
void hexadecimalToDecimal(char hexadecimal[]);
void clearInputBuffer();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-3 or 0 to exit): ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear input buffer

        switch (choice) {
            case 1: {
                int decimal;
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                clearInputBuffer(); // Clear input buffer
                decimalToHexadecimal(decimal);
                break;
            }
            case 2: {
                char hexadecimal[20];
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexadecimal);
                clearInputBuffer(); // Clear input buffer
                hexadecimalToDecimal(hexadecimal);
                break;
            }
            case 3: {
                printf("Would you like to decode/encode another value? (yes/no): ");
                char response[4];
                scanf("%3s", response);
                clearInputBuffer(); // Clear input buffer
                if (response[0] == 'n' || response[0] == 'N') {
                    choice = 0; // Exiting the loop
                }
                break;
            }
            case 0: 
                printf("Exiting the program. Goodbye!\n");
                break;
            default: 
                printf("Invalid choice. Please select again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

// Function to display a menu of options
void displayMenu() {
    printf("\n--- Hexadecimal Converter Menu ---\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Check for additional conversions\n");
    printf("0. Exit\n");
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    printf("Converting decimal %d to hexadecimal: ", decimal);
    if (decimal == 0) {
        printf("0\n");
        return;
    }
    char hex[20];
    int i = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        // Convert remainder to appropriate hex character
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder - 10 + 'A';
        }
        decimal = decimal / 16;
        i++;
    }
    hex[i] = '\0';
    
    // Print hex in reverse order
    printf("0x");
    for (--i; i >= 0; i--) {
        putchar(hex[i]);
    }
    printf("\n");
}

// Function to convert hexadecimal to decimal
void hexadecimalToDecimal(char hexadecimal[]) {
    int decimal = 0;
    int base = 1; // 16^0
    int length = 0;
    
    // Calculate length
    while (hexadecimal[length] != '\0') {
        length++;
    }
    
    // Convert hex to decimal
    for (int i = length - 1; i >= 0; i--) {
        char ch = hexadecimal[i];
        if (ch >= '0' && ch <= '9') {
            decimal += (ch - '0') * base;
        } else if (ch >= 'A' && ch <= 'F') {
            decimal += (ch - 'A' + 10) * base;
        } else if (ch >= 'a' && ch <= 'f') {
            decimal += (ch - 'a' + 10) * base;
        } else {
            printf("Invalid hexadecimal input!\n");
            return; // Exit on invalid input
        }
        base *= 16; // Increment base for next digit
    }
    
    printf("Hexadecimal %s is equal to decimal %d\n", hexadecimal, decimal);
}

// Function to clear the input buffer
void clearInputBuffer() {
    while (getchar() != '\n'); // Discard characters until the end of the line
}