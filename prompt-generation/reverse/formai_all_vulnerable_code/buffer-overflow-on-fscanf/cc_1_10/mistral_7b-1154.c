//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 1000

typedef struct Word {
    char str[MAX_WORD_LEN];
    struct Word *next;
} Word;

Word *dictionary = NULL;
Word *current = NULL;

void add_to_dictionary(char *word) {
    Word *new_word = (Word *)malloc(sizeof(Word));
    strcpy(new_word->str, word);
    new_word->next = dictionary;
    dictionary = new_word;
}

void load_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    char word[MAX_WORD_LEN];

    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word) != EOF) {
        add_to_dictionary(word);
    }

    fclose(fp);
}

int is_valid_word(char *word) {
    current = dictionary;

    while (current != NULL) {
        if (strcmp(current->str, word) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int check_spelling(char *text) {
    char *token = strtok(text, " ");
    int num_errors = 0;

    while (token != NULL) {
        if (!is_valid_word(token)) {
            printf("Error: '%s' is not a valid word.\n", token);
            num_errors++;
        }
        token = strtok(NULL, " ");
    }

    return num_errors;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    load_dictionary();

    FILE *fp = fopen(argv[1], "r");
    char text[1024];

    if (fp == NULL) {
        printf("Error: Unable to open text file.\n");
        return 1;
    }

    fgets(text, sizeof(text), fp);
    fclose(fp);

    int num_errors = check_spelling(text);

    printf("Number of spelling errors: %d\n", num_errors);

    return 0;
}