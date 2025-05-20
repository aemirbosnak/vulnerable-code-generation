//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BINARY_LENGTH 32
#define NUM_DIGITS 10
#define MIN_BINARY 0b0000000000000000000000000001
#define MAX_BINARY 0b1111111111111111111111111110

void print_binary(unsigned int num) {
    unsigned int binary[BINARY_LENGTH / NUM_DIGITS + 1];
    int i = 0;

    memset(binary, 0, sizeof binary);

    for (; num > 0; num >>= 1) {
        binary[i / NUM_DIGITS] |= (num % 2) << (i % NUM_DIGITS);
        i++;
    }

    for (i = BINARY_LENGTH; i-- > 0;) {
        putchar(binary[i / NUM_DIGITS] >>(i % NUM_DIGITS) & 1 ? '1' : '0');
    }
    putchar('\n');
}

void convert_number(unsigned int decimal) {
    printf("From decimal to binary:\n");
    print_binary(decimal);

    unsigned int binary_num = decimal;
    unsigned int binary[BINARY_LENGTH / NUM_DIGITS + 1];
    int i = 0;

    memset(binary, 0, sizeof binary);

    while (binary_num > 0) {
        binary[i / NUM_DIGITS] |= binary_num % 2 << (i % NUM_DIGITS);
        binary_num /= 2;
        i++;
    }

    int j;
    for (i = 0; i < BINARY_LENGTH / NUM_DIGITS; i++) {
        for (j = i * NUM_DIGITS; j < (i + 1) * NUM_DIGITS; j++) {
            putchar(binary[i / NUM_DIGITS] >>(j % NUM_DIGITS) & 1 + '0' - '0');
        }
        putchar(' ');
    }

    printf("\nFrom binary to decimal:\n");
    unsigned int decimal_num = 0;
    for (i = 0; i < BINARY_LENGTH / NUM_DIGITS; i++) {
        int power = BINARY_LENGTH - (i + 1) * NUM_DIGITS;
        decimal_num += (binary[i / NUM_DIGITS] >> (i % NUM_DIGITS)) & 1 ? pow(2, power) : 0;
    }

    print_binary(decimal_num);
}

int main() {
    unsigned int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    convert_number(num);

    return 0;
}