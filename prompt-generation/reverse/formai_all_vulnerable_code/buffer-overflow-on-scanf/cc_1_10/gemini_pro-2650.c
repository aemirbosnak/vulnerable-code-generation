//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the Fibonacci sequence
struct fib_node {
    int value;
    struct fib_node *next;
};

// Function to create a new Fibonacci node with the given value
struct fib_node *create_fib_node(int value) {
    struct fib_node *node = malloc(sizeof(struct fib_node));
    node->value = value;
    node->next = NULL;
    return node;
}

// Function to insert a new node into the Fibonacci sequence
void insert_fib_node(struct fib_node **head, struct fib_node *node) {
    if (*head == NULL) {
        *head = node;
    } else {
        node->next = *head;
        *head = node;
    }
}

// Function to generate the first n Fibonacci numbers
struct fib_node *generate_fib_sequence(int n) {
    struct fib_node *head = NULL;
    int a = 0, b = 1, c;

    for (int i = 0; i < n; i++) {
        c = a + b;
        struct fib_node *node = create_fib_node(c);
        insert_fib_node(&head, node);

        a = b;
        b = c;
    }

    return head;
}

// Function to print the Fibonacci sequence
void print_fib_sequence(struct fib_node *head) {
    struct fib_node *current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

// Function to free the memory allocated for the Fibonacci sequence
void free_fib_sequence(struct fib_node *head) {
    struct fib_node *current = head;
    struct fib_node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    int n;

    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    struct fib_node *head = generate_fib_sequence(n);

    printf("The Fibonacci sequence is: ");
    print_fib_sequence(head);

    free_fib_sequence(head);

    return 0;
}