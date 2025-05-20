//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

typedef struct {
    char* input;
    char* output;
} BinaryConverter;

void initializeConverter(BinaryConverter* converter) {
    converter->input = malloc(MAX_INPUT_LENGTH * sizeof(char));
    converter->output = malloc(MAX_INPUT_LENGTH * sizeof(char));
    memset(converter->input, 0, MAX_INPUT_LENGTH);
    memset(converter->output, 0, MAX_INPUT_LENGTH);
}

void destroyConverter(BinaryConverter* converter) {
    free(converter->input);
    free(converter->output);
}

void convertToBinary(BinaryConverter* converter) {
    char input[MAX_INPUT_LENGTH];
    strcpy(input, converter->input);
    int i = 0;
    int j = strlen(input) - 1;
    while (i < j) {
        if (isdigit(input[i])) {
            int decimal = input[i] - '0';
            char binary[3];
            sprintf(binary, "%02b", decimal);
            strcat(converter->output, binary);
        } else {
            strcat(converter->output, &input[i]);
        }
        i++;
    }
}

int main() {
    BinaryConverter converter;
    initializeConverter(&converter);
    printf("Enter a string to convert to binary: ");
    scanf("%s", converter.input);
    convertToBinary(&converter);
    printf("Binary representation: %s\n", converter.output);
    destroyConverter(&converter);
    return 0;
}