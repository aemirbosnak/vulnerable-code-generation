//Falcon-180B DATASET v1.0 Category: Database querying ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *) a;
    WordCount *wc2 = (WordCount *) b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    char input[MAX_WORD_LEN];
    char *word;
    char *token;
    FILE *inputFile;
    FILE *outputFile;
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fscanf(inputFile, "%s", input)!= EOF) {
        word = strtok(input, ",.!?;:");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Too many words.\n");
                exit(1);
            }
            strcpy(words[numWords].word, word);
            words[numWords].count = 0;
            numWords++;
            word = strtok(NULL, ",.!?;:");
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    fprintf(outputFile, "Word\tCount\n");
    for (i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\t%d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}