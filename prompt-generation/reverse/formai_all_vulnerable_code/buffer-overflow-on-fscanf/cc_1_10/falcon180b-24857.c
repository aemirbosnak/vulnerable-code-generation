//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    WordCount* wordA = (WordCount*)a;
    WordCount* wordB = (WordCount*)b;

    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char** argv) {
    FILE* inputFile = NULL;
    char inputBuffer[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i = 0;

    if (argc < 2) {
        printf("Error: Please specify an input file.\n");
        return 1;
    }

    inputFile = fopen(argv[1], "r");

    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            fclose(inputFile);
            return 1;
        }

        inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; // Remove newline character

        for (i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, inputBuffer) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == numWords) {
            strcpy(words[numWords].word, inputBuffer);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}