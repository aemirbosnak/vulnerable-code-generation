//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: genious
#include <stdio.h>

void dec_to_hex(int decimal) {
    int remainder, quotient;
    char hex[100];
    int i = 0;
    quotient = decimal;
    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10)
            hex[i] = 48 + remainder;
        else
            hex[i] = 55 + remainder;
        i++;
        quotient = quotient / 16;
    }
    printf("Hexadecimal number is: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
}

void hex_to_dec(char hex[]) {
    int decimal = 0;
    int base = 1;
    int len = strlen(hex);
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
    }
    printf("Decimal number is: %d", decimal);
}

int main() {
    int choice, decimal;
    char hex[100];
    printf("1. Decimal to Hexadecimal Conversion \n");
    printf("2. Hexadecimal to Decimal Conversion \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter decimal number: ");
            scanf("%d", &decimal);
            dec_to_hex(decimal);
            break;
        case 2:
            printf("Enter hexadecimal number: ");
            scanf("%s", hex);
            hex_to_dec(hex);
            break;
        default:
            printf("Invalid choice!");
    }
    return 0;
}