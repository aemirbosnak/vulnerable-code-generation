//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[MAX_SENTENCE_LENGTH], outputFileName[MAX_SENTENCE_LENGTH];
    char sentence[MAX_SENTENCE_LENGTH];
    int numWords, i;
    WordCount wordCounts[26]; // assuming English alphabet

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
        fclose(inputFile);
        exit(1);
    }

    for (i = 0; i < 26; i++) {
        wordCounts[i].count = 0;
    }

    while (fgets(sentence, MAX_SENTENCE_LENGTH, inputFile)!= NULL) {
        numWords = 0;
        int wordLength;

        char *token = strtok(sentence, " ");
        while (token!= NULL) {
            wordLength = strlen(token);
            if (wordLength > MAX_WORD_LENGTH) {
                printf("Error: word '%s' is too long.\n", token);
                exit(1);
            }

            strcpy(wordCounts[token[0] - 'a'].word, token);
            wordCounts[token[0] - 'a'].count++;

            numWords++;
            token = strtok(NULL, " ");
        }

        if (numWords == 0) {
            printf("Error: empty sentence.\n");
            exit(1);
        }
    }

    for (i = 0; i < 26; i++) {
        fprintf(outputFile, "%c: %s (%d)\n", i + 'a', wordCounts[i].word, wordCounts[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}