//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char letter;
    int frequency;
} CharFreq;

#define ALPHABET_SIZE 26

void initializeFrequencyTable(CharFreq table[]) {
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        table[i].letter = 'a' + i;
        table[i].frequency = 0;
    }
}

void compressFile(char *inputFile, char *outputFile) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "wb");
    CharFreq frequencyTable[ALPHABET_SIZE];
    initializeFrequencyTable(frequencyTable);
    char currentChar;
    int tableIndex;

    while ((currentChar = fgetc(input)) != EOF) {
        tableIndex = currentChar - 'a';
        frequencyTable[tableIndex].frequency++;
    }

    fputc('C', output); // Indicate that this is a romantic compression algorithm file
    fputc('O', output);
    fputc('D', output);
    fputc('E', output);
    fputc(':', output); // Separator for frequency table

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        fwrite(&frequencyTable[i].frequency, sizeof(int), 1, output);
    }

    rewind(input); // Rewind the input file to the beginning

    while ((currentChar = fgetc(input)) != EOF) {
        tableIndex = currentChar - 'a';
        fputc(tableIndex + 'a', output); // Write the compressed character to the output file
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    compressFile(argv[1], argv[2]);

    printf("A love letter has been compressed and saved as %s.\n", argv[2]);
    return 0;
}