//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LEN 20

// Function to check if a word is in the dictionary
int is_in_dict(char *word, char **dict, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, dict[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Function to suggest a word
char *suggest_word(char *word, char **dict, int num_words) {
    // Try to find a word with one character different
    for (int i = 0; i < num_words; i++) {
        int num_diffs = 0;

        for (int j = 0; j < WORD_LEN; j++) {
            if (word[j] != dict[i][j]) {
                num_diffs++;

                if (num_diffs > 1) {
                    break;
                }
            }
        }

        if (num_diffs == 1) {
            return dict[i];
        }
    }

    // Try to find a word with two characters different
    for (int i = 0; i < num_words; i++) {
        int num_diffs = 0;

        for (int j = 0; j < WORD_LEN; j++) {
            if (word[j] != dict[i][j]) {
                num_diffs++;

                if (num_diffs > 2) {
                    break;
                }
            }
        }

        if (num_diffs == 2) {
            return dict[i];
        }
    }

    return NULL;
}

int main() {
    // Load the dictionary
    char *dict[] = {"apple", "banana", "cherry", "dog", "elephant", "fish", "grape", "horse", "ice cream", "juice"};
    int num_words = sizeof(dict) / sizeof(char *);

    // Get the word to be checked
    char word[WORD_LEN];
    printf("Enter a word: ");
    scanf("%s", word);

    // Convert the word to lowercase
    for (int i = 0; i < WORD_LEN; i++) {
        word[i] = tolower(word[i]);
    }

    // Check if the word is in the dictionary
    if (is_in_dict(word, dict, num_words)) {
        printf("The word is spelled correctly.\n");
    } else {
        // Suggest a word
        char *suggested_word = suggest_word(word, dict, num_words);

        if (suggested_word != NULL) {
            printf("The word is misspelled. Did you mean '%s'?\n", suggested_word);
        } else {
            printf("The word is misspelled. I cannot suggest a correction.\n");
        }
    }

    return 0;
}