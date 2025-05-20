//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: surprised
/*
 * Unique C Queue Implementation Example Program
 *
 * Author: [Your Name]
 * Date:   [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Structure for a queue
typedef struct {
    node_t *front;
    node_t *rear;
    int size;
} queue_t;

// Function to create a new queue
queue_t* create_queue() {
    queue_t *q = malloc(sizeof(queue_t));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to enqueue an element
void enqueue(queue_t *q, int element) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = element;
    new_node->next = NULL;

    if (q->size == 0) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }

    q->size++;
}

// Function to dequeue an element
int dequeue(queue_t *q) {
    if (q->size == 0) {
        return -1;
    }

    node_t *temp = q->front;
    int element = temp->data;

    if (q->size == 1) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = temp->next;
    }

    free(temp);
    q->size--;
    return element;
}

// Function to display the queue
void display(queue_t *q) {
    node_t *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue_t *q = create_queue();

    // Enqueue some elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    // Dequeue an element
    int element = dequeue(q);
    printf("Dequeued element: %d\n", element);

    // Display the queue
    display(q);

    // Enqueue another element
    enqueue(q, 40);

    // Display the queue again
    display(q);

    // Dequeue all elements
    while (q->size > 0) {
        dequeue(q);
    }

    // Display the queue again
    display(q);

    return 0;
}