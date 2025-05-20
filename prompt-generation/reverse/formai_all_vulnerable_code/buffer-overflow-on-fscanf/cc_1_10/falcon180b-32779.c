//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char inputBuffer[MAX_WORD_LENGTH];
    char wordBuffer[MAX_WORD_LENGTH];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        strcpy(wordBuffer, inputBuffer);
        char *token = strtok(wordBuffer, ",.?!;:");
        while (token!= NULL) {
            int wordLength = strlen(token);
            if (wordLength > MAX_WORD_LENGTH) {
                printf("Warning: word '%s' is too long and will be truncated.\n", token);
                wordLength = MAX_WORD_LENGTH;
            }
            strncpy(wordCounts[numWords].word, token, wordLength);
            wordCounts[numWords].word[wordLength] = '\0';
            wordCounts[numWords].count = 1;
            numWords++;

            if (numWords >= MAX_WORDS) {
                printf("Error: exceeded maximum number of words.\n");
                break;
            }

            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(inputFile);

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}