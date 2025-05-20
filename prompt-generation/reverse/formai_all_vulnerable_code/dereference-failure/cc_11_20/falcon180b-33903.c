//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LEN 4096
#define MAX_CODE_TABLE_SIZE 256

typedef struct {
    int code;
    int len;
} CodeTable;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    int i, j, k, code, len, codeTableSize = 0;
    char inputBuffer[4096], outputBuffer[4096];
    CodeTable codeTable[MAX_CODE_TABLE_SIZE];

    printf("Enter the input file name: ");
    scanf("%s", inputFileName);

    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    for (i = 0; i < MAX_CODE_TABLE_SIZE; i++) {
        codeTable[i].code = -1;
        codeTable[i].len = 0;
    }

    while (fread(inputBuffer, 1, 4096, inputFile) > 0) {
        for (i = 0; i < strlen(inputBuffer); i++) {
            if (codeTable[inputBuffer[i]].code == -1) {
                codeTable[inputBuffer[i]].code = codeTableSize;
                codeTable[inputBuffer[i]].len = 1;
                codeTableSize++;
            } else {
                codeTable[inputBuffer[i]].len++;
            }
        }
    }

    for (i = 0; i < MAX_CODE_TABLE_SIZE; i++) {
        if (codeTable[i].code!= -1) {
            codeTable[i].code += 256;
        }
    }

    for (i = 0; i < strlen(inputBuffer); i++) {
        if (codeTable[inputBuffer[i]].code!= -1) {
            code = codeTable[inputBuffer[i]].code;
            len = codeTable[inputBuffer[i]].len;
            for (j = 0; j < len; j++) {
                outputBuffer[k++] = code;
            }
        } else {
            outputBuffer[k++] = inputBuffer[i];
        }
    }

    fwrite(outputBuffer, 1, k, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}