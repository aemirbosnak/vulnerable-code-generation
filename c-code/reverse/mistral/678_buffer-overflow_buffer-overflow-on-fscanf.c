#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    char word[256];

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    inputFile = fopen(argv[1], "r");
    outputFile = fopen(argv[2], "w");

    while (fscanf(inputFile, "%255s", word) != EOF) {
        if (word[0] >= 'A' && word[0] <= 'Z') {
            fprintf(outputFile, "%cay\n", toupper(word[0]));
        } else {
            fprintf(outputFile, "%s\n", word);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
