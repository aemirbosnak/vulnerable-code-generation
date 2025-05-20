//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: active
/*
 * C Spell Checker
 *
 * This program takes a sentence as input and checks it for spelling errors.
 * If an error is found, it suggests the correct spelling.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Structure to represent a word in the dictionary
typedef struct {
    char word[20];
    bool is_correct;
} word_t;

// Dictionary of valid words
word_t dictionary[] = {
    {"hello", true},
    {"world", true},
    {"my", true},
    {"name", true},
    {"is", true},
    {"john", true},
    {"doe", true},
    {"what", true},
    {"is", true},
    {"your", true},
    {"name", true},
    {"?", true}
};

// Function to check if a word is in the dictionary
bool is_in_dictionary(char *word) {
    int i;
    for (i = 0; i < sizeof(dictionary) / sizeof(word_t); i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return true;
        }
    }
    return false;
}

// Function to suggest a correct spelling for a word
void suggest_spelling(char *word) {
    int i;
    for (i = 0; i < sizeof(dictionary) / sizeof(word_t); i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            printf("Did you mean '%s'?\n", dictionary[i].word);
            return;
        }
    }
    printf("I don't know the word '%s'.\n", word);
}

int main() {
    char word[20];
    printf("Enter a sentence: ");
    fgets(word, 20, stdin);
    word[strlen(word) - 1] = '\0'; // remove newline character

    // Check if the word is in the dictionary
    if (is_in_dictionary(word)) {
        printf("The word '%s' is spelled correctly.\n", word);
    } else {
        suggest_spelling(word);
    }
    return 0;
}