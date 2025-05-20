//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: scalable
/*
 * Queue implementation using a doubly-linked list
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Node structure for the doubly-linked list
 */
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node_t;

/*
 * Queue structure
 */
typedef struct queue {
    node_t *head;
    node_t *tail;
    int size;
} queue_t;

/*
 * Initialize the queue
 */
void init_queue(queue_t *q) {
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

/*
 * Enqueue an element at the end of the queue
 */
void enqueue(queue_t *q, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (q->tail == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        new_node->prev = q->tail;
        q->tail = new_node;
    }

    q->size++;
}

/*
 * Dequeue an element from the front of the queue
 */
int dequeue(queue_t *q) {
    if (q->head == NULL) {
        return -1;
    }

    node_t *old_head = q->head;
    int data = old_head->data;

    if (q->head == q->tail) {
        q->head = NULL;
        q->tail = NULL;
    } else {
        q->head = q->head->next;
        q->head->prev = NULL;
    }

    free(old_head);
    q->size--;

    return data;
}

/*
 * Print the elements of the queue
 */
void print_queue(queue_t *q) {
    node_t *curr = q->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    queue_t q;
    init_queue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    print_queue(&q);

    int data = dequeue(&q);
    printf("Dequeued %d\n", data);

    print_queue(&q);

    return 0;
}