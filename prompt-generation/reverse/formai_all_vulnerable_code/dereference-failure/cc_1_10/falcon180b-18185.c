//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Function to create a new node
Node* create_node(char data[]) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the end of the list
void insert_at_end(Node** head_ref, char data[]) {
    Node* new_node = create_node(data);
    Node* temp = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    return;
}

// Function to search for a node with given data
Node* search_node(Node* head, char data[]) {
    Node* current = head;

    while (current!= NULL) {
        if (strcmp(current->data, data) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Function to print the linked list
void print_list(Node* node) {
    while (node!= NULL) {
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;

    // Insert nodes
    insert_at_end(&head, "apple");
    insert_at_end(&head, "banana");
    insert_at_end(&head, "cherry");

    // Print initial list
    printf("Initial list:\n");
    print_list(head);

    // Search for a node
    Node* found_node = search_node(head, "banana");

    if (found_node == NULL) {
        printf("Node not found.\n");
    } else {
        printf("Node found:\n");
        print_list(found_node);
    }

    return 0;
}