//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *binary;
    char *octal;
    char *decimal;
    char *hexadecimal;
} Conversion;

void convert_binary(Conversion *result, char *binary) {
    int len = strlen(binary);
    result->binary = (char *)malloc(len + 1);
    strcpy(result->binary, binary);

    int decimal = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, len - i - 1);
        }
    }

    result->decimal = (char *)malloc(20);
    sprintf(result->decimal, "%d", decimal);

    result->octal = (char *)malloc(20);
    sprintf(result->octal, "%o", decimal);

    result->hexadecimal = (char *)malloc(20);
    sprintf(result->hexadecimal, "%X", decimal);
}

void print_conversion(Conversion *result) {
    printf("Binary: %s\n", result->binary);
    printf("Octal: %s\n", result->octal);
    printf("Decimal: %s\n", result->decimal);
    printf("Hexadecimal: %s\n", result->hexadecimal);
}

int main() {
    char binary[100];
    printf("Enter a binary number: ");
    scanf("%s", binary);

    Conversion result;
    convert_binary(&result, binary);
    print_conversion(&result);

    free(result.binary);
    free(result.decimal);
    free(result.octal);
    free(result.hexadecimal);

    return 0;
}