//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define NUM_BUCKETS 26

typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node *next;
} Node;

Node *word_list[NUM_BUCKETS];

int hash(char c) {
    return tolower(c) - 'a';
}

void add_word(char *word) {
    int index = hash(word[0]);
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->next = word_list[index];
    word_list[index] = new_node;
}

void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];

    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", word) != EOF) {
        add_word(word);
    }

    fclose(file);
}

int is_word_in_dictionary(char *word) {
    int index = hash(word[0]);
    Node *current = word_list[index];

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void check_spell(char *input) {
    char *token = strtok(input, " ");
    int i = 0;

    while (token != NULL) {
        if (!is_word_in_dictionary(token)) {
            printf("Error: Misspelled word %s at position %d.\n", token, i + 1);
        }
        token = strtok(NULL, " ");
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    load_dictionary("dictionary.txt");
    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        exit(1);
    }

    char input[1024];
    fgets(input, sizeof(input), file);
    check_spell(input);

    fclose(file);
    return 0;
}