//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void printBinary(int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; --i) {
        putchar((n & (1 << i)) ? '1' : '0');
    }
}

void printHex(int n) {
    printf("0x%X\n", n);
}

void convertToHex(char *input) {
    int decimalValue;

    if (sscanf(input, "%d", &decimalValue) == 1) {
        printf("Converted Value:\n");
        printf("Decimal: %d\n", decimalValue);
        printf("Hexadecimal: ");
        printHex(decimalValue);
        printf("Binary: ");
        printBinary(decimalValue);
        printf("\n");
    } else {
        printf("Invalid input. Please enter a valid integer.\n");
    }
}

void convertToDecimal(char *input) {
    int decimalValue = 0;

    sscanf(input, "%X", &decimalValue);
    printf("Converted Value:\n");
    printf("Hexadecimal: %s\n", input);
    printf("Decimal: %d\n", decimalValue);
    printf("Binary: ");
    printBinary(decimalValue);
    printf("\n");
}

void showMenu() {
    printf("Hexadecimal Converter\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char input[MAX_SIZE];
    int choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar();  // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                fgets(input, MAX_SIZE, stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                convertToHex(input);
                break;
            case 2:
                printf("Enter a hexadecimal number (without 0x prefix): ");
                fgets(input, MAX_SIZE, stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline
                convertToDecimal(input);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}