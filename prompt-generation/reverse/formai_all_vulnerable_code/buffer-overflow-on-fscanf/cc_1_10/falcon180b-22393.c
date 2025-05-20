//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    // Load dictionary
    WordTranslation dictionary[MAX_WORDS];
    int numWords = 0;
    FILE* dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }
    char line[MAX_WORD_LENGTH];
    while (fscanf(dictFile, "%s %s\n", line, line) == 2) {
        strcpy(dictionary[numWords].word, line);
        strcpy(dictionary[numWords].translation, line);
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Error: dictionary too large.\n");
            return 1;
        }
    }
    fclose(dictFile);

    // Prompt user for input
    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    // Tokenize input
    char* tokens[MAX_WORDS];
    int numTokens = 0;
    char* token = strtok(input, " ");
    while (token!= NULL) {
        tokens[numTokens++] = token;
        if (numTokens >= MAX_WORDS) {
            printf("Error: sentence too long.\n");
            return 1;
        }
        token = strtok(NULL, " ");
    }

    // Translate tokens
    for (int i = 0; i < numTokens; i++) {
        int found = 0;
        for (int j = 0; j < numWords; j++) {
            if (strcmp(tokens[i], dictionary[j].word) == 0) {
                printf("%s ", dictionary[j].translation);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s ", tokens[i]);
        }
    }

    printf("\n");

    return 0;
}