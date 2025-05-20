//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int value;
    struct node *next;
};

// Function to create a new node with the given value
struct node *create_node(int value) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node at the end of the list
void add_node(struct node **head_ref, int new_data) {
    struct node *new_node = create_node(new_data);
    struct node *last = *head_ref;
    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next!= NULL)
        last = last->next;
    last->next = new_node;
    return;
}

// Function to print the list
void print_list(struct node *node) {
    while (node!= NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
}

// Main function
int main() {
    struct node *head = NULL;
    int n, i, pos;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pos);
        add_node(&head, pos);
    }
    printf("The list is:\n");
    print_list(head);
    return 0;
}