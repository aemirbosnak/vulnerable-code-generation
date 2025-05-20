//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 12
#define MAX_CODE_TABLE_SIZE 4096
#define MAX_OUTPUT_SIZE 4096

typedef struct {
    char *value;
    int code;
} CodeTableEntry;

CodeTableEntry codeTable[MAX_CODE_TABLE_SIZE];
int codeTableSize = 0;

void initCodeTable() {
    codeTable[0].value = "";
    codeTable[0].code = 0;
    codeTableSize = 1;
}

int getCode(char *value) {
    int i;
    for (i = 0; i < codeTableSize; i++) {
        if (strcmp(value, codeTable[i].value) == 0) {
            return codeTable[i].code;
        }
    }
    return -1;
}

void addToCodeTable(char *value) {
    if (codeTableSize >= MAX_CODE_TABLE_SIZE) {
        printf("Code table is full.\n");
        exit(1);
    }
    codeTable[codeTableSize].value = value;
    codeTable[codeTableSize].code = codeTableSize;
    codeTableSize++;
}

void encode(char *input, char *output) {
    char *inputPtr = input;
    char *outputPtr = output;
    int code = 0;
    int codeLength = 0;
    int i;

    while (*inputPtr!= '\0') {
        code = getCode(*inputPtr);
        if (code == -1) {
            addToCodeTable(inputPtr);
            code = codeTableSize - 1;
        }
        inputPtr++;
        if (codeLength == MAX_CODE_LENGTH) {
            outputPtr += sprintf(outputPtr, "%c", codeTable[code].value[0]);
            codeLength = 1;
        } else {
            outputPtr += sprintf(outputPtr, "%c", codeTable[code].value[codeLength]);
            codeLength++;
        }
    }
    outputPtr += sprintf(outputPtr, "%c", codeTable[code].value[codeLength]);
}

void decode(char *input, char *output) {
    char *inputPtr = input;
    char *outputPtr = output;
    int code = 0;
    int i;

    while (*inputPtr!= '\0') {
        code = *inputPtr;
        if (code >= 'a' && code <= 'z') {
            strcat(output, codeTable[code - 'a'].value);
        } else if (code >= 'A' && code <= 'Z') {
            strcat(output, codeTable[code - 'A'].value);
        } else {
            strcat(output, codeTable[code].value);
        }
        inputPtr++;
    }
}

int main() {
    char input[MAX_OUTPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];

    printf("Enter the input string:\n");
    scanf("%s", input);

    encode(input, output);

    printf("Encoded string:\n%s\n", output);

    decode(output, input);

    printf("Decoded string:\n%s\n", input);

    return 0;
}