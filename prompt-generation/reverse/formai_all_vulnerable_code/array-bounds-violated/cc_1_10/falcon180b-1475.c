//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

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
    FILE *inputFile;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;
    int i;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        int wordCount = 0;
        char *token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);
            for (i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                    break;
                }
            }
            if (i == strlen(word)) {
                word[i - 1] = '\0';
            }
            if (strlen(word) > 0) {
                wordCount++;
            }
            token = strtok(NULL, " ");
        }
        if (wordCount > 0) {
            if (numWords == MAX_WORDS) {
                printf("Error: Maximum number of words reached.\n");
                exit(1);
            }
            strcpy(wordFrequencies[numWords].word, word);
            wordFrequencies[numWords].count = wordCount;
            numWords++;
        }
    }

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    printf("Word\t\tFrequency\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t\t%d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    fclose(inputFile);
    return 0;
}