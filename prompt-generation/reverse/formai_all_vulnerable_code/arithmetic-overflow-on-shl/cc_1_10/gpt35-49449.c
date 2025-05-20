//FormAI DATASET v1.0 Category: Spam Detection System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* value;
    struct node* next;
} node_t;

int hash(char* str) {
    int hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return abs(hash);
}

void add_node(node_t** head, char* value) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));

    new_node->value = (char*)malloc(sizeof(char) * (strlen(value) + 1));
    strcpy(new_node->value, value);

    new_node->next = *head;

    *head = new_node;
}

int contains(node_t* head, char* value) {
    node_t* current = head;

    while (current != NULL) {
        if (strcmp(current->value, value) == 0) {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

int check_for_spam(node_t** hash_table, char* message) {
    if (*message == '\0') {
        return 0;
    }

    int hash_value = hash(message) % 100;
    if (contains(hash_table[hash_value], message)) {
        return 1;
    }

    add_node(&hash_table[hash_value], message);

    return check_for_spam(hash_table, message + 1);
}

int main() {
    node_t* hash_table[100];
    memset(hash_table, 0, sizeof(hash_table));

    char* message = "Hello! This is a spam message. Please don't respond.";
    printf("Message: %s\n", message);

    if (check_for_spam(hash_table, message)) {
        printf("This is a spam message!\n");
    } else {
        printf("This is not a spam message.\n");
    }

    return 0;
}