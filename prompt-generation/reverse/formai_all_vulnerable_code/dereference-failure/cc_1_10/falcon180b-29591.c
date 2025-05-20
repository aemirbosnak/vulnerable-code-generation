//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define a linked list structure
typedef struct linked_list {
    Node* head;
    Node* tail;
} LinkedList;

// Initialize an empty linked list
void init_linked_list(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

// Add a node to the end of the linked list
void add_node(LinkedList* list, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Print the linked list
void print_linked_list(LinkedList* list) {
    Node* curr_node = list->head;
    printf("Linked List: ");

    while (curr_node!= NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }

    printf("\n");
}

// Reverse the linked list
void reverse_linked_list(LinkedList* list) {
    Node* prev_node = NULL;
    Node* curr_node = list->head;

    while (curr_node!= NULL) {
        Node* next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    list->head = prev_node;
}

int main() {
    LinkedList list;
    init_linked_list(&list);

    add_node(&list, 1);
    add_node(&list, 2);
    add_node(&list, 3);
    add_node(&list, 4);
    add_node(&list, 5);

    printf("Original Linked List: ");
    print_linked_list(&list);

    reverse_linked_list(&list);

    printf("Reversed Linked List: ");
    print_linked_list(&list);

    return 0;
}