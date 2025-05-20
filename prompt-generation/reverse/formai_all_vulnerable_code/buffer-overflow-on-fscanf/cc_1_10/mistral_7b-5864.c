//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define WORDS_COUNT 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int is_valid;
} word_t;

word_t dictionary[WORDS_COUNT];

void load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(dictionary[i].word, word);
        dictionary[i].is_valid = 1;
        i++;
    }

    fclose(fp);
}

int check_word(const char *word) {
    for (int i = 0; i < WORDS_COUNT; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return dictionary[i].is_valid;
        }
    }
    return 0;
}

int main() {
    load_dictionary("dictionary.txt");

    char line[1024], word[MAX_WORD_LENGTH];
    gets(line); // input line from stdin, ephemeral style

    char *token = strtok(line, " ");
    while (token != NULL) {
        strcpy(word, token);
        if (check_word(word) == 0) {
            printf("Error: %s is not a valid word\n", word);
        }
        token = strtok(NULL, " ");
    }

    return EXIT_SUCCESS;
}