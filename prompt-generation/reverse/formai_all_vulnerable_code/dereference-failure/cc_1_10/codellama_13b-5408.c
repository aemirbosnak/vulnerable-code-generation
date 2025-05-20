//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

int main() {
    char word[MAX_WORD_LENGTH];
    char sentence[MAX_SENTENCE_LENGTH];
    int word_count = 0;
    int i, j;

    // Read the sentence
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Tokenize the sentence into words
    for (i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            word_count++;
        }
    }
    word_count++;

    // Allocate memory for the words
    char **words = malloc(word_count * sizeof(char *));
    for (i = 0; i < word_count; i++) {
        words[i] = malloc(MAX_WORD_LENGTH * sizeof(char));
    }

    // Extract the words from the sentence
    i = 0;
    j = 0;
    while (sentence[i] != '\0') {
        if (sentence[i] != ' ') {
            words[j][i] = sentence[i];
            i++;
        } else {
            words[j][i] = '\0';
            j++;
            i++;
        }
    }
    words[j] = '\0';

    // Check the spelling of each word
    for (i = 0; i < word_count; i++) {
        // Check if the word is a palindrome
        if (is_palindrome(words[i])) {
            printf("%s is a palindrome.\n", words[i]);
        } else {
            printf("%s is not a palindrome.\n", words[i]);
        }
    }

    // Free memory
    for (i = 0; i < word_count; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}

int is_palindrome(char *word) {
    int i, j;
    for (i = 0, j = strlen(word) - 1; i < j; i++, j--) {
        if (word[i] != word[j]) {
            return 0;
        }
    }
    return 1;
}