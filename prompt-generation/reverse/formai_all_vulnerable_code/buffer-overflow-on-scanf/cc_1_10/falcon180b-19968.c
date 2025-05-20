//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NUM_DIGITS 32

typedef struct {
    char* input;
    char* output;
    bool is_valid;
} HexadecimalConverter;

void initialize_converter(HexadecimalConverter* converter) {
    converter->input = calloc(MAX_NUM_DIGITS, sizeof(char));
    converter->output = calloc(MAX_NUM_DIGITS, sizeof(char));
    converter->is_valid = true;
}

void destroy_converter(HexadecimalConverter* converter) {
    free(converter->input);
    free(converter->output);
}

bool is_valid_hexadecimal(char* input) {
    for (int i = 0; i < strlen(input); i++) {
        if (!isxdigit(input[i])) {
            return false;
        }
    }
    return true;
}

void convert_hexadecimal(HexadecimalConverter* converter) {
    char* input_copy = strdup(converter->input);
    char* output = converter->output;
    int num_digits = strlen(input_copy);
    int output_index = 0;

    for (int i = 0; i < num_digits; i++) {
        if (i % 2 == 0) {
            output[output_index++] = input_copy[i];
        }
    }
    output[output_index] = '\0';
}

int main() {
    HexadecimalConverter converter;
    initialize_converter(&converter);

    printf("Enter a hexadecimal number: ");
    scanf("%s", converter.input);

    if (!is_valid_hexadecimal(converter.input)) {
        printf("Invalid hexadecimal number.\n");
        destroy_converter(&converter);
        return 1;
    }

    convert_hexadecimal(&converter);
    printf("Decimal equivalent: %s\n", converter.output);

    destroy_converter(&converter);
    return 0;
}