//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_SIZE 4096
#define MAX_STRING_SIZE 4096
#define MAX_CODE_TABLE_SIZE 4096

typedef struct {
    char *string;
    int code;
} CodeTable;

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    char inputBuffer[MAX_STRING_SIZE];
    char outputBuffer[MAX_STRING_SIZE];
    int inputLength, outputLength;
    int i, j;
    int codeTable[MAX_CODE_TABLE_SIZE];
    int codeTableSize = 0;
    CodeTable *codeTableArray = NULL;
    int codeTableArraySize = 0;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Open output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // Read input file into buffer
    inputLength = fread(inputBuffer, sizeof(char), MAX_STRING_SIZE, inputFile);
    if (inputLength == 0) {
        printf("Error: input file is empty.\n");
        exit(1);
    }

    // Build code table
    for (i = 0; i < inputLength; i++) {
        if (codeTable[inputBuffer[i]] == 0) {
            codeTable[inputBuffer[i]] = codeTableSize;
            codeTableSize++;
        }
    }

    // Encode input buffer
    outputLength = 0;
    for (i = 0; i < inputLength; i++) {
        j = codeTable[inputBuffer[i]];
        if (j == 0) {
            outputBuffer[outputLength++] = inputBuffer[i];
            codeTable[inputBuffer[i]] = codeTableSize;
            codeTableSize++;
        } else {
            outputBuffer[outputLength++] = '0' + (j >> 4);
            outputBuffer[outputLength++] = '0' + (j & 0x0f);
        }
    }

    // Write encoded buffer to output file
    fwrite(outputBuffer, sizeof(char), outputLength, outputFile);

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}