#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 1024

void translate_word(char *word) {
    if (strlen(word) > 0) {
        word[0] = toupper(word[0]);
        strcat(word, "AY");
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[MAX_WORD_LENGTH], outputFileName[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];

    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    inputFile = fopen(inputFileName, "r");
    if (!inputFile) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    outputFile = fopen(outputFileName, "w");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    while (fscanf(inputFile, "%s", word) != EOF) {
        translate_word(word);
        fprintf(outputFile, "%s ", word);
    }

    fclose(inputFile);
    fclose(outputFile);

    return EXIT_SUCCESS;
}
