//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50
#define SPAM_THRESHOLD 0.8

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordCount;

int main() {
    FILE *inputFile;
    char line[1024];
    char word[MAX_WORD_LENGTH + 1];
    int numWords = 0;
    WordCount *wordCounts = malloc(MAX_WORDS * sizeof(WordCount));

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *token;
        char *saveptr = NULL;

        token = strtok_r(line, " \t\r\n", &saveptr);
        while (token!= NULL) {
            if (strlen(token) > 0) {
                if (numWords >= MAX_WORDS) {
                    printf("Maximum number of words reached.\n");
                    exit(1);
                }
                strcpy(wordCounts[numWords].word, token);
                wordCounts[numWords].count = 1;
                numWords++;
            }
            token = strtok_r(NULL, " \t\r\n", &saveptr);
        }
    }

    fclose(inputFile);

    int numSpamWords = 0;
    for (int i = 0; i < numWords; i++) {
        if (wordCounts[i].count > SPAM_THRESHOLD * numWords) {
            printf("%s (%d)\n", wordCounts[i].word, wordCounts[i].count);
            numSpamWords++;
        }
    }

    printf("Total spam words: %d\n", numSpamWords);

    free(wordCounts);
    return 0;
}