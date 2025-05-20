//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000
#define MAX_CHARACTERS 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = (const WordFrequency *)a;
    const WordFrequency *wordB = (const WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    WordFrequency *words[MAX_WORDS];
    int numWords = 0;
    int maxWordsReached = 0;
    int totalCharacters = 0;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fscanf(file, "%s", word)!= EOF) {
        totalCharacters += strlen(word);

        if (numWords >= MAX_WORDS) {
            maxWordsReached = 1;
            break;
        }

        WordFrequency *newWord = malloc(sizeof(WordFrequency));
        strcpy(newWord->word, word);
        newWord->count = 1;
        words[numWords++] = newWord;
    }

    if (maxWordsReached) {
        printf("Warning: Maximum number of words reached.\n");
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordFrequency *), compareWords);

    printf("Total number of words: %d\n", numWords);
    printf("Total number of characters: %d\n", totalCharacters);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->count);
    }

    return 0;
}