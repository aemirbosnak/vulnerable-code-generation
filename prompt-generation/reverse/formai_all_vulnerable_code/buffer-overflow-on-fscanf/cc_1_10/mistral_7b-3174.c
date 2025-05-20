//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50
#define DICTIONARY_FILE "dictionary.txt"

typedef struct Word {
    char word[WORD_LENGTH];
    int is_valid;
} Word;

void load_dictionary(Word dictionary[MAX_WORDS]) {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    int index = 0;

    if (file == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", dictionary[index].word) != EOF) {
        dictionary[index].is_valid = 1;
        index++;
    }

    fclose(file);
}

int is_valid_word(Word dictionary[MAX_WORDS], char *word) {
    int index;

    for (index = 0; index < MAX_WORDS; index++) {
        if (strcmp(dictionary[index].word, word) == 0 && dictionary[index].is_valid == 1) {
            return 1;
        }
    }

    return 0;
}

void check_spell(char *input, Word dictionary[MAX_WORDS]) {
    char *token;
    int i, is_valid;

    token = strtok(input, " ");

    while (token != NULL) {
        for (i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }

        is_valid = is_valid_word(dictionary, token);

        if (is_valid == 0) {
            printf("Error: '%s' is not a valid word.\n", token);
        }

        token = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    Word dictionary[MAX_WORDS];
    char *input;

    load_dictionary(dictionary);

    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        exit(1);
    }

    input = argv[1];

    check_spell(input, dictionary);

    return 0;
}