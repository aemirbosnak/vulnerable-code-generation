//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void printMenu();
void decimalToHexadecimal();
void hexadecimalToDecimal();
void clearBuffer();

int main() {
    int choice;
    
    while (1) {
        printMenu();
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                decimalToHexadecimal();
                break;
            case 2:
                hexadecimalToDecimal();
                break;
            case 3:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void printMenu() {
    printf("\n=== Hexadecimal Converter ===\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Please enter your choice: ");
}

void decimalToHexadecimal() {
    long decimal;
    char hexadecimal[20];

    printf("Enter a decimal number: ");
    if (scanf("%ld", &decimal) != 1) {
        clearBuffer();
        printf("Invalid input! Please enter a valid decimal number.\n");
        return;
    }

    sprintf(hexadecimal, "%lX", decimal); // Convert to hexadecimal
    printf("Decimal: %ld => Hexadecimal: %s\n", decimal, hexadecimal);
}

void hexadecimalToDecimal() {
    char hexadecimal[20];
    long decimal;

    printf("Enter a hexadecimal number: ");
    scanf("%19s", hexadecimal); // Limiting input to prevent buffer overflow

    // Validate the hexadecimal input
    for (int i = 0; i < strlen(hexadecimal); i++) {
        if (!isxdigit(hexadecimal[i])) {
            printf("Invalid input! Please enter a valid hexadecimal number.\n");
            return;
        }
    }

    decimal = strtol(hexadecimal, NULL, 16); // Convert to decimal
    printf("Hexadecimal: %s => Decimal: %ld\n", hexadecimal, decimal);
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}