//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

void decimalToHexadecimal(int decimal, char* hex) {
    if (decimal == 0) {
        strcpy(hex, "0");
        return;
    }

    int index = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[index++] = remainder + '0';
        } else {
            hex[index++] = (remainder - 10) + 'A';
        }
        decimal /= 16;
    }
    hex[index] = '\0';

    // Reverse the hex string
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }
}

void hexadecimalToDecimal(const char* hex, int* decimal) {
    *decimal = 0;
    int base = 1; // 16^0

    int len = strlen(hex);
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            *decimal += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            *decimal += (hex[i] - 'A' + 10) * base;
        }
        base *= 16;
    }
}

void displayMenu() {
    printf("\n==== Hexadecimal Converter ====\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("==============================\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int decimal;
                char hex[MAX_SIZE];
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToHexadecimal(decimal, hex);
                printf("Hexadecimal: %s\n", hex);
                break;
            }
            case 2: {
                char hex[MAX_SIZE];
                int decimal;
                printf("Enter a hexadecimal number: ");
                scanf("%s", hex);
                hexadecimalToDecimal(hex, &decimal);
                printf("Decimal: %d\n", decimal);
                break;
            }
            case 3:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    } while (choice != 3);

    return 0;
}