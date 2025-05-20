//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int code;
    int freq;
} Code;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];
    int i, j, n, maxCode = 0, codeSize = 0;
    char ch;
    Code *codeTable;

    printf("Enter the input file name: ");
    scanf("%s", inputFileName);

    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        fclose(inputFile);
        exit(1);
    }

    codeTable = (Code *)malloc(256 * sizeof(Code));
    if (codeTable == NULL) {
        printf("Error allocating memory!\n");
        fclose(inputFile);
        fclose(outputFile);
        exit(1);
    }

    n = 0;
    while ((ch = fgetc(inputFile))!= EOF) {
        if (ch < 32 || ch > 126) {
            printf("Error: Invalid character %c!\n", ch);
            fclose(inputFile);
            fclose(outputFile);
            exit(1);
        }
        if (n == 256) {
            printf("Error: Too many characters!\n");
            fclose(inputFile);
            fclose(outputFile);
            exit(1);
        }
        codeTable[ch].freq = 1;
        n++;
    }
    fclose(inputFile);

    for (i = 0; i < n; i++) {
        if (codeTable[i].freq > maxCode) {
            maxCode = codeTable[i].freq;
        }
    }

    for (i = 0; i < maxCode; i++) {
        for (j = 0; j < n; j++) {
            if (codeTable[j].freq == i) {
                codeTable[j].code = i;
                codeSize++;
                break;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (codeTable[i].code == 0) {
            codeTable[i].code = codeSize;
            codeSize++;
        }
    }

    fprintf(outputFile, "%d\n", n);
    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%d %c\n", codeTable[i].code, i);
    }

    fclose(outputFile);

    printf("Compression completed successfully!\n");

    return 0;
}