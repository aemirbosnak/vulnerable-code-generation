//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = (const WordFrequency *)a;
    const WordFrequency *wordB = (const WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int numWords = 0;
    WordFrequency words[MAX_NUM_WORDS];

    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_NUM_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        int wordLength = strlen(word);
        if (wordLength > MAX_WORD_LENGTH) {
            printf("Word is too long.\n");
            continue;
        }

        for (int i = 0; i < wordLength; i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                wordLength = i;
                break;
            }
        }

        strcpy(words[numWords].word, word);
        words[numWords].frequency = 1;
        numWords++;
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}