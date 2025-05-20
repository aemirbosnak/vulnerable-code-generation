//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: inquisitive
// Linked List Operations Example Program

#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct node {
    int data;
    struct node *next;
};

// Function to insert a node at the beginning of the linked list
void insert_begin(struct node **head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_end(struct node **head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to insert a node at a given position in the linked list
void insert_pos(struct node **head, int pos, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (pos == 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        struct node *temp = *head;
        int i;
        for (i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// Function to delete a node from the beginning of the linked list
void delete_begin(struct node **head) {
    struct node *temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to delete a node from the end of the linked list
void delete_end(struct node **head) {
    struct node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node from a given position in the linked list
void delete_pos(struct node **head, int pos) {
    struct node *temp = *head;
    if (pos == 0) {
        *head = temp->next;
        free(temp);
    } else {
        int i;
        for (i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        struct node *temp2 = temp->next->next;
        free(temp->next);
        temp->next = temp2;
    }
}

// Function to display the linked list
void display(struct node **head) {
    struct node *temp = *head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Initialize the linked list
    struct node *head = NULL;

    // Insert 5 nodes at the beginning
    insert_begin(&head, 1);
    insert_begin(&head, 2);
    insert_begin(&head, 3);
    insert_begin(&head, 4);
    insert_begin(&head, 5);

    // Insert 5 nodes at the end
    insert_end(&head, 6);
    insert_end(&head, 7);
    insert_end(&head, 8);
    insert_end(&head, 9);
    insert_end(&head, 10);

    // Insert 5 nodes at a given position
    insert_pos(&head, 3, 11);
    insert_pos(&head, 8, 12);
    insert_pos(&head, 2, 13);
    insert_pos(&head, 4, 14);
    insert_pos(&head, 9, 15);

    // Display the linked list
    display(&head);

    // Delete 5 nodes from the beginning
    delete_begin(&head);
    delete_begin(&head);
    delete_begin(&head);
    delete_begin(&head);
    delete_begin(&head);

    // Delete 5 nodes from the end
    delete_end(&head);
    delete_end(&head);
    delete_end(&head);
    delete_end(&head);
    delete_end(&head);

    // Delete 5 nodes from a given position
    delete_pos(&head, 3);
    delete_pos(&head, 8);
    delete_pos(&head, 2);
    delete_pos(&head, 4);
    delete_pos(&head, 9);

    // Display the linked list
    display(&head);

    return 0;
}