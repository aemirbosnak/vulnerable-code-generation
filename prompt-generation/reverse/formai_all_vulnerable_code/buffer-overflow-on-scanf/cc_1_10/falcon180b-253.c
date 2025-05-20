//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

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
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    WordCount words[MAX_WORDS];

    printf("Enter the input file name: ");
    scanf("%s", inputFileName);
    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            int i;
            for (i = 0; i < strlen(token); i++) {
                if (!isalpha(token[i])) {
                    token[i] = '\0';
                    break;
                }
            }
            strcpy(word, token);
            WordCount *wc = bsearch(word, words, wordCount, sizeof(WordCount), compareWords);
            if (wc == NULL) {
                if (wordCount >= MAX_WORDS) {
                    printf("Error: too many unique words.\n");
                    exit(1);
                }
                strcpy(words[wordCount].word, word);
                words[wordCount].count = 1;
                wordCount++;
            } else {
                wc->count++;
            }
            token = strtok(NULL, ",.!?;:");
        }
    }

    qsort(words, wordCount, sizeof(WordCount), compareWords);

    fprintf(outputFile, "Word count:\n");
    for (int i = 0; i < wordCount; i++) {
        fprintf(outputFile, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}