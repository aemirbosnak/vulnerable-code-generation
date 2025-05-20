//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void readWords(char *filename, WordCount *wordCounts, int numWords) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    char *token;
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= numWords) {
            break;
        }
        wordCounts[i].word[0] = '\0';
        strncat(wordCounts[i].word, word, MAX_WORD_LENGTH - 1);
        wordCounts[i].count = 1;
        i++;
    }

    qsort(wordCounts, i, sizeof(WordCount), compareWords);

    fclose(file);
}

void printTopWords(WordCount *wordCounts, int numWords, int numTopWords) {
    for (int i = 0; i < numTopWords && i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    char inputFilename[MAX_WORD_LENGTH];
    char outputFilename[MAX_WORD_LENGTH];
    int numWords;

    printf("Enter the name of the input file: ");
    scanf("%s", inputFilename);

    printf("Enter the name of the output file: ");
    scanf("%s", outputFilename);

    printf("Enter the number of top words to print: ");
    scanf("%d", &numWords);

    WordCount wordCounts[MAX_WORDS];
    readWords(inputFilename, wordCounts, numWords);

    int numTopWords = 10;
    printTopWords(wordCounts, numWords, numTopWords);

    FILE *outputFile = fopen(outputFilename, "w");

    for (int i = 0; i < numTopWords && i < numWords; i++) {
        fprintf(outputFile, "%s %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    fclose(outputFile);

    return 0;
}