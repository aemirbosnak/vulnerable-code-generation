//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct Node {
    char email[50];
    int hash;
    struct Node *next;
} Node;

Node *hash_table[TABLE_SIZE];

int hash_func(char *email) {
    int hash = 0;
    int i;

    for (i = 0; email[i] != '\0'; i++) {
        hash += tolower(email[i]);
    }

    hash %= TABLE_SIZE;
    return hash;
}

void add_subscriber(char *email) {
    int hash = hash_func(email);
    Node *new_node = (Node *)malloc(sizeof(Node));

    strcpy(new_node->email, email);
    new_node->hash = hash;
    new_node->next = hash_table[hash];
    hash_table[hash] = new_node;
}

void remove_subscriber(char *email) {
    int hash = hash_func(email);
    Node *current = hash_table[hash];
    Node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                hash_table[hash] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void display_subscribers() {
    int i;

    printf("Subscribers:\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            Node *current = hash_table[i];
            printf("%s\n", current->email);

            while (current->next != NULL) {
                current = current->next;
                printf("%s\n", current->email);
            }
        }
    }
}

int main() {
    char command[10], email[50];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s", email);
            add_subscriber(email);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%s", email);
            remove_subscriber(email);
        } else if (strcmp(command, "display") == 0) {
            display_subscribers();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}