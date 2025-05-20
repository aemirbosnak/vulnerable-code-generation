//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

int main() {
    // Create an array to store the words in the dictionary
    Word dictionary[MAX_WORDS];

    // Read the words from the dictionary file
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        return EXIT_FAILURE;
    }
    int numWords = 0;
    while (fscanf(fp, "%s", dictionary[numWords].word) != EOF) {
        dictionary[numWords].count = 0;
        numWords++;
    }
    fclose(fp);

    // Sort the dictionary
    qsort(dictionary, numWords, sizeof(Word), compareWords);

    // Create an array to store the words in the text file
    char text[100000];

    // Read the words from the text file
    fp = fopen("text.txt", "r");
    if (fp == NULL) {
        perror("Error opening text file");
        return EXIT_FAILURE;
    }
    fscanf(fp, "%s", text);
    fclose(fp);

    // Tokenize the text
    char *tokens[MAX_WORDS];
    int numTokens = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[numTokens++] = token;
        token = strtok(NULL, " ");
    }

    // Check each word in the text for spelling errors
    for (int i = 0; i < numTokens; i++) {
        // Convert the word to lowercase
        for (int j = 0; j < strlen(tokens[i]); j++) {
            tokens[i][j] = tolower(tokens[i][j]);
        }

        // Check if the word is in the dictionary
        int found = 0;
        for (int j = 0; j < numWords; j++) {
            if (strcmp(tokens[i], dictionary[j].word) == 0) {
                found = 1;
                break;
            }
        }

        // If the word is not in the dictionary, print it as a spelling error
        if (!found) {
            printf("%s is a spelling error\n", tokens[i]);
        }
    }

    return EXIT_SUCCESS;
}