//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 512
#define MAX_CONVERTED_LENGTH 32

typedef struct {
    char input[MAX_LINE_LENGTH];
    char converted[MAX_CONVERTED_LENGTH];
} binary_converter_t;

binary_converter_t* create_converter() {
    binary_converter_t* converter = malloc(sizeof(binary_converter_t));
    converter->input[0] = '\0';
    converter->converted[0] = '\0';
    return converter;
}

void destroy_converter(binary_converter_t* converter) {
    free(converter);
}

int is_binary(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (str[i]!= '0' && str[i]!= '1') {
            return 0;
        }
        i++;
    }
    return 1;
}

void convert_binary(binary_converter_t* converter) {
    int i = 0;
    while (converter->input[i]!= '\0') {
        if (converter->input[i] == '0') {
            strcat(converter->converted, "0000");
        } else if (converter->input[i] == '1') {
            strcat(converter->converted, "1111");
        } else {
            strcat(converter->converted, "0000");
        }
        i++;
    }
}

int main() {
    binary_converter_t* converter = create_converter();
    char input[MAX_LINE_LENGTH];
    fgets(input, MAX_LINE_LENGTH, stdin);
    strcpy(converter->input, input);
    if (is_binary(converter->input)) {
        convert_binary(converter);
        printf("Binary: %s\n", converter->converted);
    } else {
        printf("Invalid input\n");
    }
    destroy_converter(converter);
    return 0;
}