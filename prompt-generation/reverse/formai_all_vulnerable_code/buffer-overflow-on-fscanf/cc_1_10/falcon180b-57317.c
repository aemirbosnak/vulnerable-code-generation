//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    FILE *dictionaryFile;
    WordTranslation dictionary[MAX_WORDS];
    int numWords = 0;
    char input[MAX_WORD_LENGTH];
    char *token;

    // Open the dictionary file
    dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    // Read the dictionary into memory
    while (fscanf(dictionaryFile, "%s %s", dictionary[numWords].word, dictionary[numWords].translation) == 2) {
        numWords++;
        if (numWords == MAX_WORDS) {
            printf("Error: dictionary is too large.\n");
            fclose(dictionaryFile);
            return 1;
        }
    }
    fclose(dictionaryFile);

    // Prompt the user for input
    printf("Enter a phrase to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    // Tokenize the input
    token = strtok(input, " ");
    while (token!= NULL) {
        // Look up each word in the dictionary
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, dictionary[i].word) == 0) {
                printf("%s -> %s\n", token, dictionary[i].translation);
                break;
            }
        }
        // If the word is not found, indicate an error
        if (i == numWords) {
            printf("Error: unknown word '%s'.\n", token);
        }
        // Move on to the next word
        token = strtok(NULL, " ");
    }

    return 0;
}