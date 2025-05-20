//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    WordCount* wordA = (WordCount*)a;
    WordCount* wordB = (WordCount*)b;

    if (wordA->count > wordB->count) {
        return -1;
    } else if (wordA->count < wordB->count) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char* argv[]) {
    FILE* inputFile;
    char inputBuffer[MAX_WORD_LENGTH];
    char* word = NULL;
    WordCount wordCounts[MAX_NUM_WORDS];
    int numWords = 0;
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        word = strtok(inputBuffer, ",.?!;:\"'");

        while (word!= NULL) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, wordCounts[i].word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }

            if (i == numWords) {
                if (numWords == MAX_NUM_WORDS) {
                    printf("Error: maximum number of words reached\n");
                    exit(1);
                }

                strncpy(wordCounts[numWords].word, word, MAX_WORD_LENGTH);
                wordCounts[numWords].count = 1;
                numWords++;
            }

            word = strtok(NULL, ",.?!;:\"'");
        }
    }

    fclose(inputFile);

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}