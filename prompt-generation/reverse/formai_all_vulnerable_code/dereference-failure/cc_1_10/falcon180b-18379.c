//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *binary;
    char *decimal;
} ConversionResult;

ConversionResult convert(const char *binary) {
    int decimal = 0;
    int power = 0;
    ConversionResult result;

    result.binary = strdup(binary);
    result.decimal = malloc(MAX_LINE_LENGTH);

    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }

        power++;
    }

    snprintf(result.decimal, MAX_LINE_LENGTH, "%d", decimal);

    return result;
}

void freeConversionResult(ConversionResult *result) {
    free(result->binary);
    free(result->decimal);
    free(result);
}

int main() {
    char input[MAX_LINE_LENGTH];
    ConversionResult result;

    printf("Enter a binary number: ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    result = convert(input);

    printf("Decimal equivalent: %s\n", result.decimal);

    freeConversionResult(&result);

    return 0;
}