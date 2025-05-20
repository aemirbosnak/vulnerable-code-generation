//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char *binary;
    char *decimal;
    char *hexadecimal;
} Conversion;

void initialize_conversion(Conversion *conversion) {
    conversion->binary = malloc(33 * sizeof(char));
    conversion->decimal = malloc(12 * sizeof(char));
    conversion->hexadecimal = malloc(9 * sizeof(char));
}

void free_conversion(Conversion *conversion) {
    free(conversion->binary);
    free(conversion->decimal);
    free(conversion->hexadecimal);
}

void convert_binary_to_decimal(char *binary, char *decimal) {
    int i = 0, j = 0, decimal_value = 0;
    while (binary[i]!= '\0') {
        if (binary[i] == '1') {
            decimal_value += pow(2, strlen(binary) - i - 1);
        }
        i++;
    }
    sprintf(decimal, "%d", decimal_value);
}

void convert_binary_to_hexadecimal(char *binary, char *hexadecimal) {
    int i = 0, j = 0;
    while (binary[i]!= '\0') {
        sprintf(&hexadecimal[j], "%02x", binary[i]);
        i++;
        j += 2;
    }
    hexadecimal[j] = '\0';
}

int main() {
    Conversion conversion;
    initialize_conversion(&conversion);

    char binary_input[33];
    printf("Enter a binary number: ");
    scanf("%s", binary_input);

    convert_binary_to_decimal(binary_input, conversion.decimal);
    convert_binary_to_hexadecimal(binary_input, conversion.hexadecimal);

    printf("Decimal: %s\n", conversion.decimal);
    printf("Hexadecimal: %s\n", conversion.hexadecimal);

    free_conversion(&conversion);
    return 0;
}