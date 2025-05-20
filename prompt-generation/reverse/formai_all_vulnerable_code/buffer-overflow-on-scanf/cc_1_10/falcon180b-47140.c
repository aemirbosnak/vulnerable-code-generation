//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    char* input;
    int length;
    int base;
} BinaryConverter;

void initialize_converter(BinaryConverter* converter, char* input, int base) {
    converter->input = input;
    converter->length = strlen(input);
    converter->base = base;
}

int is_valid_base(int base) {
    if (base < 2 || base > 16) {
        return false;
    }
    return true;
}

void convert_binary(BinaryConverter* converter, char* output) {
    int i = 0;
    while (i < converter->length) {
        char c = tolower(converter->input[i]);
        if (isdigit(c)) {
            int digit = c - '0';
            sprintf(output + (converter->length - 1 - i) * 2, "%02x", digit);
        } else if (isalpha(c)) {
            int index = tolower(c) - 'a';
            if (index >= 0 && index <= 9) {
                sprintf(output + (converter->length - 1 - i) * 2, "%02x", index + 10);
            } else if (index >= 10 && index <= 15) {
                sprintf(output + (converter->length - 1 - i) * 2, "%02x", index - 10 + 'a');
            }
        }
        i++;
    }
}

int main() {
    char input[100];
    char output[200];
    int base;

    printf("Enter the base of the input number: ");
    scanf("%d", &base);

    if (!is_valid_base(base)) {
        printf("Invalid base!\n");
        return 1;
    }

    printf("Enter the input number: ");
    scanf("%s", input);

    BinaryConverter converter;
    initialize_converter(&converter, input, base);

    convert_binary(&converter, output);

    printf("Binary representation: %s\n", output);

    return 0;
}