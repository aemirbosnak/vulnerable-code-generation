//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: active
/*
 * C Spell Checking Program
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// Global variables
const char* words[2000] = {"apple", "banana", "orange", "carrot", "potato", "tomato", "egg", "bread", "butter", "cheese"};
int num_words = 10;

// Function to check if a word is in the dictionary
bool is_word(const char* word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, words[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to check if a word is a palindrome
bool is_palindrome(const char* word) {
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[len - i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to check if a word is spelled correctly
bool is_spelled_correctly(const char* word) {
    if (is_word(word)) {
        return true;
    } else if (is_palindrome(word)) {
        return true;
    } else {
        return false;
    }
}

// Main function
int main() {
    char word[100];
    printf("Enter a word: ");
    scanf("%s", word);
    if (is_spelled_correctly(word)) {
        printf("The word '%s' is spelled correctly.\n", word);
    } else {
        printf("The word '%s' is not spelled correctly.\n", word);
    }
    return 0;
}