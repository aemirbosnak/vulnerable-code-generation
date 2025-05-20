//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUMBER_OF_BITS 32
#define MAX_NUMBER_OF_BYTES 4

typedef struct {
    unsigned int bits[MAX_NUMBER_OF_BYTES];
    unsigned int bytes[MAX_NUMBER_OF_BITS / 8];
} binary_t;

void binary_to_decimal(binary_t *binary) {
    int i, j;
    long long decimal = 0;

    for (i = 0; i < MAX_NUMBER_OF_BYTES; i++) {
        for (j = 0; j < 8; j++) {
            decimal += (binary->bits[i] & (1 << j)) * pow(2, j);
        }
    }

    printf("%lld\n", decimal);
}

void decimal_to_binary(long long decimal) {
    int i, j;
    binary_t binary;

    for (i = 0; i < MAX_NUMBER_OF_BYTES; i++) {
        binary.bits[i] = 0;
    }

    while (decimal != 0) {
        int bit_index = 0;
        while (decimal % 2 == 0) {
            binary.bits[i] |= (1 << bit_index);
            decimal /= 2;
            bit_index++;
        }
        i++;
        decimal -= (1 << bit_index);
    }

    printf("Binary: ");
    for (i = 0; i < MAX_NUMBER_OF_BYTES; i++) {
        for (j = 0; j < 8; j++) {
            if (binary.bits[i] & (1 << j)) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf(" ");
    }
    printf("\n");
}

int main() {
    binary_t binary;
    long long decimal;

    printf("Enter a binary number (e.g. 11010110): ");
    scanf("%lu", &decimal);

    binary_to_decimal(&binary);

    printf("Enter a decimal number (e.g. 56): ");
    scanf("%lld", &decimal);

    decimal_to_binary(decimal);

    return 0;
}