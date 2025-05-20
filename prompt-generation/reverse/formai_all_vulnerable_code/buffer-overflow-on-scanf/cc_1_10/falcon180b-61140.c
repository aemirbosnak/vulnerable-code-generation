//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char *binary;
    char *hexadecimal;
    char *octal;
    char *decimal;
} Converter;

Converter *createConverter() {
    Converter *converter = (Converter *)malloc(sizeof(Converter));
    converter->binary = (char *)malloc(MAX_SIZE * sizeof(char));
    converter->hexadecimal = (char *)malloc(MAX_SIZE * sizeof(char));
    converter->octal = (char *)malloc(MAX_SIZE * sizeof(char));
    converter->decimal = (char *)malloc(MAX_SIZE * sizeof(char));
    return converter;
}

void destroyConverter(Converter *converter) {
    free(converter->binary);
    free(converter->hexadecimal);
    free(converter->octal);
    free(converter->decimal);
    free(converter);
}

void convertToBinary(Converter *converter, char *input) {
    int length = strlen(input);
    int i = 0;
    converter->binary[i] = '\0';
    while (i < length) {
        if (isdigit(input[i])) {
            converter->binary[i] = input[i];
        } else {
            converter->binary[i] = '0';
        }
        i++;
    }
}

void convertToHexadecimal(Converter *converter, char *input) {
    int length = strlen(input);
    int i = 0;
    converter->hexadecimal[i] = '\0';
    while (i < length) {
        if (isdigit(input[i])) {
            converter->hexadecimal[i] = input[i];
        } else {
            converter->hexadecimal[i] = '0';
        }
        i++;
    }
}

void convertToOctal(Converter *converter, char *input) {
    int length = strlen(input);
    int i = 0;
    converter->octal[i] = '\0';
    while (i < length) {
        if (isdigit(input[i])) {
            converter->octal[i] = input[i];
        } else {
            converter->octal[i] = '0';
        }
        i++;
    }
}

void convertToDecimal(Converter *converter, char *input) {
    int length = strlen(input);
    int i = 0;
    converter->decimal[i] = '\0';
    while (i < length) {
        if (isdigit(input[i])) {
            converter->decimal[i] = input[i];
        } else {
            converter->decimal[i] = '0';
        }
        i++;
    }
}

int main() {
    Converter *converter = createConverter();
    char input[MAX_SIZE];
    printf("Enter a number to convert: ");
    scanf("%s", input);
    convertToBinary(converter, input);
    printf("Binary: %s\n", converter->binary);
    convertToHexadecimal(converter, input);
    printf("Hexadecimal: %s\n", converter->hexadecimal);
    convertToOctal(converter, input);
    printf("Octal: %s\n", converter->octal);
    convertToDecimal(converter, input);
    printf("Decimal: %s\n", converter->decimal);
    destroyConverter(converter);
    return 0;
}