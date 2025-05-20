//FormAI DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node
node *new_node(int data) {
    node *p = (node *)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    return p;
}

// Function to insert a node at the end of the linked list
void insert_node(node **head, int data) {
    node *p = new_node(data);
    if (*head == NULL) {
        *head = p;
        return;
    }
    node *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = p;
}

// Function to delete a node at a given index
void delete_node(node **head, int index) {
    if (*head == NULL) {
        printf("The linked list is empty!\n");
        return;
    }
    if (index == 0) {
        node *p = *head;
        *head = (*head)->next;
        free(p);
        return;
    }
    node *curr = *head;
    int i;
    for (i = 0; i < index-1 && curr->next != NULL; i++) {
        curr = curr->next;
    }
    if (curr->next == NULL || i != index-1) {
        printf("Invalid index!\n");
        return;
    }
    node *p = curr->next;
    curr->next = curr->next->next;
    free(p);
}

// Function to print the linked list
void print_list(node *head) {
    if (head == NULL) {
        printf("The linked list is empty!\n");
        return;
    }
    node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;
    printf("Welcome to the Linked List Visualizer!\n\n");
    while (1) {
        printf("Please choose an option below:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Print the linked list\n");
        printf("4. Exit\n");
        int choice, data, index;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insert_node(&head, data);
                break;
            case 2:
                printf("Enter the index of the node to delete: ");
                scanf("%d", &index);
                delete_node(&head, index);
                break;
            case 3:
                printf("The linked list is: ");
                print_list(head);
                break;
            case 4:
                printf("Thank you for using the Linked List Visualizer!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
        printf("\n");
    }
    return 0;
}