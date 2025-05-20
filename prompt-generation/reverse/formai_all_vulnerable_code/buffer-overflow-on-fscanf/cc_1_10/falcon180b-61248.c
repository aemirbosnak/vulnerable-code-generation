//Falcon-180B DATASET v1.0 Category: Educational ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *word1 = a;
    const WordFrequency *word2 = b;
    return strcmp(word1->word, word2->word);
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    char buffer[MAX_WORD_LEN];
    WordFrequency words[MAX_WORDS] = {{0}};
    int numWords = 0;

    while (fscanf(inputFile, "%s", buffer)!= EOF) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(buffer, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }
            strcpy(words[numWords].word, buffer);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}