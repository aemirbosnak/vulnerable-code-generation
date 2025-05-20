//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimal) {
    char hex[20];
    int i = 0;

    // Convert decimal to hexadecimal
    while (decimal != 0) {
        int remainder = decimal % 16;

        if (remainder < 10) {
            hex[i++] = remainder + '0';
        } else {
            hex[i++] = remainder - 10 + 'A';
        }

        decimal /= 16;
    }

    // Print the hexadecimal number
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    printf("\n");
}

void hexadecimalToDecimal(const char *hex) {
    int decimal = 0;
    int base = 1;
    int length = 0;

    // Calculate the length of the hexadecimal string
    while (hex[length] != '\0') {
        length++;
    }

    // Convert hexadecimal to decimal
    for (int i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base;
        }
        base *= 16;
    }

    // Print the decimal number
    printf("Decimal: %d\n", decimal);
}

int main() {
    int choice, decimal;
    char hex[20];

    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    
    while (1) {
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToHexadecimal(decimal);
                break;

            case 2:
                printf("Enter a hexadecimal number (without 0x prefix): ");
                scanf("%s", hex);
                hexadecimalToDecimal(hex);
                break;

            case 3:
                printf("Thank you for using the Hexadecimal Converter! Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please select again.\n");
        }
        
        printf("\n");
    }

    return 0;
}