//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: random
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    FILE *inputFile;
    char inputBuffer[1000];
    int numWords = 0;
    WordFrequency *wordFrequencies = malloc(MAX_NUM_WORDS * sizeof(WordFrequency));

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(inputBuffer, sizeof(inputBuffer), inputFile)!= NULL) {
        char *wordStart = inputBuffer;
        while (isspace(*wordStart)) {
            wordStart++;
        }
        char *wordEnd = wordStart;
        while (!isspace(*wordEnd)) {
            wordEnd++;
        }
        *wordEnd = '\0';

        if (strlen(wordStart) > 0) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Reached maximum number of words.\n");
                break;
            }

            WordFrequency *word = &wordFrequencies[numWords];
            strcpy(word->word, wordStart);
            word->frequency = 0;
            numWords++;
        }
    }

    fclose(inputFile);

    for (int i = 0; i < numWords; i++) {
        WordFrequency *word = &wordFrequencies[i];
        inputFile = fopen("input.txt", "r");
        char inputBuffer[1000];
        while (fgets(inputBuffer, sizeof(inputBuffer), inputFile)!= NULL) {
            char *wordStart = inputBuffer;
            while (isspace(*wordStart)) {
                wordStart++;
            }
            char *wordEnd = wordStart;
            while (!isspace(*wordEnd)) {
                wordEnd++;
            }
            *wordEnd = '\0';

            if (strcmp(word->word, wordStart) == 0) {
                word->frequency++;
            }
        }
        fclose(inputFile);
    }

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        WordFrequency *word = &wordFrequencies[i];
        printf("%s\t%d\n", word->word, word->frequency);
    }

    free(wordFrequencies);
    return 0;
}