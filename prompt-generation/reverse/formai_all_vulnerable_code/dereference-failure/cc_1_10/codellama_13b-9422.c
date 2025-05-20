//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
/*
 * Linus Torvalds' Queue Implementation
 */

#include <stdio.h>
#include <stdlib.h>

struct queue {
    void *data;
    struct queue *next;
};

void enqueue(struct queue **head, void *data) {
    struct queue *new_node = malloc(sizeof(struct queue));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct queue *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

void *dequeue(struct queue **head) {
    if (*head == NULL) {
        return NULL;
    }

    struct queue *curr = *head;
    void *data = curr->data;
    *head = curr->next;
    free(curr);
    return data;
}

int main() {
    struct queue *head = NULL;

    enqueue(&head, "Hello, World!");
    enqueue(&head, "This is a test");
    enqueue(&head, "Another test");

    printf("%s\n", (char *)dequeue(&head));
    printf("%s\n", (char *)dequeue(&head));
    printf("%s\n", (char *)dequeue(&head));

    return 0;
}