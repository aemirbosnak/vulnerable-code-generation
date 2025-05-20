//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordCount;

void addWord(WordCount* wordCounts, int count, char* word) {
    int i;
    for (i = 0; i < count; i++) {
        strcpy(wordCounts[i].word, word);
        wordCounts[i].count++;
    }
}

int compareWords(const void* a, const void* b) {
    const WordCount* wordA = (const WordCount*)a;
    const WordCount* wordB = (const WordCount*)b;

    return strcmp(wordA->word, wordB->word);
}

void printWords(WordCount* wordCounts, int count) {
    qsort(wordCounts, count, sizeof(WordCount), compareWords);

    printf("Word count:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int isAlpha(char c) {
    if (isalpha(c)) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char** argv) {
    FILE* inputFile;
    char inputBuffer[MAX_WORD_LENGTH + 1];
    WordCount wordCounts[MAX_WORDS];
    int wordCount = 0;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        int length = strlen(inputBuffer);

        if (length > MAX_WORD_LENGTH) {
            printf("Error: word is too long.\n");
            fclose(inputFile);
            return 1;
        }

        int isValidWord = 1;

        for (int i = 0; i < length; i++) {
            if (!isAlpha(inputBuffer[i])) {
                isValidWord = 0;
                break;
            }
        }

        if (isValidWord) {
            addWord(wordCounts, wordCount, inputBuffer);
            wordCount++;
        }
    }

    fclose(inputFile);

    printWords(wordCounts, wordCount);

    return 0;
}