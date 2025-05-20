//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint16_t base;
    uint16_t value;
} HexPair;

void decode_hex(const char* hex, uint8_t* out, size_t size) {
    size_t i;
    for (i = 0; i < size && *hex; ++i) {
        if (isxdigit(*hex) || (*hex == ':' && isxdigit(hex[1]))) {
            HexPair pair;
            pair.base = (*hex++) >= 'A' ? 16 : 15;
            pair.base *= 16;
            pair.value = isdigit(*hex++) ? *hex - '0' : tolower(*hex++) - 'a' + 10;
            *out++ = (pair.value >> 4) | (*(out - 1) & 0xF0);
            *out++ = pair.value << 4;
        } else {
            fprintf(stderr, "Invalid hexadecimal digit: %c\n", *hex);
            exit(EXIT_FAILURE);
        }
    }
    if (i < size) {
        fprintf(stderr, "Input too long\n");
        exit(EXIT_FAILURE);
    }
}

void print_hex(const uint8_t* in, size_t size) {
    static const char* digits = "0123456789ABCDEF";
    size_t i;
    for (i = 0; i < size; ++i) {
        putchar(digits[(in[i] >> 4) & 0xF]);
        putchar(digits[in[i] & 0xF]);
    }
}

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    const size_t input_size = 16;
    uint8_t input[input_size];
    const size_t output_size = input_size * 2 + 1;
    uint8_t output[output_size];

    if (scanf("0x%16s", (char*)input) != 1) {
        fprintf(stderr, "Error: Invalid hexadecimal input\n");
        return EXIT_FAILURE;
    }

    decode_hex(input, output, input_size);

    printf("Input:   ");
    print_hex(input, input_size);
    putchar('\n');

    printf("Output:  ");
    print_hex(output, output_size);
    putchar('\n');

    return EXIT_SUCCESS;
}