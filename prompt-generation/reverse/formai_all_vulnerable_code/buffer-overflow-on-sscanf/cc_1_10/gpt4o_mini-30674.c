//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 20

void printMenu() {
    printf("\nHexadecimal Converter\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void decimalToHexadecimal(int decimal) {
    char hex[BUFFER_SIZE];
    sprintf(hex, "%X", decimal);
    printf("Decimal %d in hexadecimal: %s\n", decimal, hex);
}

void hexadecimalToDecimal(const char *hex) {
    int decimal;
    sscanf(hex, "%X", &decimal);
    printf("Hexadecimal %s in decimal: %d\n", hex, decimal);
}

void flushInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    int choice;
    char hexInput[BUFFER_SIZE];
    int decimalInput;
    int continueConversion = 1;

    while (continueConversion) {
        printMenu();
        scanf("%d", &choice);
        flushInputBuffer(); // Clear the input buffer

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalInput);
                flushInputBuffer();
                decimalToHexadecimal(decimalInput);
                break;
            case 2:
                printf("Enter a hexadecimal number: ");
                fgets(hexInput, sizeof(hexInput), stdin);
                hexInput[strcspn(hexInput, "\n")] = 0; // Remove newline character
                hexadecimalToDecimal(hexInput);
                break;
            case 3:
                continueConversion = 0;
                printf("Exiting the converter. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    }

    return 0;
}