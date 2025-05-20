//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Queue structure definition
struct queue {
    struct node* front;
    struct node* rear;
};

// Function to create a new node with given data
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create an empty queue
struct queue* create_queue() {
    struct queue* new_queue = (struct queue*) malloc(sizeof(struct queue));
    if (!new_queue) {
        printf("Memory error\n");
        exit(0);
    }
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

// Function to check if the queue is empty
int is_empty(struct queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element into the queue
void enqueue(struct queue* queue, int data) {
    struct node* new_node = create_node(data);
    if (is_empty(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->front->data;
    struct node* temp_node = queue->front;
    queue->front = queue->front->next;
    free(temp_node);
    if (is_empty(queue)) {
        queue->rear = NULL;
    }
    return data;
}

// Function to display the elements in the queue
void display(struct queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    struct node* temp_node = queue->front;
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct queue* queue = create_queue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    return 0;
}