//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char* input;
    char* output;
    int base;
} converter;

converter* create_converter(char* input, int base) {
    converter* result = (converter*)malloc(sizeof(converter));
    result->input = input;
    result->output = (char*)malloc(33*sizeof(char));
    result->base = base;
    return result;
}

void delete_converter(converter* converter) {
    free(converter->input);
    free(converter->output);
    free(converter);
}

void convert(converter* converter) {
    int length = strlen(converter->input);
    int i = 0;
    int j = 0;
    while (i < length) {
        char c = toupper(converter->input[i]);
        if (isdigit(c)) {
            converter->output[j++] = c;
        } else if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f') {
            converter->output[j++] = c;
        } else {
            printf("invalid input\n");
            exit(1);
        }
        i++;
    }
    converter->output[j] = '\0';
}

void display(converter* converter) {
    printf("binary: %s\n", converter->output);
}

int main() {
    char* input;
    int base;
    printf("enter a number: ");
    scanf("%s", input);
    printf("enter the base (2-16): ");
    scanf("%d", &base);
    if (base < 2 || base > 16) {
        printf("invalid base\n");
        exit(1);
    }
    converter* converter = create_converter(input, base);
    convert(converter);
    display(converter);
    delete_converter(converter);
    return 0;
}