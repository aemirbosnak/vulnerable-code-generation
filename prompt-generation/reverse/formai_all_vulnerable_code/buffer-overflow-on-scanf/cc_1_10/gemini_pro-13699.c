//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *createNode(int data) {
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL) {
        perror("malloc");
        exit(1);
    }
    n->data = data;
    n->next = NULL;
    return n;
}

void printList(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    node *head = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        node *new_node = createNode(data);
        if (head == NULL) {
            head = new_node;
        } else {
            node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    printList(head);

    return 0;
}