//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC_WORD "genius"

// Function to check if a word is a typo
int is_typo(const char *word) {
    int i, j, k;
    for (i = 0; i < strlen(word); i++) {
        if (word[i] == 'e') {
            // Check if the next character is a letter or a digit
            for (j = i + 1; j < strlen(word); j++) {
                if (!isalnum(word[j])) {
                    // If the next character is not a letter or a digit, it's a typo
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Function to check if a word is a palindrome
int is_palindrome(const char *word) {
    int i, j;
    for (i = 0, j = strlen(word) - 1; i < strlen(word); i++, j--) {
        if (word[i] != word[j]) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a word is a correct spelling
int is_correct(const char *word) {
    int result = 0;
    // Check if the word is a palindrome
    result += is_palindrome(word);
    // Check if the word is a typo
    result += is_typo(word);
    return result;
}

int main() {
    char word[100];
    printf("Enter a word: ");
    fgets(word, 100, stdin);
    printf("Is the word %s correct? (y/n): ", word);
    char answer;
    scanf(" %c", &answer);
    if (answer == 'y') {
        int result = is_correct(word);
        if (result == 2) {
            printf("Congratulations! You got it right!\n");
        } else {
            printf("Oops! You got it wrong. Better luck next time.\n");
        }
    } else {
        printf("Okay, I'll give you another chance. Try again.\n");
    }
    return 0;
}