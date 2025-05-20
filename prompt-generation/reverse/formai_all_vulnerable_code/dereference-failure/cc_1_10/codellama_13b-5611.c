//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: multi-threaded
// Linked list operations example program in a multi-threaded style
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to represent a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Global variables
struct node *head = NULL;
struct node *tail = NULL;
int list_size = 0;

// Function to insert a node at the end of the list
void insert_at_end(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    list_size++;
}

// Function to insert a node at the beginning of the list
void insert_at_beginning(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    list_size++;
}

// Function to insert a node after a given node
void insert_after(struct node *prev, int data) {
    if (prev == NULL) {
        printf("Invalid node\n");
        return;
    }

    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
    list_size++;
}

// Function to delete a node from the list
void delete_node(struct node *del) {
    if (del == NULL) {
        printf("Invalid node\n");
        return;
    }

    if (del == head) {
        head = del->next;
    } else {
        struct node *prev = head;
        while (prev->next != del) {
            prev = prev->next;
        }
        prev->next = del->next;
    }
    free(del);
    list_size--;
}

// Function to traverse the list
void traverse() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for a node in the list
struct node *search(int key) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Main function
int main() {
    // Insert nodes at the beginning and end of the list
    insert_at_beginning(1);
    insert_at_end(10);
    insert_at_end(20);
    insert_at_beginning(5);

    // Insert nodes after a given node
    insert_after(search(1), 3);
    insert_after(search(5), 6);
    insert_after(search(10), 15);
    insert_after(search(20), 25);

    // Delete a node from the list
    delete_node(search(15));

    // Traverse the list
    traverse();

    // Search for a node in the list
    struct node *found = search(6);
    if (found != NULL) {
        printf("Found %d at %p\n", found->data, found);
    } else {
        printf("Node not found\n");
    }

    return 0;
}