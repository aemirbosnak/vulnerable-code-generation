//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_NAME_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWordsFromFile(FILE *file, WordCount *wordCounts, int numWords) {
    char word[MAX_WORD_LENGTH];
    char fileName[MAX_FILE_NAME_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) > 0) {
            for (int j = 0; j < strlen(word); j++) {
                if (!isalpha(word[j])) {
                    word[j] = '\0';
                }
            }
            strcpy(wordCounts[i].word, word);
            wordCounts[i].count = 1;
            i++;
        }
    }
}

void countWords(WordCount *wordCounts, int numWords, char *wordToCount) {
    int i;

    for (i = 0; i < numWords; i++) {
        if (strcmp(wordCounts[i].word, wordToCount) == 0) {
            wordCounts[i].count++;
        }
    }
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    WordCount wordCounts[MAX_WORD_LENGTH];
    int numWords = 0;

    if (argc < 3) {
        printf("Usage: %s <filename> <word_to_count>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        exit(1);
    }

    readWordsFromFile(file, wordCounts, MAX_WORD_LENGTH);

    strcpy(wordCounts[numWords].word, argv[2]);
    wordCounts[numWords].count = 1;
    numWords++;

    countWords(wordCounts, numWords, argv[2]);

    printWordCounts(wordCounts, numWords);

    fclose(file);

    return 0;
}