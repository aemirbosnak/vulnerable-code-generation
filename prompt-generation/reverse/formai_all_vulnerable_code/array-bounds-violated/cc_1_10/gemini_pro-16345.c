//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 100000

typedef struct node {
    char word[MAX_WORD_LENGTH];
    struct node *next;
} node_t;

node_t *dictionary[26];

void insert_word(char *word) {
    int index = toupper(word[0]) - 'A';
    node_t *new_node = malloc(sizeof(node_t));
    strcpy(new_node->word, word);
    new_node->next = dictionary[index];
    dictionary[index] = new_node;
}

bool check_spelling(char *word) {
    int index = toupper(word[0]) - 'A';
    node_t *current = dictionary[index];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening dictionary file: %s\n", filename);
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        insert_word(word);
    }
    fclose(file);
}

void spell_check(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", filename);
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        if (!check_spelling(word)) {
            printf("%s\n", word);
        }
    }
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary file> <input file>\n", argv[0]);
        exit(1);
    }
    load_dictionary(argv[1]);
    spell_check(argv[2]);
    return 0;
}