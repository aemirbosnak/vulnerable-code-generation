#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 1024

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(inputFile, "%s", word) != EOF) {
        if (strlen(word) > 0) {
            word[0] = toupper(word[0]);
            strcat(word, "ay");
        } else {
            strcpy(word, "way");
        }
        fprintf(outputFile, "%s ", word);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
