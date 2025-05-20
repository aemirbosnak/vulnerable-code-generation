//Falcon-180B DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    char data[MAX_SIZE];
    int size;
    struct node *next;
} Node;

Node *head = NULL;

Node *create_node(char *data, int size) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error: failed to allocate memory for new node.\n");
        exit(1);
    }
    strcpy(new_node->data, data);
    new_node->size = size;
    new_node->next = NULL;
    return new_node;
}

void insert_node(Node *prev_node, Node *new_node) {
    if (prev_node == NULL) {
        head = new_node;
    } else {
        prev_node->next = new_node;
    }
}

void delete_node(Node *node) {
    if (node!= NULL) {
        if (node->next!= NULL) {
            Node *temp = node->next;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = NULL;
        } else {
            Node *temp = head;
            while (temp->next!= node) {
                temp = temp->next;
            }
            temp->next = NULL;
        }
        free(node);
    }
}

int main() {
    Node *node1 = create_node("Hello, world!", 13);
    Node *node2 = create_node("This is a test.", 16);
    Node *node3 = create_node("How are you doing today?", 25);

    insert_node(NULL, node1);
    insert_node(node1, node2);
    insert_node(node2, node3);

    printf("Linked list before deletion:\n");
    Node *temp = head;
    while (temp!= NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }

    delete_node(node2);

    printf("\nLinked list after deletion:\n");
    temp = head;
    while (temp!= NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }

    return 0;
}