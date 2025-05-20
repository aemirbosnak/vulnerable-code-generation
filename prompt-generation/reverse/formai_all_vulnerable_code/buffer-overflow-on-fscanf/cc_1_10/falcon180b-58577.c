//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char *english;
    char *cat;
} Word;

int main() {
    Word words[MAX_WORDS];
    int numWords = 0;
    char input[MAX_WORD_LENGTH];
    char *token;

    // Load dictionary
    FILE *dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    while (fscanf(dictFile, "%s %s\n", input, input) == 2) {
        if (numWords == MAX_WORDS) {
            printf("Error: dictionary too large.\n");
            return 1;
        }
        words[numWords].english = strdup(input);
        words[numWords].cat = strdup(input);
        numWords++;
    }

    fclose(dictFile);

    // Get user input
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);
    token = strtok(input, " ");

    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].cat);
                break;
            }
        }
        if (i == numWords) {
            printf("Unknown word: %s\n", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}