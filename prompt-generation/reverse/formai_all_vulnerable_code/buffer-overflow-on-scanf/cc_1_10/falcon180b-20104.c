//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000000

typedef struct {
    char *binary;
    char *decimal;
    char *hexadecimal;
} ConversionResult;

ConversionResult convert(char *binary, int length) {
    char decimal[MAX_LENGTH];
    char hexadecimal[MAX_LENGTH];
    int i;

    ConversionResult result = {
       .binary = binary,
       .decimal = decimal,
       .hexadecimal = hexadecimal
    };

    sprintf(result.decimal, "%d", 0);
    sprintf(result.hexadecimal, "%X", 0);

    for (i = 0; i < length; i++) {
        if (binary[i] == '1') {
            sprintf(result.decimal, "%d", result.decimal[0] * 2 + 1);
            sprintf(result.hexadecimal, "%X", result.hexadecimal[0] * 2 + 1);
        } else {
            sprintf(result.decimal, "%d", result.decimal[0] * 2);
            sprintf(result.hexadecimal, "%X", result.hexadecimal[0] * 2);
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
    char binary[MAX_LENGTH];
    int length;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    length = strlen(binary);

    ConversionResult result = convert(binary, length);

    printf("\nBinary: %s\nDecimal: %s\nHexadecimal: %s\n", result.binary, result.decimal, result.hexadecimal);

    return 0;
}