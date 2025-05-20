//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

void convert_to_binary(int num, char *binary) {
    if (num < 0) {
        fprintf(stderr, "Negative numbers not supported in this simple converter. Please use positive integers.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = MAX_BITS - 1; i >= 0; i--) {
        binary[i] = (num % 2) ? '1' : '0';
        num /= 2;
    }
    binary[MAX_BITS] = '\0';
}

void print_binary(char *binary) {
    int leading_zero = 1;  // Flag to skip leading zeros
    for (int i = 0; i < MAX_BITS; i++) {
        if (binary[i] == '1') {
            leading_zero = 0;  // Encountered a set bit
        }
        if (!leading_zero) {
            putchar(binary[i]);
        }
    }
    if (leading_zero) {
        putchar('0');  // for zero input
    }
    putchar('\n');
}

void print_help() {
    printf("Usage: binary_converter <positive_integer>\n");
    printf("Convert a positive integer to its binary representation.\n");
    printf("Example: ./binary_converter 10 --> 1010\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_help();
        return EXIT_FAILURE;
    }

    char *endptr;
    long num = strtol(argv[1], &endptr, 10);

    if (*endptr != '\0' || num < 0 || num > (1 << MAX_BITS) - 1) {
        fprintf(stderr, "Error: Please enter a valid positive integer within the range of 0 to %d.\n", (1 << MAX_BITS) - 1);
        return EXIT_FAILURE;
    }

    char binary[MAX_BITS + 1]; // +1 for null-terminator
    convert_to_binary((int)num, binary);
    printf("Binary representation of %ld is: ", num);
    print_binary(binary);

    return EXIT_SUCCESS;
}