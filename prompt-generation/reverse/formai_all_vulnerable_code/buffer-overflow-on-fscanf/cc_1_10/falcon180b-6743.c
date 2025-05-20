//Falcon-180B DATASET v1.0 Category: Text processing ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

bool compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;

    if (wordA->count > wordB->count) {
        return true;
    } else {
        return false;
    }
}

int main() {
    FILE *inputFile;
    char inputBuffer[MAX_WORD_LENGTH];
    char *word;
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;
    int i;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        word = strtok(inputBuffer, ",.?!;:");

        while (word!= NULL) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, wordCounts[i].word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }

            if (i == numWords) {
                if (numWords >= MAX_WORDS) {
                    printf("Error: Maximum number of words reached.\n");
                    exit(1);
                }

                strcpy(wordCounts[numWords].word, word);
                wordCounts[numWords].count = 1;
                numWords++;
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(inputFile);

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    printf("Word Count:\n");

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}