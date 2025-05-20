//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    FILE *dictionaryFile;
    char line[MAX_WORD_LENGTH];
    WordTranslation dictionary[MAX_WORDS];
    int numWords = 0;
    int i;

    // Open dictionary file
    dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    // Read words and translations from file
    while (fscanf(dictionaryFile, "%s %s", line, dictionary[numWords].translation)!= EOF) {
        strcpy(dictionary[numWords].word, line);
        numWords++;
        if (numWords == MAX_WORDS) {
            printf("Dictionary file is too large.\n");
            return 1;
        }
    }

    // Close dictionary file
    fclose(dictionaryFile);

    // Prompt user for input
    printf("Enter a sentence to translate:\n");
    fgets(line, MAX_WORD_LENGTH, stdin);

    // Remove newline character from input
    line[strcspn(line, "\n")] = '\0';

    // Translate sentence
    for (i = 0; i < numWords; i++) {
        int j = 0;
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (strcmp(token, dictionary[i].word) == 0) {
                strcpy(token, dictionary[i].translation);
            }
            token = strtok(NULL, " ");
        }
    }

    // Print translated sentence
    printf("Translated sentence: %s\n", line);

    return 0;
}