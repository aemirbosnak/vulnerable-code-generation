//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LEN 50

typedef struct {
    char word[WORD_LEN];
    int is_valid;
} word_t;

word_t dictionary[MAX_WORDS];

void load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fscanf(fp, "%s", dictionary[i].word) != EOF) {
        dictionary[i].is_valid = 1;
        i++;
    }

    fclose(fp);
}

int is_valid_word(const char *word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(dictionary[i].word, word) == 0 && dictionary[i].is_valid) {
            return 1;
        }
    }

    return 0;
}

void check_spell(const char *input) {
    char *token = strtok(strdup(input), " ");
    while (token != NULL) {
        if (!is_valid_word(token)) {
            printf("Error: '%s' is not a valid word.\n", token);
        }
        token = strtok(NULL, " ");
    }
}

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <dictionary.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_dictionary(argv[1]);

    char input[100];
    printf("Enter text to check spell: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    check_spell(input);

    return EXIT_SUCCESS;
}