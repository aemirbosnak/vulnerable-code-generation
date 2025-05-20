//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 100
#define MAX_OUTPUT_SIZE 200

typedef struct {
    char* input;
    int input_size;
    char* output;
    int output_size;
} HexConverter;

void init_hex_converter(HexConverter* converter) {
    converter->input = NULL;
    converter->input_size = 0;
    converter->output = NULL;
    converter->output_size = 0;
}

void free_hex_converter(HexConverter* converter) {
    if (converter->input!= NULL) {
        free(converter->input);
        converter->input = NULL;
    }
    if (converter->output!= NULL) {
        free(converter->output);
        converter->output = NULL;
    }
    converter->input_size = 0;
    converter->output_size = 0;
}

void read_input(HexConverter* converter) {
    char input[MAX_INPUT_SIZE];
    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';
    converter->input = strdup(input);
    converter->input_size = strlen(input);
}

void convert_to_hex(HexConverter* converter) {
    char* output = malloc(MAX_OUTPUT_SIZE * sizeof(char));
    int output_size = 0;
    for (int i = 0; i < converter->input_size; i++) {
        char c = tolower(converter->input[i]);
        if (isdigit(c)) {
            output[output_size++] = c;
        } else if (c >= 'a' && c <= 'f') {
            output[output_size++] = c;
        } else {
            printf("Invalid character: %c\n", c);
            free_hex_converter(converter);
            exit(1);
        }
    }
    converter->output = output;
    converter->output_size = output_size;
}

void print_output(HexConverter* converter) {
    if (converter->output == NULL) {
        printf("No output to print.\n");
        return;
    }
    printf("Hexadecimal representation: %s\n", converter->output);
}

int main() {
    HexConverter converter;
    init_hex_converter(&converter);
    read_input(&converter);
    convert_to_hex(&converter);
    print_output(&converter);
    free_hex_converter(&converter);
    return 0;
}