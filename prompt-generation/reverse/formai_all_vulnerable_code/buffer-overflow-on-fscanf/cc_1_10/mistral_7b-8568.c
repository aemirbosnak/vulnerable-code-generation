//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LEN 50

// Define a structure for word and its frequency
typedef struct {
    char word[WORD_LEN];
    int count;
} WordStat;

void toLower(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

int main() {
    FILE *file;
    char filename[100];
    WordStat wordStats[MAX_WORDS];

    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int numWords = 0;
    char currentWord[WORD_LEN];
    int currentWordLen = 0;

    while (fscanf(file, " %s", currentWord) != EOF) {
        toLower(currentWord);

        int wordIndex = -1;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(currentWord, wordStats[i].word) == 0) {
                wordIndex = i;
                break;
            }
        }

        if (wordIndex >= 0) {
            wordStats[wordIndex].count++;
        } else {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }
            strcpy(wordStats[numWords].word, currentWord);
            wordStats[numWords].count = 1;
            numWords++;
        }
    }

    fclose(file);

    printf("\nWord frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordStats[i].word, wordStats[i].count);
    }

    return 0;
}