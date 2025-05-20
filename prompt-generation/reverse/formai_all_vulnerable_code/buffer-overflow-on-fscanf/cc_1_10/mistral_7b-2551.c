//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define WORD_COUNT 1000

// Function to check if a character is an alphabet or not
int is_alphabet(char c) {
    return (isalpha(c) != 0);
}

// Function to check if a word is present in the dictionary or not
int is_valid_word(char* word) {
    FILE* dict = fopen("dictionary.txt", "r");
    int found = 0;
    char dictionary_word[MAX_WORD_LENGTH];

    while (fscanf(dict, "%s", dictionary_word) != EOF) {
        if (strcmp(dictionary_word, word) == 0) {
            found = 1;
            break;
        }
    }

    fclose(dict);
    return found;
}

// Function to remove spaces from a string
void remove_spaces(char* str) {
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (isalnum(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }

    str[j] = '\0';
}

// Function to check if a given word is spelled correctly
void check_word(char* word) {
    int i, flag = 1;

    for (i = 0; word[i] != '\0'; i++) {
        if (!is_alphabet(word[i])) {
            if (word[i] == '\'' && is_alphabet(word[i + 1])) {
                i++;
                continue;
            }

            printf("Error at position %d: '%c' is not an alphabet.\n", i + 1, word[i]);
            flag = 0;
            break;
        }
    }

    if (flag) {
        if (!is_valid_word(word)) {
            printf("Warning: '%s' is not a valid word.\n", word);
        }
    }
}

int main() {
    int i, word_count = 0;
    char words[WORD_COUNT][MAX_WORD_LENGTH];

    printf("Welcome to the Spell Checker!\n");

    while (1) {
        printf("Enter a word (or type 'quit' to exit): ");
        scanf("%s", words[word_count]);

        remove_spaces(words[word_count]);

        if (strcmp(words[word_count], "quit") == 0) {
            break;
        }

        check_word(words[word_count]);
        word_count++;
    }

    printf("Spell checking completed.\n");

    return 0;
}