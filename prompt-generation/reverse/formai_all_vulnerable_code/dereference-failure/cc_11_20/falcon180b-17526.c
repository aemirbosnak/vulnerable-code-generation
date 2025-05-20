//Falcon-180B DATASET v1.0 Category: Text processing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_COUNT 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char word[MAX_LINE_LENGTH];
    WordCount wordCounts[MAX_WORD_COUNT];
    int numWords = 0;

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        int wordCount = 0;
        char *token;
        token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);
            for (int i = 0; i < strlen(word); i++) {
                if (isalpha(word[i])) {
                    word[i] = tolower(word[i]);
                } else {
                    word[i] = '\0';
                }
            }
            int found = 0;
            for (int j = 0; j < numWords; j++) {
                if (strcmp(word, wordCounts[j].word) == 0) {
                    wordCounts[j].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                if (numWords >= MAX_WORD_COUNT) {
                    printf("Error: reached maximum word count.\n");
                    return 1;
                }
                strcpy(wordCounts[numWords].word, word);
                wordCounts[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(inputFile);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}