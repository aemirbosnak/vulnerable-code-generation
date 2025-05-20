//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu() {
    printf("\nHexadecimal Converter Menu:\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Please select an option (1-3): ");
}

void decimalToHexadecimal(int decimal) {
    char hexadecimal[20];
    int index = 0;
    
    // Handle special case for 0
    if (decimal == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    while (decimal != 0) {
        int remainder = decimal % 16;

        // Convert remainder to the respective hex character
        if (remainder < 10) {
            hexadecimal[index++] = 48 + remainder;  // 48 is ASCII for '0'
        } else {
            hexadecimal[index++] = 55 + remainder;  // 55 is ASCII for 'A'
        }
        
        decimal /= 16;
    }
    
    printf("Hexadecimal: ");
    for (int j = index - 1; j >= 0; j--) {
        putchar(hexadecimal[j]);
    }
    printf("\n");
}

void hexadecimalToDecimal(char hex[]) {
    int decimal = 0;
    int base = 1;  // 16^0
    int len = strlen(hex);
    
    for (int i = len - 1; i >= 0; i--) {
        char ch = hex[i];

        // Convert hex digit to decimal
        if (ch >= '0' && ch <= '9') {
            decimal += (ch - 48) * base;  // 48 is ASCII for '0'
        } else if (ch >= 'A' && ch <= 'F') {
            decimal += (ch - 55) * base;  // 55 is ASCII for 'A'
        } else if (ch >= 'a' && ch <= 'f') {
            decimal += (ch - 87) * base;  // 87 is ASCII for 'a'
        } else {
            printf("Invalid hexadecimal input.\n");
            return;
        }
        
        base *= 16;  // Move to the next position
    }

    printf("Decimal: %d\n", decimal);
}

int main() {
    int option;
    char hexInput[20];  // Buffer for hexadecimal input
    int decimalInput;    // For decimal input

    while (1) {
        printMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalInput);
                decimalToHexadecimal(decimalInput);
                break;
            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexInput);
                hexadecimalToDecimal(hexInput);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}