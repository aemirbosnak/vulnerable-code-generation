//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000 // Maximum length of binary number

typedef struct {
    char* binary;
    int decimal;
} BinaryConverter;

void initializeConverter(BinaryConverter* converter) {
    converter->binary = (char*)malloc(MAX_LENGTH * sizeof(char));
    converter->decimal = 0;
}

void freeConverter(BinaryConverter* converter) {
    free(converter->binary);
}

void convertBinaryToDecimal(BinaryConverter* converter) {
    int i, j;
    int power = 0;
    for (i = strlen(converter->binary) - 1; i >= 0; i--) {
        if (converter->binary[i] == '1') {
            power++;
        }
    }
    for (i = 0; i < strlen(converter->binary); i++) {
        if (converter->binary[i] == '1') {
            converter->decimal += pow(2, power);
        }
        power--;
    }
}

int main() {
    BinaryConverter converter;
    initializeConverter(&converter);

    char binary[MAX_LENGTH];
    int decimal;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    strcpy(converter.binary, binary);
    convertBinaryToDecimal(&converter);

    printf("Decimal equivalent: %d\n", converter.decimal);

    freeConverter(&converter);

    return 0;
}