//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100

void check_spelling(char *word) {
    // Declare variables
    int i, j, k;
    char *dictionary[MAX_WORD_LENGTH];
    bool is_word = false;

    // Load dictionary
    FILE *fp = fopen("dictionary.txt", "r");
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        fscanf(fp, "%s", dictionary[i]);
    }
    fclose(fp);

    // Check if word is in dictionary
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            is_word = true;
            break;
        }
    }

    // Print result
    if (is_word) {
        printf("The word '%s' is spelled correctly.\n", word);
    } else {
        printf("The word '%s' is not spelled correctly.\n", word);
    }
}

int main() {
    // Declare variables
    char word[MAX_WORD_LENGTH];

    // Get word from user
    printf("Enter a word: ");
    fgets(word, MAX_WORD_LENGTH, stdin);

    // Remove newline character from input
    word[strcspn(word, "\n")] = '\0';

    // Check spelling
    check_spelling(word);

    return 0;
}