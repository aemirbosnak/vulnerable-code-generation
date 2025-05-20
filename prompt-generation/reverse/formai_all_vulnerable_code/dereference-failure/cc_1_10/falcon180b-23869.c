//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node at the end of the list
void add_node(Node** head, int data) {
    Node* new_node = create_node(data);
    Node* temp = *head;
    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
        return;
    }
    while (temp->next!= NULL)
        temp = temp->next;
    temp->next = new_node;
}

// Function to add a node at the beginning of the list
void add_node_at_beginning(Node** head, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to add a node at a specific position in the list
void add_node_at_position(Node** head, int data, int position) {
    Node* new_node = create_node(data);
    Node* temp = *head;
    if (position == 0) {
        new_node->next = temp;
        *head = new_node;
        return;
    }
    for (int i = 1; i < position - 1 && temp!= NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to delete a node with given data
void delete_node(Node** head, int data) {
    Node* temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    Node* prev_node = temp->next;
    free(temp);
    temp = prev_node;
}

// Function to print the list
void print_list(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main() {
    Node* head = NULL;
    add_node(&head, 10);
    add_node(&head, 20);
    add_node(&head, 30);
    print_list(head);
    add_node_at_beginning(&head, 5);
    print_list(head);
    add_node_at_position(&head, 25, 2);
    print_list(head);
    delete_node(&head, 20);
    print_list(head);
    delete_node(&head, 5);
    print_list(head);
    delete_node(&head, 30);
    print_list(head);
    return 0;
}