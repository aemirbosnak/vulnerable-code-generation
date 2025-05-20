//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BASE_16 16
#define BASE_10 10

void print_hex(unsigned long long num) {
    char hex[64];
    int i = 0;

    hex[i++] = '0';
    hex[i++] = 'x';

    while (num > 0) {
        num >>= 4;
        unsigned int digit = num & 0xF;

        if (digit < 10) {
            hex[i++] = digit + '0';
        } else {
            hex[i++] = digit + 'A' - 10;
        }

        num >>= 4;
    }

    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }

    putchar('\n');
}

unsigned long long decimal_to_hexadecimal(unsigned long long decimal) {
    return (decimal >> 0) | ((decimal >> 4) << 4);
}

int main() {
    unsigned long long decimal_number;

    printf("Enter a decimal number: ");
    if (scanf("%llu", &decimal_number) != 1) {
        perror("Invalid input");
        exit(EXIT_FAILURE);
    }

    printf("The hexadecimal representation of %llu is:", decimal_number);
    print_hex(decimal_number);

    return EXIT_SUCCESS;
}