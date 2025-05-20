//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int is_valid;
} word_t;

word_t dictionary[MAX_WORDS];

void load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "Could not open dictionary file %s\n", filename);
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s", dictionary[i].word) != EOF) {
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

int main() {
    load_dictionary("dictionary.txt");

    char input[1024];
    while (1) {
        printf("Enter a word to check or type 'quit' to exit: ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        int is_valid = is_valid_word(input);
        if (is_valid) {
            printf("The word '%s' is valid.\n", input);
        } else {
            printf("The word '%s' is not valid.\n", input);
        }

        for (int i = 0; i < strlen(input); i++) {
            putchar(toupper(input[i]));
        }
        putchar('\n');
    }

    return 0;
}