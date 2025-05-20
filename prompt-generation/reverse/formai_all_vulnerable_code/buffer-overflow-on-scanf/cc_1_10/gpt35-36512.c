//FormAI DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *allocate_node(int data, Node *next) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (!new_node) {
        printf("Failed to allocate memory for new node\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = next;
    return new_node;
}

void free_list(Node *head) {
    while (head) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main() {
    int n, data;
    Node *head, *prev, *curr;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = NULL;
    prev = NULL;
    for (int i = 0; i < n; i++) {
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);

        curr = allocate_node(data, NULL);
        if (!curr) {
            free_list(head);
            return 1;
        }

        if (!head) {
            head = curr;
        } else {
            prev->next = curr;
        }
        prev = curr;
    }

    printf("The list is:\n");
    curr = head;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    free_list(head);

    return 0;
}