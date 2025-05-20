//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: Dennis Ritchie
// Linked list operations example program

#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to insert a new node at the beginning of the list
void insert_beginning(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a new node at the end of the list
void insert_end(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to delete the first node in the list
void delete_beginning(node **head) {
    node *temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to delete the last node in the list
void delete_end(node **head) {
    if (*head == NULL) {
        return;
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        node *temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

// Function to display the list
void display(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;

    insert_beginning(&head, 10);
    insert_beginning(&head, 20);
    insert_end(&head, 30);
    insert_end(&head, 40);

    display(head);

    delete_beginning(&head);
    display(head);

    delete_end(&head);
    display(head);

    return 0;
}