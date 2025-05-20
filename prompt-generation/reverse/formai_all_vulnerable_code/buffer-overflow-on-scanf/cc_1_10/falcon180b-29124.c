//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000
#define MAX_NUM_SIZE 32

typedef struct {
    char *binary;
    char *octal;
    char *decimal;
    char *hexadecimal;
} NumberSystem;

NumberSystem convert(char *number, int base) {
    NumberSystem result;
    int length = strlen(number);
    result.binary = malloc(MAX_NUM_SIZE * sizeof(char));
    result.octal = malloc(MAX_NUM_SIZE * sizeof(char));
    result.decimal = malloc(MAX_NUM_SIZE * sizeof(char));
    result.hexadecimal = malloc(MAX_NUM_SIZE * sizeof(char));

    if (base == 2) {
        sprintf(result.binary, "%b", atoi(number));
        sprintf(result.octal, "%o", atoi(number));
        sprintf(result.decimal, "%d", atoi(number));
        sprintf(result.hexadecimal, "%x", atoi(number));
    } else if (base == 8) {
        sprintf(result.binary, "%b", atoi(number));
        sprintf(result.octal, "%o", atoi(number));
        sprintf(result.decimal, "%d", atoi(number));
        sprintf(result.hexadecimal, "%x", atoi(number));
    } else if (base == 10) {
        sprintf(result.binary, "%b", atoi(number));
        sprintf(result.octal, "%o", atoi(number));
        sprintf(result.decimal, "%d", atoi(number));
        sprintf(result.hexadecimal, "%x", atoi(number));
    } else if (base == 16) {
        sprintf(result.binary, "%b", atoi(number));
        sprintf(result.octal, "%o", atoi(number));
        sprintf(result.decimal, "%d", atoi(number));
        sprintf(result.hexadecimal, "%x", atoi(number));
    }

    return result;
}

int main(int argc, char *argv[]) {
    char *input;
    int base = 10;

    if (argc == 1) {
        printf("Please enter a number to convert:\n");
        scanf("%s", input);
    } else {
        input = argv[1];
    }

    if (argc > 2) {
        if (strcmp(argv[2], "2") == 0) {
            base = 2;
        } else if (strcmp(argv[2], "8") == 0) {
            base = 8;
        } else if (strcmp(argv[2], "10") == 0) {
            base = 10;
        } else if (strcmp(argv[2], "16") == 0) {
            base = 16;
        } else {
            printf("Invalid base: %s\n", argv[2]);
            return 1;
        }
    }

    NumberSystem result = convert(input, base);

    printf("Binary: %s\n", result.binary);
    printf("Octal: %s\n", result.octal);
    printf("Decimal: %s\n", result.decimal);
    printf("Hexadecimal: %s\n", result.hexadecimal);

    free(result.binary);
    free(result.octal);
    free(result.decimal);
    free(result.hexadecimal);

    return 0;
}