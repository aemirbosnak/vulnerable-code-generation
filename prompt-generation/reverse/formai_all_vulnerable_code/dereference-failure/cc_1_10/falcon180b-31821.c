//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Node structure
struct node {
    double value;
    struct node *next;
};

// Function prototypes
void add_node(struct node **head, double value);
void delete_node(struct node **head);
void print_nodes(struct node *head);

// Main function
int main() {
    struct node *head = NULL;

    // Add nodes
    add_node(&head, 1.0);
    add_node(&head, 2.0);
    add_node(&head, 3.0);

    // Print nodes
    print_nodes(head);

    // Delete node
    delete_node(&head);

    // Print nodes
    print_nodes(head);

    return 0;
}

// Add node function
void add_node(struct node **head, double value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

// Delete node function
void delete_node(struct node **head) {
    struct node *temp = *head;
    if (temp!= NULL) {
        *head = temp->next;
        free(temp);
    }
}

// Print nodes function
void print_nodes(struct node *head) {
    while (head!= NULL) {
        printf("%lf ", head->value);
        head = head->next;
    }
    printf("\n");
}