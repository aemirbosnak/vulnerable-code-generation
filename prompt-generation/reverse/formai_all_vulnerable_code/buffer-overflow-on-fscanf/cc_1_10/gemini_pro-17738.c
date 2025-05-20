//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *word;
    struct Node *next;
} Node;

typedef struct Dictionary {
    struct Node *head;
    int size;
} Dictionary;

Dictionary *create_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    Dictionary *dictionary = malloc(sizeof(Dictionary));
    dictionary->head = NULL;
    dictionary->size = 0;

    char word[100];
    while (fscanf(file, "%s", word) != EOF) {
        Node *node = malloc(sizeof(Node));
        node->word = strdup(word);
        node->next = dictionary->head;
        dictionary->head = node;
        dictionary->size++;
    }

    fclose(file);
    return dictionary;
}

void destroy_dictionary(Dictionary *dictionary) {
    Node *node = dictionary->head;
    while (node) {
        Node *next = node->next;
        free(node);
        node = next;
    }

    free(dictionary);
}

bool check_spelling(Dictionary *dictionary, char *word) {
    Node *node = dictionary->head;
    while (node) {
        if (!strcmp(node->word, word)) {
            return true;
        }
        node = node->next;
    }

    return false;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <dictionary> <word>\n", argv[0]);
        return 1;
    }

    Dictionary *dictionary = create_dictionary(argv[1]);
    if (!dictionary) {
        return 1;
    }

    char *word = argv[2];
    bool correct = check_spelling(dictionary, word);

    if (correct) {
        printf("%s is spelled correctly.\n", word);
    } else {
        printf("%s is spelled incorrectly.\n", word);
    }

    destroy_dictionary(dictionary);
    return 0;
}