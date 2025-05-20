//Code Llama-13B DATASET v1.0 Category: Threading Library Implementation ; Style: optimized
/*
 * A unique C Threading Library Implementation example program in an optimized style.
 *
 * This program demonstrates how to create a thread-safe queue data structure in C,
 * using the pthread library and a mutex lock.
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the structure of a node in the queue
typedef struct node {
    void *data;
    struct node *next;
} node_t;

// Define the structure of the queue
typedef struct {
    node_t *head;
    node_t *tail;
    pthread_mutex_t lock;
} queue_t;

// Function to create a new node in the queue
node_t* create_node(void *data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a new node to the tail of the queue
void enqueue(queue_t *queue, void *data) {
    // Create a new node
    node_t *node = create_node(data);

    // Lock the mutex
    pthread_mutex_lock(&queue->lock);

    // Add the node to the tail of the queue
    if (queue->tail == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }

    // Unlock the mutex
    pthread_mutex_unlock(&queue->lock);
}

// Function to remove a node from the head of the queue
void* dequeue(queue_t *queue) {
    // Lock the mutex
    pthread_mutex_lock(&queue->lock);

    // Check if the queue is empty
    if (queue->head == NULL) {
        pthread_mutex_unlock(&queue->lock);
        return NULL;
    }

    // Get the data from the head node
    void *data = queue->head->data;

    // Remove the head node from the queue
    node_t *temp = queue->head;
    queue->head = queue->head->next;
    free(temp);

    // Unlock the mutex
    pthread_mutex_unlock(&queue->lock);

    return data;
}

// Function to free all nodes in the queue
void destroy_queue(queue_t *queue) {
    // Lock the mutex
    pthread_mutex_lock(&queue->lock);

    // Free all nodes in the queue
    node_t *node = queue->head;
    while (node != NULL) {
        node_t *temp = node;
        node = node->next;
        free(temp);
    }

    // Unlock the mutex
    pthread_mutex_unlock(&queue->lock);
}

int main() {
    // Create a new queue
    queue_t *queue = malloc(sizeof(queue_t));
    queue->head = NULL;
    queue->tail = NULL;
    pthread_mutex_init(&queue->lock, NULL);

    // Add some data to the queue
    enqueue(queue, "Hello");
    enqueue(queue, "World");

    // Remove some data from the queue
    void *data1 = dequeue(queue);
    void *data2 = dequeue(queue);

    // Print the data
    printf("%s %s\n", (char *)data1, (char *)data2);

    // Free the queue
    destroy_queue(queue);

    return 0;
}