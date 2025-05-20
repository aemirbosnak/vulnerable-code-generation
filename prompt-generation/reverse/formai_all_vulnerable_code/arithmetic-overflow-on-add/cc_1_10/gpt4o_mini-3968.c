//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 5000
#define DICTIONARY_FILE "dictionary.txt"

struct Dictionary {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count;
};

void load_dictionary(struct Dictionary *dict) {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dict->words[dict->count]) != EOF) {
        dict->count++;
    }

    fclose(file);
}

int is_word_in_dictionary(char *word, struct Dictionary *dict) {
    for (int i = 0; i < dict->count; i++) {
        if (strcasecmp(word, dict->words[i]) == 0) {
            return 1; // Found the word
        }
    }
    return 0; // Word not found
}

void print_suggestions(char *word, struct Dictionary *dict) {
    printf("Suggestions for '%s':\n", word);
    for (int i = 0; i < dict->count; i++) {
        if (strncasecmp(word, dict->words[i], 3) == 0) {
            printf(" - %s\n", dict->words[i]);
        }
    }
}

void check_spelling(char *text, struct Dictionary *dict) {
    char word[MAX_WORD_LENGTH];
    int index = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            word[index++] = text[i];
        } else {
            if (index > 0) {
                word[index] = '\0';
                index = 0;

                if (!is_word_in_dictionary(word, dict)) {
                    printf("Misspelled word: '%s'\n", word);
                    print_suggestions(word, dict);
                }
            }
        }
    }
}

int main(int argc, char **argv) {
    struct Dictionary dict;
    dict.count = 0;

    load_dictionary(&dict);

    printf("Enter text to check spelling (Ctrl+D to end):\n");
    char *text = NULL;
    size_t len = 0;

    while (getline(&text, &len, stdin) != -1) {
        check_spelling(text, &dict);
    }

    free(text);
    return 0;
}