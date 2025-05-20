//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_NUMBER_OF_BASES 16

typedef struct {
    char base[32];
    long long value;
} conversion_t;

void convert(const char *input, size_t len, const char *base_str, conversion_t *output) {
    size_t i, j;
    long long value = 0;
    char *end;

    for (i = 0; i < len; i++) {
        char c = input[i];

        if (c >= '0' && c <= '9') {
            value *= 10;
            value += (c - '0');
        } else if (c == '.' && i < len - 1) {
            // Allow decimals
            value *= 10;
            continue;
        } else {
            break;
        }
    }

    // Check if the input is a valid number
    if (i == len) {
        output->value = value;
        return;
    }

    // Convert the input to the specified base
    for (j = 0; j < MAX_NUMBER_OF_BASES; j++) {
        if (base_str[j] == '\0') {
            break;
        }

        if (base_str[j] == 'x' || base_str[j] == 'X') {
            base_str += j;
            break;
        }
    }

    // Calculate the power of the base
    long long power = 1;
    for (j = 0; j < MAX_INPUT_LENGTH; j++) {
        power *= base_str[j] - '0';
    }

    // Convert the input to the specified base
    for (j = 0; j < len; j++) {
        char c = input[j];

        if (c >= '0' && c <= '9') {
            value += (c - '0') * power;
        } else if (c == '.' && j < len - 1) {
            // Allow decimals
            value += (c - '.') * power;
        } else {
            break;
        }

        power *= base_str[j] - '0';
    }

    output->value = value;
}

int main() {
    conversion_t input;
    conversion_t output;

    // Convert a binary string to decimal
    char bin_str[] = "1101011010";
    convert(bin_str, sizeof(bin_str) - 1, "dec", &output);
    printf("Decimal: %lld\n", output.value);

    // Convert a hexadecimal string to binary
    char hex_str[] = "AF34";
    convert(hex_str, sizeof(hex_str) - 1, "hex", &output);
    printf("Binary: %s\n", output.base);

    return 0;
}