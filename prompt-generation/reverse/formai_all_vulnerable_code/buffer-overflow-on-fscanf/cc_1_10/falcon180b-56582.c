//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

int main() {
    FILE *dictFile;
    WordPair dict[MAX_WORDS];
    int numWords = 0;
    char input[MAX_WORD_LENGTH];
    char *token;
    int i;

    // Open dictionary file
    dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    // Read in dictionary
    while (fscanf(dictFile, "%s %s", dict[numWords].word, dict[numWords].translation)!= EOF) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Error: dictionary too large.\n");
            return 1;
        }
    }

    // Close dictionary file
    fclose(dictFile);

    // Translate input
    printf("Enter text to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    token = strtok(input, " ");
    while (token!= NULL) {
        for (i = 0; i < numWords; i++) {
            if (strcmp(dict[i].word, token) == 0) {
                printf("%s ", dict[i].translation);
                break;
            }
        }
        if (i == numWords) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}