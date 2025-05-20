//Falcon-180B DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    char line[1000];
    char *word;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Too many words in input file.\n");
                fclose(inputFile);
                fclose(outputFile);
                exit(1);
            }

            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;

            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    fprintf(outputFile, "Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\t%d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}