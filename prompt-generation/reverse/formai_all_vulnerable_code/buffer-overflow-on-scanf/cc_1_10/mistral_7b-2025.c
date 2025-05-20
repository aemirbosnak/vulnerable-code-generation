//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEX_DIGITS 32

void convert_hex_to_decimal(char hex[MAX_HEX_DIGITS], int *decimal) {
    int hex_value, i, power;

    *decimal = 0;

    for (i = strlen(hex) - 1; i >= 0; i--) {
        if (isdigit(hex[i])) {
            hex_value = hex[i] - '0';
        } else if (isalpha(hex[i])) {
            hex_value = hex[i] >= 'A' ? hex[i] - 'A' + 10 : hex[i] - 'a' + 10;
        } else {
            fprintf(stderr, "Invalid Hexadecimal character: %c\n", hex[i]);
            return;
        }

        *decimal += hex_value * (16 * pow(16, (strlen(hex) - 1 - i)));
    }
}

void print_hex_number(int decimal) {
    int i;
    char hex[MAX_HEX_DIGITS];

    sprintf(hex, "%X", decimal);

    for (i = strlen(hex) - 1; i >= 0; i--) {
        if (strlen(hex) % 2 == 1 && i != strlen(hex) - 1) {
            printf("0");
        }
        printf("%c", hex[i]);
    }

    printf("\n");
}

int main() {
    char hex_input[MAX_HEX_DIGITS];
    int decimal;

    printf("Sherlock's Magnificent Hexadecimal Converter\n");
    printf("--------------------------------------------\n");
    printf("Enter a Hexadecimal number: ");
    scanf("%s", hex_input);

    convert_hex_to_decimal(hex_input, &decimal);

    printf("The decimal equivalent of the given Hexadecimal number is:\n");
    print_hex_number(decimal);

    return 0;
}