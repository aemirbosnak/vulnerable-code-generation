//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: innovative
/*
 * Innovative Queue Implementation
 *
 * This implementation uses a doubly-linked list to store the queue.
 * The list is circular, with the tail node pointing to the head node.
 * This allows for constant-time insertion and removal of elements.
 */

#include <stdlib.h>
#include <stdio.h>

// Struct for a node in the linked list
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

// Struct for the queue
struct queue {
    struct node *head;
    struct node *tail;
};

// Function to create a new node
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to create a new queue
struct queue *create_queue() {
    struct queue *new_queue = malloc(sizeof(struct queue));
    new_queue->head = NULL;
    new_queue->tail = NULL;
    return new_queue;
}

// Function to insert an element at the back of the queue
void enqueue(struct queue *queue, int data) {
    struct node *new_node = create_node(data);
    if (queue->head == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        new_node->prev = queue->tail;
        queue->tail = new_node;
    }
}

// Function to remove the element at the front of the queue
int dequeue(struct queue *queue) {
    if (queue->head == NULL) {
        return -1;
    } else {
        struct node *head = queue->head;
        queue->head = head->next;
        if (queue->head != NULL) {
            queue->head->prev = NULL;
        } else {
            queue->tail = NULL;
        }
        int data = head->data;
        free(head);
        return data;
    }
}

// Function to print the contents of the queue
void print_queue(struct queue *queue) {
    struct node *node = queue->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct queue *queue = create_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    dequeue(queue);
    print_queue(queue);
    return 0;
}