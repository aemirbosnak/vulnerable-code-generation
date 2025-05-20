//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of a linked list
typedef struct linked_list {
    Node* head;
} LinkedList;

// Function to create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create an empty linked list
LinkedList* create_linked_list() {
    LinkedList* new_list = (LinkedList*)malloc(sizeof(LinkedList));
    new_list->head = NULL;
    return new_list;
}

// Function to add a node at the end of the linked list
void add_node(LinkedList* list, int data) {
    Node* new_node = create_node(data);
    Node* current_node = list->head;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        while (current_node->next!= NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

// Function to remove a node with the given data from the linked list
void remove_node(LinkedList* list, int data) {
    Node* previous_node = NULL;
    Node* current_node = list->head;
    if (current_node!= NULL && current_node->data == data) {
        list->head = current_node->next;
        free(current_node);
        return;
    }
    while (current_node!= NULL && current_node->data!= data) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        return;
    }
    previous_node->next = current_node->next;
    free(current_node);
}

// Function to print the contents of the linked list
void print_linked_list(LinkedList* list) {
    Node* current_node = list->head;
    while (current_node!= NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    // Create an empty linked list
    LinkedList* list = create_linked_list();

    // Add some nodes to the linked list
    add_node(list, 10);
    add_node(list, 20);
    add_node(list, 30);

    // Print the contents of the linked list
    print_linked_list(list);

    // Remove a node from the linked list
    remove_node(list, 20);

    // Print the contents of the linked list again
    print_linked_list(list);

    return 0;
}