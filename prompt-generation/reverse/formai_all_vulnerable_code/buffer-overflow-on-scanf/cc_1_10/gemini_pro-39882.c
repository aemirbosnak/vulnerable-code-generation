//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *email;
    struct node *next;
} node_t;

node_t *head = NULL;

void add_email(char *email) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->email = strdup(email);
    new_node->next = head;
    head = new_node;
}

void remove_email(char *email) {
    node_t *prev = NULL;
    node_t *current = head;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->email);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void print_list() {
    node_t *current = head;

    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    char *email;

    while ((email = malloc(100)) != NULL) {
        scanf("%s", email);
        add_email(email);
    }

    print_list();

    return 0;
}