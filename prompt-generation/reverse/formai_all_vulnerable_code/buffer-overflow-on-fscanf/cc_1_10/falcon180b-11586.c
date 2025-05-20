//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} Word;

int main() {
    FILE *dictFile;
    Word dict[MAX_WORDS];
    int numWords = 0;
    char input[MAX_WORD_LENGTH];

    // Open dictionary file
    dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    // Read words from dictionary file
    while (fscanf(dictFile, "%s %s\n", dict[numWords].english, dict[numWords].cat)!= EOF) {
        numWords++;
        if (numWords >= MAX_WORDS) {
            printf("Error: Dictionary is too large.\n");
            fclose(dictFile);
            return 1;
        }
    }
    fclose(dictFile);

    // Get user input
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Split input into words
    char *word = strtok(input, " ");
    while (word!= NULL) {
        // Check if word is in dictionary
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, dict[i].english) == 0) {
                // Word found, print translation
                printf("%s ", dict[i].cat);
            }
        }
        if (i == numWords) {
            // Word not found, print error message
            printf("Error: Unknown word '%s'.\n", word);
        }
        word = strtok(NULL, " ");
    }

    return 0;
}