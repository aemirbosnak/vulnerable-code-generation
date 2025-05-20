//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_node(int data) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Could not allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node *insert_node(node *head, int data) {
    node *new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    return head;
}

void print_list(node *head) {
    node *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void free_list(node *head) {
    node *current_node = head;
    while (current_node != NULL) {
        node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
}

int main() {
    int num_terms;
    printf("Enter the number of terms you want in the Fibonacci sequence: ");
    scanf("%d", &num_terms);

    node *head = NULL;
    head = insert_node(head, 0);
    head = insert_node(head, 1);

    int i;
    for (i = 2; i < num_terms; i++) {
        node *current_node = head;
        int sum = 0;
        while (current_node != NULL) {
            sum += current_node->data;
            current_node = current_node->next;
        }
        head = insert_node(head, sum);
    }

    print_list(head);

    free_list(head);

    return 0;
}