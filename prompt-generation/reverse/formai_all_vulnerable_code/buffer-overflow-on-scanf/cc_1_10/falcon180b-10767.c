//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
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
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to print the list
void print_list(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to reverse the list
Node* reverse_list(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Main function
int main() {
    Node* head = NULL;
    int choice, data;

    // Menu-driven program to perform various operations on the list
    while (true) {
        printf("\n");
        printf("1. Add element\n");
        printf("2. Print list\n");
        printf("3. Reverse list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d", &data);
                add_node(&head, data);
                break;
            case 2:
                printf("List after adding elements:\n");
                print_list(head);
                break;
            case 3:
                head = reverse_list(head);
                printf("List after reversing:\n");
                print_list(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}