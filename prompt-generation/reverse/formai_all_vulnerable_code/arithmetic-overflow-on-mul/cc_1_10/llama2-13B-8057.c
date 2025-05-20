//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BINARY_CHARS  '0' '1'
#define BINARY_MAX_LEN 32

void binary_to_decimal(char *binary, int *decimal);
void decimal_to_binary(int decimal, char *binary);

int main() {
    char binary[BINARY_MAX_LEN];
    int decimal;

    printf("Enter a binary number: ");
    fgets(binary, BINARY_MAX_LEN, stdin);

    binary_to_decimal(binary, &decimal);
    printf("The decimal equivalent of %s is %d\n", binary, decimal);

    decimal_to_binary(decimal, binary);
    printf("The binary equivalent of %d is %s\n", decimal, binary);

    return 0;
}

void binary_to_decimal(char *binary, int *decimal) {
    int i = 0;
    *decimal = 0;

    while (binary[i] != '\0') {
        int digit = binary[i] - '0';
        *decimal *= 2;
        *decimal += digit;
        i++;
    }
}

void decimal_to_binary(int decimal, char *binary) {
    int i = 0;

    while (decimal != 0) {
        binary[i] = decimal % 2 == 0 ? '0' : '1';
        decimal /= 2;
        i++;
    }

    binary[i] = '\0';
}