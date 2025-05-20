//Falcon-180B DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
struct node {
    char data[MAX_SIZE];
    struct node* next;
};

int main() {
    // Initialize variables
    struct node* head = NULL;
    struct node* tail = NULL;
    int count = 0;

    // Allocate memory for the first node
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: Unable to allocate memory for new node.\n");
        return 1;
    }

    // Set the data for the first node
    strcpy(new_node->data, "Hello World!");

    // Set the next pointer to NULL
    new_node->next = NULL;

    // Set the head and tail pointers to the new node
    head = new_node;
    tail = new_node;

    // Allocate memory for additional nodes
    struct node* new_node2 = (struct node*) malloc(sizeof(struct node));
    if (new_node2 == NULL) {
        printf("Error: Unable to allocate memory for new node.\n");
        return 1;
    }

    struct node* new_node3 = (struct node*) malloc(sizeof(struct node));
    if (new_node3 == NULL) {
        printf("Error: Unable to allocate memory for new node.\n");
        return 1;
    }

    // Set the data for the additional nodes
    strcpy(new_node2->data, "Node 2");
    strcpy(new_node3->data, "Node 3");

    // Set the next pointers for the additional nodes
    new_node2->next = new_node3;
    new_node3->next = NULL;

    // Update the tail pointer to the last node
    tail = new_node3;

    // Print the contents of the linked list
    struct node* current_node = head;
    while (current_node!= NULL) {
        printf("%s\n", current_node->data);
        current_node = current_node->next;
    }

    // Free the memory allocated for the linked list nodes
    current_node = head;
    while (current_node!= NULL) {
        free(current_node->data);
        free(current_node);
        current_node = current_node->next;
    }

    return 0;
}