//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = (const WordFrequency *)a;
    const WordFrequency *wordB = (const WordFrequency *)b;
    return strcmp(wordA->word, wordB->word);
}

void printWordFrequencies(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char inputBuffer[MAX_WORD_LENGTH];
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        char *word = strtok(inputBuffer, ",.?!;:");
        while (word!= NULL) {
            int wordLength = strlen(word);
            if (wordLength > MAX_WORD_LENGTH) {
                printf("Warning: word '%s' is too long and will be truncated.\n", word);
                wordLength = MAX_WORD_LENGTH;
            }
            strncpy(wordFrequencies[numWords].word, word, wordLength);
            wordFrequencies[numWords].word[wordLength] = '\0';
            wordFrequencies[numWords].frequency++;
            numWords++;

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(inputFile);

    printWordFrequencies(wordFrequencies, numWords);

    return 0;
}