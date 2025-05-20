//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

// Function prototypes
void convertToHexadecimal(int decimal);
void convertToDecimal(const char *hex);

void printMenu() {
    printf("=== Hexadecimal Converter ===\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("============================\n");
}

int main() {
    int choice;
    char hexInput[MAX_INPUT_SIZE];
    int decimalInput;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalInput);
                printf("Decimal: %d -> Hexadecimal: ", decimalInput);
                convertToHexadecimal(decimalInput);
                break;
                
            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexInput);
                printf("Hexadecimal: %s -> Decimal: ", hexInput);
                convertToDecimal(hexInput);
                break;

            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}

void convertToHexadecimal(int decimal) {
    if (decimal < 0) {
        printf("Invalid input. Decimal number must be non-negative.\n");
        return;
    }

    char hex[100];
    int index = 0;

    if (decimal == 0) {
        printf("0");
        return;
    }

    while (decimal != 0) {
        int remainder = decimal % 16;

        // Convert remainder to appropriate hex character
        if (remainder < 10) {
            hex[index++] = 48 + remainder; // 48 is '0'
        } else {
            hex[index++] = 87 + remainder; // 87 is 'a' - 10
        }
        
        decimal /= 16;
    }

    // Print hexadecimal in reverse order
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]);
    }

    // New line after hex output
    printf("\n");
}

void convertToDecimal(const char *hex) {
    int len = strlen(hex);
    int base = 1; // 16^0
    int decimal = 0;

    // Convert hex string to decimal
    for (int i = len - 1; i >= 0; i--) {
        char c = hex[i];

        // Convert character to decimal value
        int value;
        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            value = 10 + (c - 'a');
        } else if (c >= 'A' && c <= 'F') {
            value = 10 + (c - 'A');
        } else {
            printf("Invalid hexadecimal digit: %c\n", c);
            return;
        }

        decimal += value * base;
        base *= 16; // Increase base for next digit
    }

    printf("%d\n", decimal);
}