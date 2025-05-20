//FormAI DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void check_word(char *word) {
    int len = strlen(word);
    int i, valid = 1;

    // Check if word contains any non-alphabetic characters
    for (i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            valid = 0;
            break;
        }
    }

    if (valid) {
        // Check if word is spelled correctly
        char *dictionary[] = {"apple", "banana", "cherry", "orange", "peach"};
        int num_words = 5;

        for (i = 0; i < num_words; i++) {
            if (strcasecmp(word, dictionary[i]) == 0) {
                printf("The word %s is spelled correctly!\n", word);
                return;
            }
        }

        printf("The word %s is spelled incorrectly. Perhaps you meant:\n", word);

        // Find and suggest similar words
        for (i = 0; i < num_words; i++) {
            if (strcasestr(dictionary[i], word)) {
                printf("- %s\n", dictionary[i]);
            }
        }
    } else {
        printf("The word %s contains non-alphabetic characters.\n", word);
    }
}

int main() {
    printf("Welcome to the Cheerful Spell Checker!\n");
    printf("Type in a word to check its spelling. Type 'quit' to exit.\n");

    while (1) {
        char input[100];
        printf("> ");
        fgets(input, 100, stdin);

        int len = strlen(input);

        // Remove trailing newline character
        if (input[len-1] == '\n') {
            input[len-1] = '\0';
        }

        // Check if user wants to quit
        if (strcasecmp(input, "quit") == 0) {
            printf("Goodbye! Happy spelling!\n");
            break;
        }

        check_word(input);
    }

    return 0;
}