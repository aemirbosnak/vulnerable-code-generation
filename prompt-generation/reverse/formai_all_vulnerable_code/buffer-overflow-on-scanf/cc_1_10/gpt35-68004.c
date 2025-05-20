//FormAI DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, i, value;
    struct node *new_node, *head, *temp;

    printf("Enter the number of nodes to be created: ");
    scanf("%d", &n);

    // Allocate memory for the head node
    head = (struct node *) malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory cannot be allocated");
        exit(0);
    }

    // Get the data for the head node
    printf("Enter data for node 1: ");
    scanf("%d", &value);
    head->data = value;
    head->next = NULL;

    // Create n-1 nodes and link them together
    temp = head;
    for (i = 2; i <= n; i++) {
        new_node = (struct node *) malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Memory cannot be allocated");
            exit(0);
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        new_node->data = value;
        new_node->next = NULL;
        temp->next = new_node;
        temp = temp->next;
    }

    // traverse the linked list and print the data of each node
    printf("The linked list is: ");
    temp = head;
    while (temp != NULL) {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Free the memory allocated to each node
    temp = head;
    while (temp != NULL) {
        struct node *to_free = temp;
        temp = temp->next;
        free(to_free);
    }

    return 0;
}