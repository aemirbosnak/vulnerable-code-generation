//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_SENTENCES 1000
#define MAX_WORDS 5000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *inputFile;
    char input[MAX_SENTENCES][MAX_WORD_LENGTH];
    int numSentences = 0;
    int numWords = 0;
    WordCount wordCounts[MAX_WORDS];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Read input file
    while (fscanf(inputFile, "%s", input[numSentences])!= EOF) {
        numSentences++;
        if (numSentences >= MAX_SENTENCES) {
            printf("Error: maximum number of sentences exceeded.\n");
            fclose(inputFile);
            return 2;
        }
    }

    // Count words
    for (int i = 0; i < numSentences; i++) {
        char *token = strtok(input[i], " ");
        while (token!= NULL) {
            numWords++;
            if (numWords >= MAX_WORDS) {
                printf("Error: maximum number of words exceeded.\n");
                fclose(inputFile);
                return 3;
            }
            WordCount *word = NULL;
            for (int j = 0; j < numWords; j++) {
                if (strcmp(wordCounts[j].word, token) == 0) {
                    wordCounts[j].count++;
                    word = &wordCounts[j];
                    break;
                }
            }
            if (word == NULL) {
                strcpy(wordCounts[numWords].word, token);
                wordCounts[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, " ");
        }
    }

    // Print word counts
    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }

    fclose(inputFile);
    return 0;
}