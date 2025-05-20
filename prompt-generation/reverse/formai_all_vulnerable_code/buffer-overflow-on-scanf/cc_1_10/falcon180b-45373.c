//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER_LENGTH 32

typedef struct {
    int decimal;
    char binary[MAX_NUMBER_LENGTH + 1];
} Number;

void convert_decimal_to_binary(int decimal, char binary[MAX_NUMBER_LENGTH + 1]) {
    int remainder, i;
    char *binary_pointer = &binary[MAX_NUMBER_LENGTH];

    for (i = 0; i < MAX_NUMBER_LENGTH; i++) {
        remainder = decimal % 2;
        decimal /= 2;
        *binary_pointer = '0' + remainder;
        binary_pointer--;
    }

    *binary_pointer = '\0';
}

void convert_binary_to_decimal(char binary[MAX_NUMBER_LENGTH + 1], int decimal[MAX_NUMBER_LENGTH]) {
    int i, j, binary_digit;
    char *binary_pointer = &binary[MAX_NUMBER_LENGTH];

    for (i = 0, j = 0; i < MAX_NUMBER_LENGTH; i++, j++) {
        binary_digit = *binary_pointer - '0';
        decimal[j] = binary_digit;
        binary_pointer--;
    }
}

int main() {
    int decimal, binary_decimal[MAX_NUMBER_LENGTH];
    char binary[MAX_NUMBER_LENGTH + 1];
    Number number;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    convert_decimal_to_binary(decimal, number.binary);
    strcpy(binary, number.binary);

    printf("Binary representation: %s\n", binary);

    convert_binary_to_decimal(binary, binary_decimal);

    printf("Decimal representation: %d\n", binary_decimal[0]);

    return 0;
}