//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 32

char hex_table[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void convert_hex_to_decimal(char *hex_str, int *decimal) {
    int len = strlen(hex_str);
    int i, j, value;

    *decimal = 0;

    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        value = hex_table[hex_str[i] - '0'] * 16;
        if (hex_str[i] >= 'A' && hex_str[i] <= 'F')
            value += hex_table[hex_str[i] - 'A'] * 1;
        *decimal += value;
    }
}

void print_decimal_as_hex(int decimal, char *hex_str) {
    int i, j;

    *hex_str = '\0';

    for (i = 0; decimal > 0; i++) {
        j = decimal % 16;
        hex_str[i] = hex_table[j];
        decimal /= 16;
    }

    for (i = i - 1; i >= 0; i--)
        putchar(hex_str[i]);
    putchar('\n');
}

int main() {
    char input_hex[SIZE];
    int decimal;

    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
        '1', '0', '1', '1', '0', '0', '1', '1', '0', '1', '1', '0', '1', '1', '0', '1', '1', '0', '1', '1', '0', '1', '1', '0', '1', '1', '0', '1', '1', '0', '1', '1');
    printf("Welcome to the Hexadecimal Converter v3000.\n");
    printf("In this desolate wasteland, we can still decipher the remnants of technology.\n");
    printf("Enter a hexadecimal number: ");
    scanf("%s", input_hex);

    convert_hex_to_decimal(input_hex, &decimal);
    print_decimal_as_hex(decimal, input_hex);
    printf("The decimal equivalent of '%s' is: %d\n", input_hex, decimal);

    return 0;
}