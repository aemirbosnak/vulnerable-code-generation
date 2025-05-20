#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(inputFile, "%1023s", word) == 1) {
        int length = strlen(word);
        if (length > 0) {
            word[0] = toupper(word[0]);
            strcat(word, "AY");
            fprintf(outputFile, "%s ", word);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
