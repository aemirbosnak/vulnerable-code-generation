//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file.\n");
        return 1;
    }

    Word words[MAX_WORDS];
    int numWords = 0;

    char currentWord[WORD_LENGTH];

    while (fscanf(file, " %s", currentWord) != EOF) {
        toLower(currentWord);
        int found = 0;

        for (int i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, currentWord) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[numWords].word, currentWord);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(file);

    printf("Word frequencies:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}