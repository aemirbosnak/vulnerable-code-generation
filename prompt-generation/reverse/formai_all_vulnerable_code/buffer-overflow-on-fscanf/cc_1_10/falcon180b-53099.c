//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = a;
    const WordFrequency *wordB = b;

    return strcmp(wordA->word, wordB->word);
}

void printWordFrequency(WordFrequency *wordFrequency, int numWords) {
    qsort(wordFrequency, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].count);
    }
}

int main() {
    FILE *file;
    char buffer[MAX_WORD_LENGTH];
    char *word;
    int numWords = 0;
    WordFrequency *wordFrequency = malloc(MAX_WORDS * sizeof(WordFrequency));

    file = fopen("ebook.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, "%s", buffer)!= EOF) {
        word = strtok(buffer, ",.!?;:\"'");

        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }

            wordFrequency[numWords].word = strdup(word);
            wordFrequency[numWords].count = 1;

            numWords++;

            word = strtok(NULL, ",.!?;:\"'");
        }
    }

    fclose(file);

    printWordFrequency(wordFrequency, numWords);

    for (int i = 0; i < numWords; i++) {
        free(wordFrequency[i].word);
    }

    free(wordFrequency);

    return 0;
}