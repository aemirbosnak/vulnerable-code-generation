//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define a linked list structure
typedef struct linked_list {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

// Initialize a linked list
void init_linked_list(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

// Add a node to the end of the linked list
void add_node(LinkedList *list, int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    list->size++;
}

// Print the contents of the linked list
void print_linked_list(LinkedList *list) {
    Node *node = list->head;

    printf("Linked List: ");
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function
int main() {
    LinkedList list;
    init_linked_list(&list);

    add_node(&list, 1);
    add_node(&list, 2);
    add_node(&list, 3);

    print_linked_list(&list);

    Node *node = list.head;
    while (node!= NULL) {
        printf("Node data: %d\n", node->data);
        node = node->next;
    }

    return 0;
}