//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    char *binary;
    int decimal;
} BinaryConverter;

void initialize(BinaryConverter *binaryConverter, int decimal) {
    binaryConverter->binary = (char *)malloc(MAX_SIZE * sizeof(char));
    binaryConverter->decimal = decimal;
}

void convert(BinaryConverter *binaryConverter) {
    int i = 0;
    while (binaryConverter->decimal > 0) {
        binaryConverter->binary[i] = (binaryConverter->decimal % 2) + '0';
        binaryConverter->decimal /= 2;
        i++;
    }
    binaryConverter->binary[i] = '\0';
}

void reverse(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int decimal;
    BinaryConverter binaryConverter;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    initialize(&binaryConverter, decimal);
    convert(&binaryConverter);

    printf("Binary representation: %s\n", binaryConverter.binary);

    free(binaryConverter.binary);
    return 0;
}