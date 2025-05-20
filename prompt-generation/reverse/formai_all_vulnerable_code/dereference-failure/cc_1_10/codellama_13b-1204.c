//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
/*
 * Mind-bending queue implementation example
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void enqueue(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int dequeue(node **head) {
    if (*head == NULL) {
        return -1;
    }

    node *temp = *head;
    int data = temp->data;
    *head = temp->next;
    free(temp);
    return data;
}

void print_queue(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;
    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    enqueue(&head, 4);
    enqueue(&head, 5);

    print_queue(head);

    int data = dequeue(&head);
    printf("Dequeued %d\n", data);

    print_queue(head);

    return 0;
}