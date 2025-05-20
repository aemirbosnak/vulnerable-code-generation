//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define the structure of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of a queue
typedef struct queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new queue
Queue* create_queue() {
    Queue* new_queue = (Queue*)malloc(sizeof(Queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->size = 0;
    return new_queue;
}

// Function to check if the queue is empty
int is_empty(Queue* queue) {
    return queue->front == NULL;
}

// Function to check if the queue is full
int is_full(Queue* queue) {
    return queue->size == MAX_SIZE;
}

// Function to enqueue data into the queue
void enqueue(Queue* queue, int data) {
    Node* new_node = create_node(data);
    if (is_full(queue)) {
        printf("Queue is full. Cannot enqueue data.\n");
        return;
    }
    if (is_empty(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
}

// Function to dequeue data from the queue
int dequeue(Queue* queue) {
    int data = -1;
    if (is_empty(queue)) {
        printf("Queue is empty. Cannot dequeue data.\n");
        return data;
    }
    Node* temp_node = queue->front;
    data = temp_node->data;
    queue->front = temp_node->next;
    free(temp_node);
    queue->size--;
    if (is_empty(queue)) {
        queue->front = NULL;
        queue->rear = NULL;
    }
    return data;
}

// Function to display the queue
void display_queue(Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp_node = queue->front;
    printf("Queue: ");
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = create_queue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display_queue(queue);
    dequeue(queue);
    display_queue(queue);
    dequeue(queue);
    display_queue(queue);
    dequeue(queue);
    dequeue(queue);
    display_queue(queue);
    return 0;
}