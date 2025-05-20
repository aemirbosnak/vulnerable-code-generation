//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

#define BINARY_DIGITS 64
#define BINARY_STR_SIZE (BINARY_DIGITS * 2 + 1)

typedef struct {
    uint64_t value;
    char binary[BINARY_STR_SIZE];
} binary_t;

void binary_to_string(binary_t *binary, char *str) {
    int i;
    for (i = 0; i < BINARY_DIGITS; i++) {
        str[i * 2] = (binary->value & (1ULL << i)) ? '1' : '0';
        str[i * 2 + 1] = '0' + (binary->value >> (64 - i));
    }
    str[BINARY_STR_SIZE - 1] = '\0';
}

int main() {
    binary_t binary;
    char str[BINARY_STR_SIZE];

    printf("Enter a binary number: ");
    scanf("%" SCNu64, &binary.value);
    binary_to_string(&binary, str);
    printf("Binary: %s\n", str);

    printf("Enter a decimal number: ");
    int dec = scanf("%d", &dec);
    if (dec == 0) {
        printf("Invalid input\n");
        return 1;
    }

    binary.value = 0;
    for (int i = 0; i < BINARY_DIGITS; i++) {
        binary.value <<= 1;
        if (str[i * 2] == '1') {
            binary.value |= 1ULL << (64 - i - 1);
        }
    }

    printf("Decimal: %d\n", dec);
    printf("Binary: %s\n", str);

    return 0;
}