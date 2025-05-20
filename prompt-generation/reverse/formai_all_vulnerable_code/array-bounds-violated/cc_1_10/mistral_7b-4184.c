//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY_SIZE 10000

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *dictionary = NULL;

void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[256];
    Word *new_word;

    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        size_t len = strlen(line) - 1;
        if (line[len] == '\n') line[len] = '\0';
        new_word = (Word *) malloc(sizeof(Word));
        new_word->word = strdup(line);
        new_word->next = dictionary;
        dictionary = new_word;
    }

    fclose(file);
}

int check_spelling(char *word) {
    Word *current = dictionary;

    while (current != NULL) {
        if (strcasecmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void tokenize(char *line, char **tokens, int *num_tokens) {
    int cap_next = 0;
    int i = 0;

    tokens[i] = strtok(line, " ");

    while (tokens[i] != NULL) {
        i++;

        if (i >= *num_tokens) {
            *num_tokens = i + 10; // Resize the array if necessary
            tokens = (char **) realloc(tokens, (*num_tokens) * sizeof(char *));
            tokens[i] = strtok(NULL, " ");
        }
    }

    (*num_tokens) = i;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    load_dictionary("dictionary.txt");

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Could not open text file.\n");
        return 1;
    }

    char line[256];
    char tokens[1024][256];
    int num_tokens;

    while (fgets(line, sizeof(line), file) != NULL) {
        tokenize(line, tokens, &num_tokens);

        for (int i = 0; i < num_tokens; i++) {
            if (!check_spelling(tokens[i])) {
                printf("Misspelled word: %s\n", tokens[i]);
            }
        }
    }

    fclose(file);

    return 0;
}