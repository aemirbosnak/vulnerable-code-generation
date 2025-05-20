//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char *binary;
    char *decimal;
    char *hexadecimal;
} ConversionResult;

void convert_binary_to_decimal(char *binary, int length, int *decimal) {
    int i = 0, j = 0, power = 0;
    while (i < length) {
        if (binary[i] == '1') {
            *decimal += pow(2, power);
        }
        power++;
        i++;
    }
}

void convert_binary_to_hexadecimal(char *binary, int length, char *hexadecimal) {
    int i = 0, j = 0;
    while (i < length) {
        sprintf(&hexadecimal[j], "%02x", (int)binary[i]);
        j += 2;
        i++;
    }
}

ConversionResult *convert_binary(char *binary, int length) {
    ConversionResult *result = malloc(sizeof(ConversionResult));
    result->binary = strdup(binary);
    result->decimal = malloc(MAX_LINE_SIZE);
    result->hexadecimal = malloc(MAX_LINE_SIZE);

    int decimal = 0;
    convert_binary_to_decimal(binary, length, &decimal);
    sprintf(result->decimal, "%d", decimal);

    char hexadecimal[MAX_LINE_SIZE];
    convert_binary_to_hexadecimal(binary, length, hexadecimal);
    strcpy(result->hexadecimal, hexadecimal);

    return result;
}

void print_conversion_result(ConversionResult *result) {
    printf("Binary: %s\n", result->binary);
    printf("Decimal: %s\n", result->decimal);
    printf("Hexadecimal: %s\n", result->hexadecimal);
}

void main() {
    char binary[MAX_LINE_SIZE];
    printf("Enter a binary number: ");
    scanf("%s", binary);

    int length = strlen(binary);
    if (length == 0) {
        printf("Invalid input.\n");
        return;
    }

    ConversionResult *result = convert_binary(binary, length);
    print_conversion_result(result);

    free(result->binary);
    free(result->decimal);
    free(result->hexadecimal);
    free(result);
}