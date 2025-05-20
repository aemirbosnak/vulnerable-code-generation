//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void hex_to_decimal(char hex[]) {
    int decimal = 0;
    int power = 0;

    for (int i = strlen(hex) - 1; i >= 0; i--) {
        if (isxdigit(hex[i])) {
            int digit = hex[i] >= 'A' ? hex[i] - 'A' + 10 : hex[i] - '0';
            decimal += digit * pow(16, power++);
        }
    }

    printf("Decimal: %d\n", decimal);
}

void hex_to_binary(char hex[]) {
    int decimal;
    hex_to_decimal(hex);

    printf("Binary: ");
    for (int i = 0; decimal > 0; i++) {
        printf("%d", decimal % 2);
        decimal /= 2;
    }
    printf("\n");
}

void hex_to_octal(char hex[]) {
    int decimal;
    hex_to_decimal(hex);

    printf("Octal: ");
    while (decimal > 0) {
        int digit = decimal % 8;
        printf("%d", digit);
        decimal /= 8;
    }
    printf("\n");
}

int main() {
    char hex[11];

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    printf("Choose an output format:\n");
    printf("1. Decimal\n");
    printf("2. Binary\n");
    printf("3. Octal\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            hex_to_decimal(hex);
            break;
        case 2:
            hex_to_binary(hex);
            break;
        case 3:
            hex_to_octal(hex);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}