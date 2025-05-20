//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(char *filename, WordCount *wordCounts, int numWords) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= numWords) {
            printf("Error: too many words in file.\n");
            exit(1);
        }
        strcpy(wordCounts[i].word, word);
        wordCounts[i].count = 1;
        i++;
    }
    fclose(file);
}

void translateWords(WordCount *wordCounts, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %s\n", wordCounts[i].word, wordCounts[i].word);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    char inputFilename[MAX_WORD_LENGTH];
    strcpy(inputFilename, argv[1]);
    char outputFilename[MAX_WORD_LENGTH];
    strcpy(outputFilename, argv[2]);
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;
    readWords(inputFilename, wordCounts, MAX_WORDS);
    numWords = sizeof(wordCounts) / sizeof(wordCounts[0]);
    translateWords(wordCounts, numWords);
    return 0;
}