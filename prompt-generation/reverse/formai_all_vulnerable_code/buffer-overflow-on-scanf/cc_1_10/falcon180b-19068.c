//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    char* binary;
    int decimal;
} BinaryConverter;

void initBinaryConverter(BinaryConverter* converter) {
    converter->binary = (char*) malloc(MAX_SIZE * sizeof(char));
    converter->decimal = 0;
}

void freeBinaryConverter(BinaryConverter* converter) {
    free(converter->binary);
}

void convertToBinary(int decimal, BinaryConverter* converter) {
    int remainder;
    char* binary = converter->binary;
    int size = 0;

    while (decimal > 0) {
        remainder = decimal % 2;
        binary[size++] = (remainder == 0)? '0' : '1';
        decimal /= 2;
    }

    binary[size] = '\0';
    converter->decimal = atoi(binary);
}

int main() {
    BinaryConverter converter;
    int decimal;

    initBinaryConverter(&converter);

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    convertToBinary(decimal, &converter);

    printf("Binary representation of %d is: %s\n", decimal, converter.binary);

    freeBinaryConverter(&converter);

    return 0;
}