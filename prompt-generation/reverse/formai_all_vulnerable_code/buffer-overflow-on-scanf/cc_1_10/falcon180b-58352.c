//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_OUTPUT_SIZE 33

typedef struct {
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];
} BinaryConverter;

void initializeConverter(BinaryConverter *converter) {
    strcpy(converter->input, "");
    strcpy(converter->output, "");
}

void addInput(BinaryConverter *converter, char input) {
    if (strlen(converter->input) >= MAX_INPUT_SIZE) {
        printf("Error: Input is too large.\n");
        return;
    }
    strcat(converter->input, input);
}

void convert(BinaryConverter *converter) {
    if (strlen(converter->input) == 0) {
        printf("Error: Input is empty.\n");
        return;
    }
    for (int i = 0; i < strlen(converter->input); i++) {
        if (converter->input[i] < '0' || converter->input[i] > '9') {
            printf("Error: Input contains non-numeric characters.\n");
            return;
        }
        int decimal = converter->input[i] - '0';
        char binary = (decimal % 2) + '0';
        strcat(converter->output, binary);
        decimal /= 2;
    }
}

void displayOutput(BinaryConverter *converter) {
    if (strlen(converter->output) == 0) {
        printf("Error: Input is not a valid integer.\n");
        return;
    }
    printf("Binary: %s\n", converter->output);
}

int main() {
    BinaryConverter converter;
    initializeConverter(&converter);
    char input[MAX_INPUT_SIZE];
    printf("Enter a decimal number: ");
    scanf("%s", input);
    for (int i = 0; i < strlen(input); i++) {
        addInput(&converter, input[i]);
    }
    convert(&converter);
    displayOutput(&converter);
    return 0;
}