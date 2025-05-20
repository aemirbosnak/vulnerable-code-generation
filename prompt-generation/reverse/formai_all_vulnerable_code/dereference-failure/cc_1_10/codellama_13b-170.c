//Code Llama-13B DATASET v1.0 Category: Spell checking ; Style: innovative
/*
 * Unique C Spell Checking Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_DICT_SIZE 1000

// Function to check if a word is in the dictionary
int is_word_in_dict(const char *word, const char *dict[], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dict[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a word is valid
int is_word_valid(const char *word) {
    if (strlen(word) == 0) {
        return 0;
    }
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to spell check a sentence
int spell_check(const char *sentence, const char *dict[]) {
    int dict_size = sizeof(dict) / sizeof(dict[0]);
    char *words[MAX_WORD_LEN];
    int num_words = 0;

    // Split the sentence into words
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[num_words] = token;
        num_words++;
        token = strtok(NULL, " ");
    }

    // Check each word in the sentence
    for (int i = 0; i < num_words; i++) {
        if (!is_word_valid(words[i])) {
            return 0;
        }
        if (!is_word_in_dict(words[i], dict, dict_size)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    // Test the spell checker
    const char *dict[] = {"hello", "world", "c", "program", "spell", "checking", "example", "unique", "innovative"};
    const char *sentence = "This is a unique C programming example that demonstrates innovative spell checking.";
    int result = spell_check(sentence, dict);
    if (result == 1) {
        printf("Spell check successful.\n");
    } else {
        printf("Spell check failed.\n");
    }
    return 0;
}