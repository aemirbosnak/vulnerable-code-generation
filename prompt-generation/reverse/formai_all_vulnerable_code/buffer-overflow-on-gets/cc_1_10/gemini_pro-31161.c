//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *entry;
    struct node *next;
} node_t;

node_t *head = NULL;
node_t *tail = NULL;

void add_entry(char *entry) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->entry = strdup(entry);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        tail->next = new_node;
    }
    tail = new_node;
}

void print_entries() {
    node_t *current_node = head;

    while (current_node != NULL) {
        printf("%s\n", current_node->entry);
        current_node = current_node->next;
    }
}

int main() {
    char entry[1024];

    while (1) {
        printf("What's on your mind? (Type 'quit' to exit)\n");
        gets(entry);

        if (strcmp(entry, "quit") == 0) {
            break;
        } else {
            add_entry(entry);
        }
    }

    printf("\nYour entries:\n");
    print_entries();

    return 0;
}