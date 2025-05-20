//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Global variables
bool is_capitalized;
bool is_lowercase;
bool is_uppercase;
bool is_digit;
bool is_alphanumeric;
bool is_whitespace;
bool is_punctuation;
bool is_word;

// Function prototypes
void check_word(char *word);
void check_word_case(char *word);
void check_word_length(char *word);
void check_word_punctuation(char *word);
void check_word_whitespace(char *word);
void check_word_alphanumeric(char *word);
void check_word_digit(char *word);

int main() {
    char word[50];
    printf("Enter a word: ");
    scanf("%s", word);

    check_word_case(word);
    check_word_length(word);
    check_word_punctuation(word);
    check_word_whitespace(word);
    check_word_alphanumeric(word);
    check_word_digit(word);

    return 0;
}

void check_word_case(char *word) {
    is_capitalized = (toupper(word[0])!= word[0]);
    is_lowercase = (tolower(word[0])!= word[0]);
    is_uppercase = (toupper(word[0]) == word[0]);
    printf("Case of first character: %s\n", (is_capitalized? "Uppercase" : (is_lowercase? "Lowercase" : "Mixed case")));
}

void check_word_length(char *word) {
    int length = strlen(word);
    printf("Length of word: %d\n", length);
}

void check_word_punctuation(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            is_punctuation = true;
            break;
        }
    }
    printf("Punctuation in word: %s\n", (is_punctuation? "Yes" : "No"));
}

void check_word_whitespace(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (isspace(word[i])) {
            is_whitespace = true;
            break;
        }
    }
    printf("Whitespace in word: %s\n", (is_whitespace? "Yes" : "No"));
}

void check_word_alphanumeric(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (isalnum(word[i])) {
            is_alphanumeric = true;
            break;
        }
    }
    printf("Alphanumeric in word: %s\n", (is_alphanumeric? "Yes" : "No"));
}

void check_word_digit(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (isdigit(word[i])) {
            is_digit = true;
            break;
        }
    }
    printf("Digit in word: %s\n", (is_digit? "Yes" : "No"));
}