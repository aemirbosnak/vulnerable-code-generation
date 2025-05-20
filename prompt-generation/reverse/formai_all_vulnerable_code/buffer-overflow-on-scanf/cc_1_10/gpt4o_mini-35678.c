//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void convertToHex(int decimal, char* hex) {
    int index = 0;
    if (decimal == 0) {
        hex[index++] = '0';
    } else {
        while (decimal > 0) {
            int remainder = decimal % 16;
            if (remainder < 10) {
                hex[index++] = '0' + remainder;
            } else {
                hex[index++] = 'A' + (remainder - 10);
            }
            decimal = decimal / 16;
        }
    }
    hex[index] = '\0';

    // Reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }
}

void displayMenu() {
    printf("==================================\n");
    printf("       Decimal to Hex Converter    \n");
    printf("==================================\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
    printf("==================================\n");
}

int main() {
    int choice, decimal;
    char hex[20];

    do {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            // Clear invalid input
            while(getchar() != '\n');
            choice = 0; // Reset choice for re-prompt
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                if (scanf("%d", &decimal) != 1) {
                    fprintf(stderr, "Invalid input. Please enter a valid decimal number.\n");
                    // Clear invalid input
                    while(getchar() != '\n');
                    continue;
                }
                convertToHex(decimal, hex);
                printf("Decimal: %d\n", decimal);
                printf("Hexadecimal: %s\n", hex);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                fprintf(stderr, "Invalid choice. Please select 1 or 2.\n");
        }

    } while (choice != 2);

    return 0;
}