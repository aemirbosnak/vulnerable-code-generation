//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEX 512

void convert_hex_to_decimal(char hex[]) {
    int decimal = 0;
    int len = strlen(hex);
    int power = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(hex[i])) {
            decimal += (hex[i] - '0') * pow(16, power);
        } else if (isalpha(hex[i])) {
            decimal += (hex[i] >='A' && hex[i] <= 'F') ? (hex[i] - 'A' + 10) * pow(16, power) : (hex[i] - 'a' + 10) * pow(16, power);
        }
        power++;
    }

    printf("Decimal value of the hexadecimal number is %d\n", decimal);
}

void convert_decimal_to_hex(int decimal) {
    char hex[MAX_HEX];
    int i = 0, quotient;

    while (decimal > 0) {
        quotient = decimal / 16;
        decimal = decimal % 16;

        if (quotient > 9) {
            hex[i++] = quotient + 55;
        } else {
            hex[i++] = quotient + '0';
        }

        decimal = quotient;
    }

    hex[i] = '\0';

    printf("Hexadecimal value of the decimal number is %s\n", hex);
}

int main(void) {
    char hex_input[MAX_HEX];
    int decimal_input;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_input);

    convert_hex_to_decimal(hex_input);

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_input);

    convert_decimal_to_hex(decimal_input);

    return 0;
}