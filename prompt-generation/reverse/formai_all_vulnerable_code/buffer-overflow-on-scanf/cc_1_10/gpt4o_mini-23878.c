//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void printMenu();
void decimalToHexadecimal(int decimal);
void hexadecimalToDecimal(char hex[]);
void clearInputBuffer();

int main() {
    int choice;
    int decimalNumber;
    char hexNumber[20];

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();  // Clear the input buffer

        switch (choice) {
            case 1:
                // Decimal to Hexadecimal
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                clearInputBuffer();  // Clear the input buffer
                printf("Hexadecimal representation: ");
                decimalToHexadecimal(decimalNumber);
                printf("\n");
                break;

            case 2:
                // Hexadecimal to Decimal
                printf("Enter a hexadecimal number: ");
                fgets(hexNumber, sizeof(hexNumber), stdin);
                // Remove newline character if present
                hexNumber[strcspn(hexNumber, "\n")] = 0; 
                printf("Decimal representation: ");
                hexadecimalToDecimal(hexNumber);
                printf("\n");
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

void printMenu() {
    printf("\n--- Hexadecimal Converter ---\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
}

void decimalToHexadecimal(int decimal) {
    if (decimal < 0) {
        printf("Please enter a non-negative integer.\n");
        return;
    }

    if (decimal == 0) {
        printf("0");
        return;
    }

    char hex[20];
    int index = 0;

    while (decimal != 0) {
        int remainder = decimal % 16;

        // Convert remainder to hex digit
        if (remainder < 10) {
            hex[index++] = remainder + '0'; // For 0-9
        } else {
            hex[index++] = (remainder - 10) + 'A'; // For A-F
        }

        decimal /= 16;
    }

    // Reverse the hex array to get the correct representation
    for (int i = index - 1; i >= 0; i--) {
        putchar(hex[i]);
    }
}

void hexadecimalToDecimal(char hex[]) {
    int length = strlen(hex);
    int base = 1;    // Initial base value is 1 (16^0)
    int decimal = 0; // Initialize decimal variable

    // Convert from hex to decimal
    for (int i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 'a' + 10) * base;
        } else {
            printf("Invalid hexadecimal number.\n");
            return;
        }
        base *= 16; // Update base
    }
    printf("%d", decimal);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}