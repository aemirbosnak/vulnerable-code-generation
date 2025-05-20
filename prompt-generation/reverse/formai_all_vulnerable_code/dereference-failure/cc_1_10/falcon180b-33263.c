//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000

typedef enum {
    HEX_UPPERCASE,
    HEX_LOWERCASE
} hex_case_t;

typedef struct {
    char *input;
    char *output;
    hex_case_t case_type;
} converter_t;

void init_converter(converter_t *converter) {
    converter->input = malloc(MAX_LINE_LENGTH * sizeof(char));
    converter->output = malloc(MAX_LINE_LENGTH * sizeof(char));
    converter->case_type = HEX_UPPERCASE;
}

void free_converter(converter_t *converter) {
    free(converter->input);
    free(converter->output);
}

void set_case_type(converter_t *converter, hex_case_t case_type) {
    converter->case_type = case_type;
}

void convert_hex(converter_t *converter) {
    char *input_ptr = converter->input;
    char *output_ptr = converter->output;
    while (*input_ptr!= '\0') {
        if (isxdigit(*input_ptr)) {
            char hex_char = *input_ptr;
            if (isupper(hex_char)) {
                if (converter->case_type == HEX_LOWERCASE) {
                    *output_ptr = tolower(hex_char);
                } else {
                    *output_ptr = hex_char;
                }
            } else {
                if (converter->case_type == HEX_UPPERCASE) {
                    *output_ptr = toupper(hex_char);
                } else {
                    *output_ptr = hex_char;
                }
            }
        } else {
            *output_ptr = *input_ptr;
        }
        input_ptr++;
        output_ptr++;
    }
    *output_ptr = '\0';
}

int main() {
    converter_t converter;
    init_converter(&converter);

    printf("Enter hexadecimal string: ");
    fgets(converter.input, MAX_LINE_LENGTH, stdin);

    set_case_type(&converter, HEX_UPPERCASE);
    convert_hex(&converter);

    printf("Hexadecimal string in uppercase: %s\n", converter.output);

    set_case_type(&converter, HEX_LOWERCASE);
    convert_hex(&converter);

    printf("Hexadecimal string in lowercase: %s\n", converter.output);

    free_converter(&converter);

    return 0;
}