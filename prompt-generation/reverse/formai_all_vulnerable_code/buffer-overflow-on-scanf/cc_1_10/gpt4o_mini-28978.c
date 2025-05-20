//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

void print_menu() {
    printf("Hexadecimal Converter\n");
    printf("=====================\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void decimal_to_hexadecimal() {
    int decimal;
    char hex[10];

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    sprintf(hex, "%X", decimal);
    printf("Hexadecimal: %s\n\n", hex);
}

void hexadecimal_to_decimal() {
    char hex[MAX_INPUT_SIZE];
    int decimal;

    printf("Enter a hexadecimal number (without 0x prefix): ");
    scanf("%s", hex);

    decimal = (int)strtol(hex, NULL, 16);
    printf("Decimal: %d\n\n", decimal);
}

void clear_buffer() {
    while (getchar() != '\n');
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                decimal_to_hexadecimal();
                break;
            case 2:
                hexadecimal_to_decimal();
                break;
            case 3:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n\n");
                break;
        }
    }

    return 0;
}