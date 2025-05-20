//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure definition
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to check if the queue is full
bool isFull(Queue* q) {
    return (q->size == MAX_SIZE);
}

// Function to enqueue an element
void enqueue(Queue* q, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    temp->data = value;
    temp->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

// Function to dequeue an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(0);
    }
    int value = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return value;
}

// Function to display the queue elements
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements are: ");
        Node* temp = q->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    int value = dequeue(q);
    printf("Dequeued value is: %d\n", value);
    display(q);
    return 0;
}