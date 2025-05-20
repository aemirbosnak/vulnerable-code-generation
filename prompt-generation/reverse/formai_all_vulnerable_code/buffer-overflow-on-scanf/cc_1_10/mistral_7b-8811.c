//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 33

void print_menu() {
    printf("\n*** HEX TO DECIMAL CONVERTER ***\n");
    printf("1. Convert Hex to Decimal\n");
    printf("2. Convert Decimal to Hex\n");
    printf("3. Quit\n");
}

int hex_to_decimal(char hex[]) {
    int decimal = 0;
    int power = 0;

    for (int i = strlen(hex) - 1; i >= 0; i--) {
        if (isdigit(hex[i])) {
            decimal += (hex[i] - '0') * pow(16, power);
            power++;
        } else if (isalpha(hex[i])) {
            decimal += (hex[i] - 'A' + 10) * pow(16, power);
            power++;
        }
    }

    return decimal;
}

void decimal_to_hex(int decimal) {
    char hex[32];
    int index = 0;
    int divisor = 16;

    while (decimal > 0) {
        int digit = decimal % divisor;

        if (digit < 10) {
            hex[index++] = digit + '0';
        } else {
            hex[index++] = digit + 'A' - 10;
        }

        decimal /= divisor;
    }

    hex[index] = '\0';

    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }

    printf("\n");
}

int main() {
    char input[MAX_INPUT_SIZE];
    int choice, decimal;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Hex number: ");
                scanf("%s", input);
                decimal = hex_to_decimal(input);
                printf("Decimal equivalent: %d\n", decimal);
                break;
            case 2:
                printf("Enter Decimal number: ");
                scanf("%d", &decimal);
                printf("Hexadecimal equivalent: ");
                decimal_to_hex(decimal);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}