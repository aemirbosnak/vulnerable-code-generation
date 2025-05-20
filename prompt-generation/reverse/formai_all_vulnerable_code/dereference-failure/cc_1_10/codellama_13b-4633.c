//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: detailed
// Program to demonstrate a unique C Network Topology Mapper example
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store network topology information
struct node {
    char name[10];
    struct node* next;
};

// Function to add a new node to the network topology
void add_node(struct node** head, char* name) {
    struct node* new_node = malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    new_node->next = NULL;

    // If the list is empty, add the new node to the head
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print the network topology
void print_network_topology(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%s -> ", current->name);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a new network topology
    struct node* head = NULL;
    add_node(&head, "A");
    add_node(&head, "B");
    add_node(&head, "C");
    add_node(&head, "D");

    // Print the network topology
    print_network_topology(head);

    // Free the memory allocated for the network topology
    struct node* current = head;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}