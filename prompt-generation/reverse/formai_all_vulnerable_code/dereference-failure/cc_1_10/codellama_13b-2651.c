//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: futuristic
// Futuristic Data Structures Visualization Example Program
#include <stdio.h>
#include <stdlib.h>

// Structure for storing data
struct data_node {
    int data;
    struct data_node *next;
};

// Structure for storing nodes
struct node {
    struct data_node *head;
    struct data_node *tail;
    struct node *next;
};

// Function to print the data structure
void print_data_struct(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        struct data_node *current_data = current->head;
        while (current_data != NULL) {
            printf("%d ", current_data->data);
            current_data = current_data->next;
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add a new node to the end of the list
void add_node(struct node **head, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->head = malloc(sizeof(struct data_node));
    new_node->head->data = data;
    new_node->head->next = NULL;
    new_node->tail = new_node->head;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to add a new data node to the end of the list
void add_data_node(struct node **head, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->head = malloc(sizeof(struct data_node));
    new_node->head->data = data;
    new_node->head->next = NULL;
    new_node->tail = new_node->head;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->tail->next = new_node->head;
        current->tail = new_node->tail;
    }
}

// Function to delete a node from the list
void delete_node(struct node **head, int data) {
    struct node *current = *head;
    while (current != NULL) {
        if (current->head->data == data) {
            struct node *temp = current->next;
            free(current->head);
            free(current);
            current = temp;
        }
        current = current->next;
    }
}

// Function to delete a data node from the list
void delete_data_node(struct node **head, int data) {
    struct node *current = *head;
    while (current != NULL) {
        if (current->head->data == data) {
            struct data_node *temp = current->head->next;
            free(current->head);
            current->head = temp;
        }
        current = current->next;
    }
}

int main() {
    struct node *head = NULL;

    // Add nodes to the list
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);

    // Add data nodes to the list
    add_data_node(&head, 6);
    add_data_node(&head, 7);
    add_data_node(&head, 8);
    add_data_node(&head, 9);
    add_data_node(&head, 10);

    // Print the list
    print_data_struct(head);

    // Delete a node
    delete_node(&head, 3);

    // Delete a data node
    delete_data_node(&head, 7);

    // Print the list again
    print_data_struct(head);

    return 0;
}