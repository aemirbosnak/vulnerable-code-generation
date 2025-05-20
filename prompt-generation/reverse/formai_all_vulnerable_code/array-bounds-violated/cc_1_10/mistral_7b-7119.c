//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define NUM_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int is_valid;
} word_t;

word_t dictionary[NUM_WORDS];

void load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    int i = 0;
    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, sizeof(line), fp) != NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') line[len - 1] = '\0';
        strcpy(dictionary[i].word, line);
        dictionary[i].is_valid = 1;
        i++;
    }

    fclose(fp);
}

int is_valid_word(const char *word) {
    for (int i = 0; i < NUM_WORDS; i++) {
        if (strcasecmp(dictionary[i].word, word) == 0) {
            return dictionary[i].is_valid;
        }
    }

    return 0;
}

void check_word(const char *word) {
    int is_valid = is_valid_word(word);
    if (is_valid) {
        printf("%s is a valid word.\n", word);
    } else {
        printf("%s is not a valid word.\n", word);
    }
}

int main() {
    load_dictionary("dictionary.txt");

    char input[MAX_WORD_LENGTH + 1];
    while (1) {
        printf("Enter a word to check (or type 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        check_word(input);
    }

    return 0;
}