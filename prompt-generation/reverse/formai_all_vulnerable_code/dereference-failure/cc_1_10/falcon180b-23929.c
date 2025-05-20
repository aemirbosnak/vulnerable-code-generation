//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure for linked list implementation of queue
struct Node {
    int data;
    struct Node *next;
};

// Queue structure
struct Queue {
    struct Node *front;
    struct Node *rear;
};

// Function to create an empty queue
void createQueue(struct Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->front == NULL;
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    struct Node *temp = q->front;
    int count = 0;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return count == MAX_SIZE;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue *q, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue *q) {
    int data;
    struct Node *temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        data = temp->data;
        q->front = temp->next;
        free(temp);
    }

    return data;
}

// Function to display the contents of the queue
void display(struct Queue *q) {
    struct Node *temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Queue after adding elements: ");
    display(&q);

    int data = dequeue(&q);
    printf("Element removed from queue: %d\n", data);

    printf("Queue after removing element: ");
    display(&q);

    return 0;
}