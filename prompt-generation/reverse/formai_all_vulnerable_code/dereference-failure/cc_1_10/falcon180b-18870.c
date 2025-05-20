//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *word1 = (WordCount *)a;
    WordCount *word2 = (WordCount *)b;
    return strcmp(word1->word, word2->word);
}

int main(int argc, char **argv) {
    FILE *inputFile;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int numWords = 0;
    WordCount *wordCounts = malloc(MAX_NUM_WORDS * sizeof(WordCount));

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        int wordIndex = 0;
        char *token = strtok(line, " \t\n\r\f\v");
        while (token!= NULL) {
            if (wordIndex >= MAX_NUM_WORDS) {
                printf("Too many words in line %d\n", numWords + 1);
                return 1;
            }
            strcpy(wordCounts[wordIndex].word, token);
            wordCounts[wordIndex].count++;
            wordIndex++;
            token = strtok(NULL, " \t\n\r\f\v");
        }
        numWords++;
    }

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    free(wordCounts);
    fclose(inputFile);
    return 0;
}