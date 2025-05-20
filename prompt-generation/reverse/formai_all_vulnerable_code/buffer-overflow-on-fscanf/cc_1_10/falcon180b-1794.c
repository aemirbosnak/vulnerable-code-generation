//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUM_WORDS 10000
#define WORD_SEPARATORS ",.!?;:\"'()[]{}<>"

typedef struct {
    char word[MAX_WORD_LENGTH];
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

    char word[MAX_WORD_LENGTH];
    WordFrequency wordFrequencies[MAX_NUM_WORDS];
    int numWords = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_NUM_WORDS) {
            printf("Reached maximum number of words.\n");
            break;
        }

        int wordLength = strlen(word);
        if (wordLength > MAX_WORD_LENGTH) {
            printf("Word is too long.\n");
            continue;
        }

        for (int i = 0; i < wordLength; i++) {
            if (!isalnum(word[i])) {
                if (strchr(WORD_SEPARATORS, word[i]) == NULL) {
                    printf("Invalid character in word.\n");
                    continue;
                }
            }
        }

        int index = 0;
        while (index < numWords && strcmp(wordFrequencies[index].word, word)!= 0) {
            index++;
        }

        if (index == numWords) {
            strcpy(wordFrequencies[index].word, word);
            wordFrequencies[index].frequency = 1;
            numWords++;
        } else {
            wordFrequencies[index].frequency++;
        }
    }

    fclose(file);
    printWordFrequencies(wordFrequencies, numWords);

    return 0;
}