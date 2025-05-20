//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: grateful
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
    FILE *dictFile;
    Word words[MAX_WORDS];
    int numWords = 0;

    // Load dictionary
    dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }
    while (fscanf(dictFile, "%s %s\n", words[numWords].english, words[numWords].cat)!= EOF) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Error: Dictionary is too large.\n");
            fclose(dictFile);
            return 1;
        }
    }
    fclose(dictFile);

    // Get user input
    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    // Tokenize input
    char *token = strtok(input, " ");
    while (token!= NULL) {
        // Look up word in dictionary
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].english) == 0) {
                // Found match, translate and print
                printf("%s ", words[i].cat);
                break;
            }
        }
        if (i == numWords) {
            // No match found, print original word
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}