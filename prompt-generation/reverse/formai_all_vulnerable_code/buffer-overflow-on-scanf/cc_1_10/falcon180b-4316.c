//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    char line[1000];
    char token[MAX_WORD_LENGTH];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i, j, k;

    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *tokenStart = line;
        while ((tokenStart = strtok_r(tokenStart, " \t\r\n", &tokenStart))!= NULL) {
            if (numWords >= MAX_WORDS) {
                break;
            }
            strcpy(words[numWords].word, tokenStart);
            words[numWords].count = 1;
            numWords++;
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    fprintf(outputFile, "The most common words are:\n");
    for (i = 0; i < numWords; i++) {
        if (words[i].count > 1) {
            fprintf(outputFile, "%s: %d\n", words[i].word, words[i].count);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}