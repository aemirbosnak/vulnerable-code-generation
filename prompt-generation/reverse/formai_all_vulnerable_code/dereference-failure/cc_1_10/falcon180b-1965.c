//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_SIZE 100

typedef struct node {
    char data[MAX_NODE_SIZE];
    struct node *next;
} Node;

Node *create_node(char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strncpy(new_node->data, data, MAX_NODE_SIZE);
    new_node->next = NULL;
    return new_node;
}

void delete_node(Node *head, Node *delete_node) {
    Node *prev_node = head;
    Node *curr_node = head->next;

    while (curr_node!= delete_node && curr_node!= NULL) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    if (curr_node == NULL) {
        printf("Node not found.\n");
        return;
    }

    prev_node->next = curr_node->next;
    free(curr_node);
}

void add_node(Node *head, char *data) {
    Node *new_node = create_node(data);
    Node *curr_node = head->next;

    if (head->next == NULL) {
        head->next = new_node;
        return;
    }

    while (curr_node!= NULL) {
        curr_node = curr_node->next;
    }

    curr_node->next = new_node;
}

void print_list(Node *head) {
    Node *curr_node = head->next;

    while (curr_node!= NULL) {
        printf("%s -> ", curr_node->data);
        curr_node = curr_node->next;
    }

    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    add_node(head, "Hello");
    add_node(head, "World");
    add_node(head, "!");

    print_list(head);

    delete_node(head, head->next);

    print_list(head);

    return 0;
}