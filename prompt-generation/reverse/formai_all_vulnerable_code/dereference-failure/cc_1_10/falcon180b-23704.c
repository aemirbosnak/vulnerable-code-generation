//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the queue
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of the queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Initialize the queue
void init(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
int is_empty(Queue* q) {
    return q->front == NULL;
}

// Enqueue an element to the rear of the queue
void enqueue(Queue* q, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Dequeue an element from the front of the queue
int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    if (is_empty(q)) {
        q->rear = NULL;
    }
    return data;
}

// Display the elements in the queue
void display(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);
    return 0;
}