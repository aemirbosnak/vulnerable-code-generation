//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_OUTPUT_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s [binary number]\n", argv[0]);
        return 1;
    }

    char *binary_str = argv[1];
    int input_len = strlen(binary_str);

    if (input_len > MAX_INPUT_LENGTH) {
        printf("Error: Input too long.\n");
        return 1;
    }

    char *output_str = malloc(MAX_OUTPUT_LENGTH * sizeof(char));
    if (output_str == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    int output_len = 0;
    int carry = 0;

    for (int i = input_len - 1; i >= 0; i--) {
        if (binary_str[i] == '1') {
            carry += 1;
        } else {
            carry += 0;
        }

        if (carry == 10) {
            carry = 0;
            output_str[output_len++] = '1';
        } else {
            carry += 1;
        }
    }

    if (carry == 10) {
        output_str[output_len++] = '1';
    }

    printf("Decimal equivalent: %s\n", output_str);

    free(output_str);
    return 0;
}