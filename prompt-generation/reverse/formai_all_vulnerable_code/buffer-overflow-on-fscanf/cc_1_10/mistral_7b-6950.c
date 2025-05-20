//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_FILE "dictionary.txt"

typedef struct Word {
    char word[MAX_WORD_LENGTH];
} Word;

void loadDictionary(Word **dictionary, int *numWords);
void unloadDictionary(Word *dictionary, int numWords);
int isWordInDictionary(Word *dictionary, int numWords, char *word);
int checkSpelling(char *input, Word *dictionary, int numWords);

int main() {
    Word *dictionary = NULL;
    int numWords = 0;
    loadDictionary(&dictionary, &numWords);

    char input[100];
    printf("Enter a string to check spelling: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    int numErrors = checkSpelling(input, dictionary, numWords);
    printf("Spelling check result: %d errors found.\n", numErrors);

    unloadDictionary(dictionary, numWords);
    return 0;
}

void loadDictionary(Word **dictionary, int *numWords) {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (!file) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", (*dictionary)->word) != EOF) {
        (*dictionary)++;
        numWords++;
        if ((*dictionary) >= (Word *)calloc(numWords + 1, sizeof(Word))) {
            printf("Error: Failed to allocate memory for dictionary.\n");
            exit(1);
        }
    }
    fclose(file);
}

void unloadDictionary(Word *dictionary, int numWords) {
    free(dictionary);
}

int isWordInDictionary(Word *dictionary, int numWords, char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

int checkSpelling(char *input, Word *dictionary, int numWords) {
    int numErrors = 0;
    char *token = strtok(input, " ");

    while (token != NULL) {
        int found = isWordInDictionary(dictionary, numWords, token);
        if (!found) {
            numErrors++;
            printf("Error: '%s' is not a valid word.\n", token);
        }
        token = strtok(NULL, " ");
    }
    return numErrors;
}