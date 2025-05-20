//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} Word;

int main() {
    FILE *dictFile;
    Word dict[MAX_WORDS];
    int numWords = 0;
    char line[100];
    char *word;

    // Read dictionary file
    dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    // Fill dictionary array
    while (fgets(line, sizeof(line), dictFile)!= NULL) {
        word = strtok(line, " ");
        strcpy(dict[numWords].english, word);
        word = strtok(NULL, " ");
        strcpy(dict[numWords].cat, word);
        numWords++;
    }
    fclose(dictFile);

    // Main loop
    char input[100];
    while (1) {
        printf("Enter a sentence to translate: ");
        fgets(input, sizeof(input), stdin);

        // Tokenize input
        char *token = strtok(input, " ");
        while (token!= NULL) {
            // Check if word is in dictionary
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(token, dict[i].english) == 0) {
                    // Found match, print cat translation
                    printf("%s ", dict[i].cat);
                    break;
                }
            }
            if (i == numWords) {
                // Word not found, print original word
                printf("%s ", token);
            }
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    return 0;
}