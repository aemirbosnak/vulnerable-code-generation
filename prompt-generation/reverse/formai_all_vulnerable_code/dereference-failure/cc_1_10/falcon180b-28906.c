//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of the queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new queue
Queue* create_queue() {
    Queue* new_queue = (Queue*)malloc(sizeof(Queue));
    if (new_queue == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

// Function to check if the queue is empty
int is_empty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* new_node = create_node(data);
    if (is_empty(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    int data;
    Node* temp_node;
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    temp_node = queue->front;
    data = temp_node->data;
    queue->front = temp_node->next;
    free(temp_node);
    return data;
}

// Function to display the elements of the queue
void display(Queue* queue) {
    Node* temp_node = queue->front;
    printf("Queue elements are: ");
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    Queue* queue = create_queue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    return 0;
}