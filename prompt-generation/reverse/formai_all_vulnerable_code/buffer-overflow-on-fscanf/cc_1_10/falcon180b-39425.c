//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(char *filename, WordCount *wordCounts, int numWords) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Error: too many unique words in file\n");
                exit(1);
            }
            strcpy(wordCounts[numWords].word, word);
            wordCounts[numWords].count = 1;
            numWords++;
        }
    }

    fclose(file);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    printf("Word counts:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    readWords(argv[1], wordCounts, numWords);
    printWordCounts(wordCounts, numWords);

    return 0;
}