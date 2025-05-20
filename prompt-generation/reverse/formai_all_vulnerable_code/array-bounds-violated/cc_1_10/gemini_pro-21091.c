//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 30

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

// Initialize the dictionary
int init_dictionary(Word dictionary[], char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    int count = 0;
    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, MAX_WORD_LENGTH + 1, fp) != NULL) {
        // Remove the newline character
        line[strlen(line) - 1] = '\0';

        // Copy the word into the dictionary
        strcpy(dictionary[count].word, line);

        // Increment the word count
        dictionary[count].count = 0;

        count++;
    }

    fclose(fp);

    return count;
}

int main() {
    // Initialize the dictionary
    Word dictionary[MAX_WORDS];
    int num_words = init_dictionary(dictionary, "dictionary.txt");
    if (num_words == -1) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    // Get the input text
    char text[1000];
    printf("Enter the text you want to check for spelling errors:\n");
    fgets(text, 1000, stdin);

    // Tokenize the input text
    char *tokens[100];
    int num_tokens = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Check for spelling errors
    int num_errors = 0;
    for (int i = 0; i < num_tokens; i++) {
        // Convert the token to lowercase
        for (int j = 0; j < strlen(tokens[i]); j++) {
            tokens[i][j] = tolower(tokens[i][j]);
        }

        // Check if the token is in the dictionary
        int found = 0;
        for (int j = 0; j < num_words; j++) {
            if (strcmp(tokens[i], dictionary[j].word) == 0) {
                found = 1;
                break;
            }
        }

        // If the token is not in the dictionary, increment the error count
        if (!found) {
            num_errors++;
        }
    }

    // Print the results
    if (num_errors == 0) {
        printf("Yay! Your text has no spelling errors.\n");
    } else {
        printf("Oops! Your text has %d spelling errors.\n", num_errors);
    }

    return 0;
}