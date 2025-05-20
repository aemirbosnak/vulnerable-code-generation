//FormAI DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 30
#define MAX_DICT_WORDS 1000

char dictionary[MAX_DICT_WORDS][MAX_WORD_LEN];
int num_dict_words = 0;

void load_dictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        char word[MAX_WORD_LEN];
        while (fscanf(file, "%s", word) == 1 && num_dict_words < MAX_DICT_WORDS) {
            // Convert to lowercase
            for (int i = 0; word[i]; i++) {
                word[i] = tolower(word[i]);
            }

            // Copy word to dictionary
            strcpy(dictionary[num_dict_words++], word);
        }

        fclose(file);
    }
}

int spell_check(const char* word) {
    // Convert to lowercase
    char lowercase_word[MAX_WORD_LEN];
    for (int i = 0; word[i]; i++) {
        lowercase_word[i] = tolower(word[i]);
    }
    lowercase_word[strlen(word)] = '\0';

    // Check if in dictionary
    for (int i = 0; i < num_dict_words; i++) {
        if (strcmp(lowercase_word, dictionary[i]) == 0) {
            return 1;
        }
    }

    printf("Oops, it seems '%s' is not a valid word!\n", word);
    return 0;
}

int main() {
    load_dictionary("dictionary.txt");

    printf("Welcome to Spell Checker 3000!\n\n");

    char input[MAX_WORD_LEN];
    printf("Enter a word to spell check (or 'QUIT' to exit):\n");
    while (scanf("%s", input) == 1 && strcmp(input, "QUIT") != 0) {
        spell_check(input);
        printf("\nEnter another word to spell check (or 'QUIT' to exit):\n");
    }

    printf("\nGoodbye!\n");

    return 0;
}