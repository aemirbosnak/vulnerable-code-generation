//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct node {
    char word[MAX_WORD_LEN + 1];
    struct node *next;
} node_t;

node_t *head = NULL;
node_t *tail = NULL;

void insert(char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    strcpy(new_node->word, word);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

int search(char *word) {
    node_t *current = head;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening dictionary file.\n");
        return;
    }

    char word[MAX_WORD_LEN + 1];

    while (fscanf(file, "%s", word) != EOF) {
        insert(word);
    }

    fclose(file);
}

int check_spelling(char *word) {
    return search(word);
}

int main() {
    load_dictionary("dictionary.txt");

    char word[MAX_WORD_LEN + 1];

    while (1) {
        printf("Enter a word (or q to quit): ");
        scanf("%s", word);

        if (strcmp(word, "q") == 0) {
            break;
        }

        int correct = check_spelling(word);

        if (correct) {
            printf("The word \"%s\" is spelled correctly.\n", word);
        } else {
            printf("The word \"%s\" is spelled incorrectly.\n", word);
        }
    }

    return 0;
}