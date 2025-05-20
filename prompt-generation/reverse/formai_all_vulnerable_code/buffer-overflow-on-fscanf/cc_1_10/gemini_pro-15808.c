//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *word;
    struct Node *next;
} Node;

Node *head = NULL;

void insert(char *word) {
    Node *new_node = malloc(sizeof(Node));
    new_node->word = strdup(word);
    new_node->next = head;
    head = new_node;
}

int find(char *word) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <dictionary file> <text file>\n", argv[0]);
        return 1;
    }

    FILE *dictionary = fopen(argv[1], "r");
    if (dictionary == NULL) {
        perror("Could not open dictionary file");
        return 1;
    }

    char word[1024];
    while (fscanf(dictionary, "%s\n", word) != EOF) {
        insert(word);
    }
    fclose(dictionary);

    FILE *text = fopen(argv[2], "r");
    if (text == NULL) {
        perror("Could not open text file");
        return 1;
    }

    while (fscanf(text, "%s ", word) != EOF) {
        if (!find(word)) {
            printf("%s\n", word);
        }
    }
    fclose(text);

    return 0;
}