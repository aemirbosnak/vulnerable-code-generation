//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: accurate
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DIGITS 10
#define BINARY_DIGITS 8
#define OCTAL_DIGITS 8
#define HEXADECIMAL_DIGITS 8

int main() {
    int num;
    char binary[BINARY_DIGITS];
    char octal[OCTAL_DIGITS];
    char hexadecimal[HEXADECIMAL_DIGITS];

    printf("Enter a number: ");
    scanf("%d", &num);

    // Convert to binary
    binary[0] = num % 2;
    num /= 2;
    for (int i = 1; i < BINARY_DIGITS; i++) {
        binary[i] = num % 2;
        num /= 2;
    }

    // Convert to octal
    octal[0] = num % 8;
    num /= 8;
    for (int i = 1; i < OCTAL_DIGITS; i++) {
        octal[i] = num % 8;
        num /= 8;
    }

    // Convert to hexadecimal
    hexadecimal[0] = num % 16;
    num /= 16;
    for (int i = 1; i < HEXADECIMAL_DIGITS; i++) {
        hexadecimal[i] = num % 16;
        num /= 16;
    }

    printf("Binary: %s\n", binary);
    printf("Octal: %s\n", octal);
    printf("Hexadecimal: %s\n", hexadecimal);

    return 0;
}