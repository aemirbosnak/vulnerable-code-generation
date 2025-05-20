//Falcon-180B DATASET v1.0 Category: Educational ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node structure for the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void create_linked_list(Node** head, int n);
void print_linked_list(Node* head);
void delete_linked_list(Node** head);

int main() {
    Node* head = NULL;
    int n;

    // Get the number of nodes from the user
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create a linked list with n nodes
    create_linked_list(&head, n);

    // Print the linked list
    printf("Linked List: ");
    print_linked_list(head);

    // Delete the linked list
    delete_linked_list(&head);

    return 0;
}

// Function to create a linked list with n nodes
void create_linked_list(Node** head, int n) {
    *head = NULL;
    for (int i = 0; i < n; i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = i;
        new_node->next = NULL;
        if (*head == NULL) {
            *head = new_node;
        } else {
            Node* temp = *head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
}

// Function to print the linked list
void print_linked_list(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to delete the linked list
void delete_linked_list(Node** head) {
    Node* temp = *head;
    while (temp!= NULL) {
        Node* next_node = temp->next;
        free(temp);
        temp = next_node;
    }
    *head = NULL;
}