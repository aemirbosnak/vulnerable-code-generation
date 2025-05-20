//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char* binary;
    int decimal;
} BinaryConverter;

void initBinaryConverter(BinaryConverter* converter) {
    converter->binary = (char*)malloc(MAX_SIZE * sizeof(char));
    converter->decimal = 0;
    converter->binary[0] = '\0';
}

void freeBinaryConverter(BinaryConverter* converter) {
    free(converter->binary);
}

void convertToBinary(int decimal, BinaryConverter* converter) {
    char* binary = converter->binary;
    int i = 0;

    while (decimal > 0) {
        int remainder = decimal % 2;
        binary[i] = remainder + '0';
        decimal /= 2;
        i++;
    }

    binary[i] = '\0';
    converter->decimal = decimal;
}

int main() {
    int decimal;
    BinaryConverter converter;

    initBinaryConverter(&converter);

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    convertToBinary(decimal, &converter);

    printf("Binary representation of %d: %s\n", decimal, converter.binary);

    freeBinaryConverter(&converter);

    return 0;
}