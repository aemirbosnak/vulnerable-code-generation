//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_STR_LEN 1024
#define MAX_WORD_LEN 256

// Function to check if a given string is a palindrome
bool is_palindrome(const char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to reverse a given string
char *reverse_string(char *str) {
    size_t len = strlen(str);
    char *rev = malloc(len * sizeof(char));
    for (size_t i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    return rev;
}

// Function to check if a given word is a palindrome
bool is_word_palindrome(const char *word) {
    size_t len = strlen(word);
    for (size_t i = 0; i < len; i++) {
        if (word[i] != word[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    // Initialize a list of words
    char **word_list = malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++) {
        word_list[i] = malloc(MAX_WORD_LEN * sizeof(char));
        gets(word_list[i]);
    }

    // Loop through the list of words and check if they are palindromes
    for (int i = 0; i < 10; i++) {
        if (is_word_palindrome(word_list[i])) {
            printf("%s is a palindrome\n", word_list[i]);
        } else {
            printf("%s is not a palindrome\n", word_list[i]);
        }
    }

    // Free the memory allocated for the word list
    for (int i = 0; i < 10; i++) {
        free(word_list[i]);
    }
    free(word_list);

    return 0;
}