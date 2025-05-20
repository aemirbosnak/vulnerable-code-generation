//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char* binary;
    char* octal;
    char* hexadecimal;
} ConversionResult;

ConversionResult convert(char* binary) {
    int length = strlen(binary);
    ConversionResult result;

    result.binary = malloc(length + 1);
    result.octal = malloc(length + 1);
    result.hexadecimal = malloc(length * 2 + 1);

    strcpy(result.binary, binary);
    strcpy(result.octal, "");
    strcpy(result.hexadecimal, "");

    for (int i = 0; i < length; i++) {
        char c = tolower(binary[i]);

        if (c == '0' || c == '1') {
            strcat(result.octal, c);
        } else {
            strcat(result.octal, "X");
        }

        if (c >= '0' && c <= '9') {
            strcat(result.hexadecimal, c);
        } else {
            strcat(result.hexadecimal, "X");
        }
    }

    return result;
}

void print_result(ConversionResult result) {
    printf("Binary: %s\nOctal: %s\nHexadecimal: %s\n", result.binary, result.octal, result.hexadecimal);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <binary number>\n", argv[0]);
        return 1;
    }

    char* binary = argv[1];
    ConversionResult result = convert(binary);
    print_result(result);

    free(result.binary);
    free(result.octal);
    free(result.hexadecimal);

    return 0;
}