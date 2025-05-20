//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

// Structure to store a word and its translation
typedef struct {
    char english[MAX_WORD_LEN];
    char alien[MAX_WORD_LEN];
} Word;

int main() {
    FILE *dictFile;
    Word dict[MAX_WORDS];
    int numWords = 0;
    char line[MAX_WORD_LEN];

    // Open the dictionary file
    dictFile = fopen("dict.txt", "r");
    if (dictFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    // Read in the words and translations
    while (fgets(line, MAX_WORD_LEN, dictFile)!= NULL) {
        // Split the line into two parts: English word and alien translation
        char *token = strtok(line, " ");
        strcpy(dict[numWords].english, token);
        token = strtok(NULL, " ");
        strcpy(dict[numWords].alien, token);
        numWords++;
    }

    // Close the dictionary file
    fclose(dictFile);

    // Begin translation
    char sentence[MAX_WORD_LEN];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_WORD_LEN, stdin);

    // Split the sentence into words
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        // Check if the word is in the dictionary
        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(token, dict[i].english) == 0) {
                // Word found, print the translation
                printf("%s ", dict[i].alien);
                found = 1;
                break;
            }
        }
        if (!found) {
            // Word not found, print an error message
            printf("Error: %s not found in dictionary.\n", token);
        }
        // Move to the next word
        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}