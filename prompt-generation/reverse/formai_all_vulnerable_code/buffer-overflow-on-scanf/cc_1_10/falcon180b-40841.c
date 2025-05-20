//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_DIGITS 32
#define MAX_DECIMAL_DIGITS 10

typedef struct {
    int decimal_digits;
    char binary_digits[MAX_BINARY_DIGITS];
} BinaryConverter;

void initialize_binary_converter(BinaryConverter* converter) {
    converter->decimal_digits = 0;
    converter->binary_digits[0] = '\0';
}

void add_binary_digit(BinaryConverter* converter, char digit) {
    int i = 0;
    while (i < converter->decimal_digits && converter->binary_digits[i]!= '\0') {
        i++;
    }
    converter->binary_digits[i] = digit;
    converter->decimal_digits++;
}

int is_binary_converter_full(BinaryConverter* converter) {
    return converter->decimal_digits >= MAX_DECIMAL_DIGITS;
}

void print_binary_converter(BinaryConverter* converter) {
    printf("Binary: ");
    for (int i = converter->decimal_digits - 1; i >= 0; i--) {
        printf("%c", converter->binary_digits[i]);
    }
    printf("\n");
}

int main() {
    BinaryConverter converter;
    initialize_binary_converter(&converter);

    int decimal_number;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);

    while (decimal_number!= 0) {
        int remainder = decimal_number % 2;
        add_binary_digit(&converter, remainder + '0');
        decimal_number /= 2;
    }

    print_binary_converter(&converter);

    return 0;
}