//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCES 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wordCountA = (const WordCount*)a;
    const WordCount* wordCountB = (const WordCount*)b;

    return strcmp(wordCountA->word, wordCountB->word);
}

void printTopWords(WordCount* wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    printf("Top %d most frequent words:\n", numWords);
    for (int i = 0; i < numWords; ++i) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char sentence[MAX_SENTENCES][MAX_WORD_LENGTH];
    int numSentences = 0;

    char word[MAX_WORD_LENGTH];
    int wordIndex = 0;

    while (fscanf(inputFile, "%s", word)!= EOF) {
        strcpy(sentence[numSentences], word);
        ++numSentences;

        if (wordIndex >= MAX_WORD_LENGTH) {
            printf("Error: Maximum word length exceeded.\n");
            return 1;
        }

        strcpy(sentence[numSentences - 1] + strlen(sentence[numSentences - 1]), " ");
        ++wordIndex;
    }

    fclose(inputFile);

    WordCount wordCounts[MAX_WORD_LENGTH];
    memset(wordCounts, 0, sizeof(wordCounts));

    int numWords = 0;

    for (int i = 0; i < numSentences; ++i) {
        char* token = strtok(sentence[i], " ");
        while (token!= NULL) {
            int wordLength = strlen(token);

            if (wordLength > MAX_WORD_LENGTH) {
                printf("Error: Word length exceeded maximum limit.\n");
                return 1;
            }

            if (numWords >= MAX_WORD_LENGTH) {
                printf("Error: Maximum number of words exceeded.\n");
                return 1;
            }

            strcpy(wordCounts[numWords].word, token);
            ++wordCounts[numWords].count;

            ++numWords;

            token = strtok(NULL, " ");
        }
    }

    printTopWords(wordCounts, numWords);

    return 0;
}