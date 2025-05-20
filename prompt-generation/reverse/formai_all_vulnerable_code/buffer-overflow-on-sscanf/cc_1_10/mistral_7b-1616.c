//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024
#define BINARY_SIZE(n) (((n) + 3) / 4 * 4)

void itob(unsigned int n, char *s, int base) {
    static char *digits = "0123456789ABCDEF";
    char output[64];
    int i = 0;

    output[63] = '\0';

    do {
        output[--i] = digits[n % base];
        n /= base;
    } while (n);

    if (base == 16) {
        if (s) {
            strncpy(s, output, sizeof(output));
        }
        for (int j = 0; output[j] != '\0'; j++) {
            if (isupper(output[j])) {
                output[j] += 32;
            }
        }
    }

    if (s) {
        strncpy(s, output, sizeof(output));
    }
}

void reverse_binary(char *binary, int size) {
    char tmp;
    for (int i = 0; i < size / 2; i++) {
        tmp = binary[i];
        binary[i] = binary[size - i - 1];
        binary[size - i - 1] = tmp;
    }
}

int main() {
    char binary[MAX_INPUT_SIZE];
    char decimal[32], hexadecimal[32], reversed_binary[32];
    unsigned int decimal_number;

    printf("Enter binary number: ");
    scanf("%s", binary);

    sscanf(binary, "%x", &decimal_number);

    itob(decimal_number, decimal, 10);
    printf("Decimal: %s\n", decimal);

    itob(decimal_number, hexadecimal, 16);
    printf("Hexadecimal: %s\n", hexadecimal);

    if (strlen(binary) % 2 == 1) {
        reverse_binary(binary, strlen(binary));
    }

    itob(decimal_number, reversed_binary, 2);
    printf("Reversed Binary: %s\n", reversed_binary);

    return 0;
}