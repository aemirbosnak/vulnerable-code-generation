//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000
#define MAX_CODE_VALUE 4095

typedef struct {
    char code;
    int frequency;
} Code;

Code codeTable[MAX_CODE_VALUE + 1];
int codeTableSize = 0;

void generateCodeTable(char input[], int inputSize) {
    int i;
    for (i = 0; i < inputSize; i++) {
        codeTable[input[i]].frequency += 1;
    }
}

void buildCodeTable(char input[], int inputSize) {
    int i;
    for (i = 0; i < inputSize; i++) {
        if (codeTable[input[i]].frequency > 0) {
            codeTable[input[i]].code = codeTableSize++;
        }
    }
}

void encode(char input[], int inputSize, char output[], int *outputSize) {
    int i;
    for (i = 0; i < inputSize; i++) {
        output[(*outputSize)++] = codeTable[input[i]].code;
    }
}

void decode(char input[], int inputSize, char output[], int *outputSize) {
    int i;
    for (i = 0; i < inputSize; i++) {
        output[(*outputSize)++] = codeTable[input[i]].code;
    }
}

int main() {
    char input[MAX_LENGTH], output[MAX_LENGTH];
    int inputSize, outputSize;

    printf("Enter input string: ");
    scanf("%s", input);
    inputSize = strlen(input);

    generateCodeTable(input, inputSize);
    buildCodeTable(input, inputSize);

    encode(input, inputSize, output, &outputSize);
    printf("Encoded string: ");
    for (int i = 0; i < outputSize; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    decode(output, outputSize, input, &inputSize);
    printf("Decoded string: %s\n", input);

    return 0;
}