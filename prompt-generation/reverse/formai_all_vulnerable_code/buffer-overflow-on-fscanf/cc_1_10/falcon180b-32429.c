//Falcon-180B DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wordA = (const WordCount*)a;
    const WordCount* wordB = (const WordCount*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    char inputText[1000000];
    char word[MAX_WORD_LENGTH + 1];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;
    FILE* inputFile;

    printf("Enter the name of the input file: ");
    scanf("%s", inputText);

    inputFile = fopen(inputText, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }

        if (i == numWords) {
            strcpy(wordCounts[numWords].word, word);
            wordCounts[numWords].count = 1;
            numWords++;
        }
    }

    fclose(inputFile);

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}