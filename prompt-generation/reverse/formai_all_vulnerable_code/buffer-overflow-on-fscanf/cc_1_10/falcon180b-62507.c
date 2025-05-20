//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 30

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = a;
    const WordFrequency *wordB = b;

    return strcmp(wordA->word, wordB->word);
}

void printWordFrequencies(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH + 1];
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        word[strcspn(word, "\n")] = '\0'; // Remove newline character

        int wordLength = strlen(word);
        if (wordLength > MAX_WORD_LENGTH) {
            wordLength = MAX_WORD_LENGTH;
        }

        strncpy(wordFrequencies[numWords].word, word, wordLength);
        wordFrequencies[numWords].frequency = 1;
        numWords++;
    }

    fclose(file);

    printWordFrequencies(wordFrequencies, numWords);

    return 0;
}