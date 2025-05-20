//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
/*
 * Cyberpunk Data Structures Visualization
 *
 * By: Anonymous
 * Date: 2023-03-17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <pthread.h>
#include <semaphore.h>

/* Structures */

// Linked list node structure
struct Node {
    int data;
    struct Node *next;
};

// Queue structure
struct Queue {
    struct Node *front;
    struct Node *rear;
};

/* Functions */

// Creates a new node with the given data
struct Node *create_node(int data) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Creates a new queue
struct Queue *create_queue() {
    struct Queue *queue = malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Enqueues the given data into the queue
void enqueue(struct Queue *queue, int data) {
    struct Node *node = create_node(data);
    if (queue->front == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

// Dequeues the front data from the queue
int dequeue(struct Queue *queue) {
    if (queue->front == NULL) {
        return -1;
    }
    struct Node *node = queue->front;
    int data = node->data;
    queue->front = node->next;
    free(node);
    return data;
}

// Checks if the queue is empty
bool is_empty(struct Queue *queue) {
    return queue->front == NULL;
}

// Displays the queue
void display(struct Queue *queue) {
    struct Node *node = queue->front;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Main function */

int main() {
    struct Queue *queue = create_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    display(queue);
    dequeue(queue);
    display(queue);
    return 0;
}