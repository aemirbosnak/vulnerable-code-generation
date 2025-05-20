//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define NUM_BUCKETS 26

typedef struct Node {
    char word[MAX_WORD_LENGTH + 1];
    struct Node *next;
} Node;

Node *word_list[NUM_BUCKETS];

void add_to_list(Node **head, char *word) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->next = *head;
    *head = new_node;
}

int hash(char *word) {
    int hash = 0;
    for (int i = 0; word[i]; i++) {
        hash = ((hash << 3) + hash) + tolower(word[i]);
    }
    return hash % NUM_BUCKETS;
}

void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF) {
        int index = hash(word);
        if (!word_list[index]) {
            word_list[index] = (Node *)malloc(sizeof(Node));
            word_list[index]->next = NULL;
        }
        add_to_list(&(word_list[index]->next), word);
    }

    fclose(file);
}

void check_word(char *word) {
    int index = hash(word);
    Node *current = word_list[index];
    while (current != NULL) {
        if (strcasecmp(current->word, word) == 0) {
            printf("%s is a valid word.\n", word);
            return;
        }
        current = current->next;
    }

    printf("%s is not a valid word.\n", word);
}

int main() {
    load_dictionary("dictionary.txt");

    char input[MAX_WORD_LENGTH + 1];
    while (1) {
        printf("Enter a word to check (type 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        check_word(input);
    }

    for (int i = 0; i < NUM_BUCKETS; i++) {
        Node *current = word_list[i];
        while (current != NULL) {
            free(current);
            current = current->next;
        }
        free(word_list[i]);
    }

    return 0;
}