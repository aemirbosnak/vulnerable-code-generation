//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_valid;
} word_t;

void load_dictionary(word_t *dictionary) {
    FILE *fp = fopen("dictionary.txt", "r");
    if (!fp) {
        fprintf(stderr, "Failed to open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(dictionary[index].word, word);
        dictionary[index].is_valid = true;
        index++;
    }

    fclose(fp);
}

bool is_valid_word(word_t *dictionary, char *word, int size) {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strncmp(dictionary[i].word, word, strlen(word)) == 0 && dictionary[i].is_valid) {
            return true;
        }
    }

    return false;
}

void spell_check(char *text) {
    word_t dictionary[DICTIONARY_SIZE];
    load_dictionary(dictionary);

    char *token = strtok(text, " .,\n");
    int words_checked = 0;

    while (token != NULL) {
        int word_length = strlen(token);

        if (word_length > MAX_WORD_LENGTH) {
            printf("Warning: Word '%s' is too long.\n", token);
            token = strtok(NULL, " .,\n");
            continue;
        }

        if (!is_valid_word(dictionary, token, word_length)) {
            printf("Error: Word '%s' is not in the dictionary.\n", token);
        }

        words_checked++;
        token = strtok(NULL, " .,\n");
    }

    printf("Successfully checked %d words.\n", words_checked);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *text = argv[1];
    spell_check(text);

    return EXIT_SUCCESS;
}

// Happiness is when the code compiles and runs without errors :)