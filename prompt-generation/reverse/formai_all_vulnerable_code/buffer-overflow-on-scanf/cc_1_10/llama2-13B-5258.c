//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BINARY_SIZE 32

void binary_to_decimal(uint8_t binary[BINARY_SIZE], int *decimal) {
    int i, sum = 0;

    for (i = 0; i < BINARY_SIZE; i++) {
        sum += (binary[i] - '0') * pow(2, BINARY_SIZE - i - 1);
    }

    *decimal = sum;
}

void decimal_to_binary(int decimal, uint8_t binary[BINARY_SIZE]) {
    int i, remainder = decimal;

    for (i = 0; i < BINARY_SIZE; i++) {
        binary[i] = remainder % 2 ? '1' : '0';
        remainder /= 2;
    }
}

int main() {
    uint8_t binary[BINARY_SIZE] = {0};
    int decimal = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    binary_to_decimal(binary, &decimal);

    printf("Binary representation of %d: ", decimal);
    for (int i = 0; i < BINARY_SIZE; i++) {
        printf("%c", binary[i]);
    }

    printf("\n");

    decimal = 0;
    binary[0] = 1;
    for (int i = 1; i < BINARY_SIZE; i++) {
        binary[i] = 0;
    }

    printf("Binary reverse of %d: ", decimal);
    for (int i = BINARY_SIZE - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }

    printf("\n");

    return 0;
}