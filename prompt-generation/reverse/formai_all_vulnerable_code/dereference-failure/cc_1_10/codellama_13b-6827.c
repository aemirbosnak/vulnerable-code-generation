//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: innovative
// Innovative C Queue Implementation

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
    int size;
};

// Initialize the queue
void init_queue(struct queue *q) {
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

// Enqueue an element
void enqueue(struct queue *q, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->tail == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }

    q->size++;
}

// Dequeue an element
int dequeue(struct queue *q) {
    if (q->head == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    struct node *old_head = q->head;
    q->head = q->head->next;
    int data = old_head->data;
    free(old_head);

    q->size--;
    return data;
}

// Display the queue
void display(struct queue *q) {
    struct node *current = q->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct queue q;
    init_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(&q);

    int data = dequeue(&q);
    printf("Dequeued %d\n", data);
    display(&q);

    return 0;
}