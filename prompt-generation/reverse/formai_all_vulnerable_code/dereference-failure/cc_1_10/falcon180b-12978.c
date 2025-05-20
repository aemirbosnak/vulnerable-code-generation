//Falcon-180B DATASET v1.0 Category: Memory management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

/* Node structure for linked list */
typedef struct node {
    int data;
    struct node *next;
} Node;

/* Memory management functions */
void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    free(ptr);
}

/* Linked list functions */
Node *create_node(int data) {
    Node *new_node = my_malloc(sizeof(Node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node **head, int data) {
    Node *new_node = create_node(data);
    if (new_node == NULL) {
        return;
    }
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node *head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    /* Add nodes to the list */
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);

    /* Print the list */
    print_list(head);

    /* Free memory used by the list */
    Node *current_node = head;
    while (current_node!= NULL) {
        Node *next_node = current_node->next;
        my_free(current_node);
        current_node = next_node;
    }

    return 0;
}