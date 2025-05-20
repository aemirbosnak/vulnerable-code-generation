//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node in the linked list
typedef struct node {
    char *data;
    struct node *next;
} Node;

// Function to create a new node
Node* create_node(char *data) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Unable to allocate memory for new node.\n");
        exit(1);
    }
    node->data = strdup(data);
    node->next = NULL;
    return node;
}

// Function to add a new node to the end of the linked list
void add_node(Node **head, char *data) {
    Node *new_node = create_node(data);
    Node *temp = *head;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to print the linked list
void print_list(Node *head) {
    printf("Linked List:\n");
    while (head!= NULL) {
        printf("%s -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to recover data from a corrupted linked list
void recover_data(Node *head) {
    Node *temp = head;
    while (temp!= NULL) {
        if (temp->next == NULL) {
            printf("Data lost: %s\n", temp->data);
        }
        temp = temp->next;
    }
}

// Main function
int main() {
    Node *head = NULL;
    add_node(&head, "apple");
    add_node(&head, "banana");
    add_node(&head, "cherry");
    add_node(&head, "date");
    add_node(&head, "elderberry");
    print_list(head);
    recover_data(head);
    return 0;
}