//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: puzzling
// Puzzling Spell Checker

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 20

// Function to check if a word is in the dictionary
bool is_word(char *word) {
    // Dictionary is hardcoded for simplicity
    char *dictionary[] = {"cat", "dog", "elephant", "fox", "jump"};
    for (int i = 0; i < sizeof(dictionary) / sizeof(char *); i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to check if a word is a valid spelling
bool is_spelling(char *word) {
    // Check if the word is in the dictionary
    if (is_word(word)) {
        return true;
    }

    // Check if the word is a palindrome
    char rev_word[MAX_WORD_LEN];
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        rev_word[i] = word[len - i - 1];
    }
    rev_word[len] = '\0';
    if (strcmp(word, rev_word) == 0) {
        return true;
    }

    // Check if the word is a permutation of a palindrome
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (word[i] == word[j]) {
                return true;
            }
        }
    }

    return false;
}

// Driver function to test the functions
int main() {
    char word[MAX_WORD_LEN];
    printf("Enter a word: ");
    scanf("%s", word);
    if (is_spelling(word)) {
        printf("The word is a valid spelling.\n");
    } else {
        printf("The word is not a valid spelling.\n");
    }
    return 0;
}