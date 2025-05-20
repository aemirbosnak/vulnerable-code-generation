//Falcon-180B DATASET v1.0 Category: Memory management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char *data;
    struct node *next;
} Node;

// Linked list structure
Node *head;

// Function to create a new node
Node *create_node(char *data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new node to the end of the list
void add_node(char *data) {
    Node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    Node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to delete a node with the given data
void delete_node(char *data) {
    if (head == NULL) {
        printf("Error: List is empty\n");
        return;
    }
    if (head->data == data) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Node *temp = head;
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Error: Node not found\n");
        return;
    }
    Node *node_to_delete = temp->next;
    temp->next = temp->next->next;
    free(node_to_delete);
}

// Function to print the list
void print_list() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the memory used by the list
void free_list() {
    Node *temp = head;
    while (temp!= NULL) {
        Node *next = temp->next;
        free(temp->data);
        free(temp);
        temp = next;
    }
    head = NULL;
}

int main() {
    head = NULL;
    add_node("Hello");
    add_node("World");
    print_list(); // Output: Hello World
    delete_node("Hello");
    print_list(); // Output: World
    free_list();
    return 0;
}