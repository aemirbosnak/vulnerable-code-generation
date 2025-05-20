//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *english;
    char *cat;
} Word;

int main() {
    char input[MAX_WORD_LENGTH];
    char *token;
    FILE *dictFile;
    Word words[MAX_WORDS];
    int numWords = 0;

    // Load dictionary file
    dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    // Read words from dictionary file
    while (fscanf(dictFile, "%s %s\n", input, input) == 2) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Dictionary file is too large.\n");
            fclose(dictFile);
            return 1;
        }
        words[numWords++] = (Word) {.english = strdup(input),.cat = strdup(input)};
    }
    fclose(dictFile);

    // Get user input
    printf("Enter a sentence in English:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    // Translate input to Cat
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
            printf("Error: Unknown word '%s'.\n", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}