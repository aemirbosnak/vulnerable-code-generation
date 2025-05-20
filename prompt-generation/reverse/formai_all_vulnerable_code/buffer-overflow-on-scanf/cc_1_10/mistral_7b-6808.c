//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    size_t size;
    struct Node *next;
} Node;

Node* recursive_alloc(size_t size, size_t depth) {
    Node *new_node;

    new_node = (Node*) malloc(sizeof(Node) + size);
    if (new_node == NULL) {
        fprintf(stderr, "Out of memory at depth %zu\n", depth);
        exit(EXIT_FAILURE);
    }

    new_node->size = size;
    new_node->next = NULL;

    if (depth > 0)
        new_node->next = recursive_alloc(size, depth - 1);

    return new_node;
}

void recursive_free(Node *node) {
    if (node != NULL) {
        recursive_free(node->next);
        free(node);
    }
}

int main() {
    Node *head, *temp;
    size_t size, depth;

    printf("Enter the size of each allocation: ");
    scanf("%zu", &size);
    printf("Enter the depth of nested allocations: ");
    scanf("%zu", &depth);

    head = recursive_alloc(size, depth);
    printf("Successfully allocated %zu bytes of memory\n", size + sizeof(Node));

    temp = head;
    while (temp != NULL) {
        printf("Address of current node: %p\n", temp);
        printf("Data in current node: %p\n", &temp->data);
        temp = temp->next;
    }

    recursive_free(head);
    printf("Successfully deallocated %zu bytes of memory\n", size + sizeof(Node));

    return 0;
}