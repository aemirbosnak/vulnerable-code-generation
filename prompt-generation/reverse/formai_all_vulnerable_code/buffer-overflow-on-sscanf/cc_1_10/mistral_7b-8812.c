//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

int main() {
    FILE *inputFile, *outputFile;
    Word words[MAX_WORDS];
    int i, j, wordIndex = 0;
    char line[1024], word[MAX_WORD_LEN];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        sscanf(line, "%s", word);
        for (i = 0; i < wordIndex; i++) {
            if (strcasecmp(words[i].word, word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == wordIndex) {
            strcpy(words[wordIndex].word, word);
            words[wordIndex++].count = 1;
        }
    }

    for (i = 0; i < wordIndex; i++) {
        fprintf(outputFile, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}