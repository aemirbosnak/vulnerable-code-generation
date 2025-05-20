//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
Node* create_node(int data);
Node* add_node(Node* head, int data);
int delete_node(Node* head, int data);
void print_list(Node* head);

int main() {
    Node* head = NULL;

    // Creating a new linked list with 5 nodes
    head = add_node(head, 1);
    head = add_node(head, 2);
    head = add_node(head, 3);
    head = add_node(head, 4);
    head = add_node(head, 5);

    // Printing the original linked list
    printf("Original Linked List:\n");
    print_list(head);

    // Deleting the node with data 3
    head = delete_node(head, 3);

    // Printing the updated linked list
    printf("\nLinked List after deleting node with data 3:\n");
    print_list(head);

    return 0;
}

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new node at the end of the linked list
Node* add_node(Node* head, int data) {
    Node* new_node = create_node(data);

    if (head == NULL) {
        head = new_node;
        return head;
    }

    Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;

    return head;
}

// Function to delete a node with given data from the linked list
int delete_node(Node* head, int data) {
    Node* temp = head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return 1;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return 0;
    }

    prev->next = temp->next;
    free(temp);

    return 1;
}

// Function to print the linked list
void print_list(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}