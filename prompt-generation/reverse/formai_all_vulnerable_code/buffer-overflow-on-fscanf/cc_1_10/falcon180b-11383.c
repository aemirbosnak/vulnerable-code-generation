//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 1000
#define MAX_FILE_SIZE 1000000 // 1 MB

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = a;
    const WordFrequency *wordB = b;
    return strcmp(wordA->word, wordB->word);
}

void printWordFrequency(WordFrequency *wordFrequency, int numWords) {
    printf("Word Frequency:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].count);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char word[MAX_WORD_LENGTH + 1];
    WordFrequency wordFrequency[MAX_WORD_COUNT];
    int numWords = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORD_COUNT) {
            printf("Maximum number of words reached.\n");
            break;
        }
        strcpy(wordFrequency[numWords].word, word);
        numWords++;
    }

    fclose(file);

    qsort(wordFrequency, numWords, sizeof(WordFrequency), compareWords);

    printWordFrequency(wordFrequency, numWords);

    return 0;
}