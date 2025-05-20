//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    char *data;
    struct node *next;
} Node;

// Function to create a new node
Node *create_node(char *data) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the end of the list
void add_to_end(Node **head, char *data) {
    Node *new_node = create_node(data);
    Node *temp = *head;
    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to display the linked list
void display_list(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Test the linked list functions
    Node *head = NULL;
    add_to_end(&head, "John");
    add_to_end(&head, "Doe");
    add_to_end(&head, "Programmer");
    display_list(head);

    return 0;
}