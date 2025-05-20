//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int code;
    int count;
} Symbol;

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    char ch;
    int i, j;
    Symbol table[256];

    printf("Enter the input file name: ");
    scanf("%s", inputFileName);
    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error: Unable to open output file.\n");
        fclose(inputFile);
        exit(1);
    }

    // Initialize the symbol table
    for (i = 0; i < 256; i++) {
        table[i].code = i;
        table[i].count = 0;
    }

    // Read the input file and build the symbol table
    while ((ch = fgetc(inputFile))!= EOF) {
        if (table[ch].code == 0) {
            table[ch].code = ++i;
        }
        table[ch].count++;
    }

    // Write the symbol table to the output file
    fwrite(&i, sizeof(int), 1, outputFile);
    for (i = 0; i < 256; i++) {
        if (table[i].code!= 0) {
            fwrite(&table[i], sizeof(Symbol), 1, outputFile);
        }
    }

    // Compress the input file
    rewind(inputFile);
    j = 0;
    while ((ch = fgetc(inputFile))!= EOF) {
        if (table[ch].code!= 0) {
            fputc(table[ch].code, outputFile);
            j++;
        }
    }

    // Write the compressed data size to the output file
    rewind(outputFile);
    fwrite(&j, sizeof(int), 1, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("Compression completed successfully.\n");

    return 0;
}