//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100

typedef struct node {
    char *word;
    struct node *next;
} node_t;

node_t *head = NULL;

bool is_word_in_dictionary(char *word);
void insert_word_into_dictionary(char *word);
void print_dictionary();
void free_dictionary();

int main() {
    char input[MAX_WORD_SIZE];
    while (true) {
        printf("Enter a word to check (or \"quit\" to exit): ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }

        bool is_correct = is_word_in_dictionary(input);
        if (is_correct) {
            printf("The word \"%s\" is correct.\n", input);
        } else {
            printf("The word \"%s\" is not correct.\n", input);
            printf("Do you want to add it to the dictionary? (y/n) ");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'y') {
                insert_word_into_dictionary(input);
            }
        }
    }

    free_dictionary();
    return 0;
}

bool is_word_in_dictionary(char *word) {
    node_t *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void insert_word_into_dictionary(char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->word = strdup(word);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node_t *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_dictionary() {
    node_t *current = head;
    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }
}

void free_dictionary() {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}