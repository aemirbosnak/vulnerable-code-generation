//Falcon-180B DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    char text[MAX_TEXT_LENGTH];
    WordCount words[MAX_WORD_LENGTH];
    int numWords = 0;
    int i, j;

    // Read in the text
    printf("Enter some text: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    // Remove trailing newline character
    if (text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }

    // Tokenize the text into words
    char *token = strtok(text, ",.?!;:");
    while (token!= NULL) {
        // Convert the word to lowercase
        for (i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        // Check if the word is already in the array
        for (j = 0; j < numWords; j++) {
            if (strcmp(words[j].word, token) == 0) {
                // Word already exists, increment count
                words[j].count++;
                break;
            }
        }

        // Word not found, add to array
        if (j == numWords) {
            strcpy(words[numWords].word, token);
            words[numWords].count = 1;
            numWords++;
        }

        // Get next token
        token = strtok(NULL, ",.?!;:");
    }

    // Print out the word counts
    printf("Word counts:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}