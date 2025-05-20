//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;
    return newQueue;
}

bool isEmpty(Queue* queue) {
    if (queue->front == NULL && queue->rear == NULL) {
        return true;
    }
    return false;
}

bool isFull(Queue* queue) {
    if (queue->size >= MAX_QUEUE_SIZE) {
        return true;
    }
    return false;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
}

int dequeue(Queue* queue) {
    Node* temp = queue->front;
    int data = temp->data;

    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    queue->front = temp->next;

    if (isEmpty(queue)) {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;

    return data;
}

void display(Queue* queue) {
    Node* temp = queue->front;

    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    display(queue);

    int dequeuedData = dequeue(queue);
    printf("Dequeued data is: %d\n", dequeuedData);

    display(queue);

    int frontData = queue->front->data;
    printf("Front data is: %d\n", frontData);

    return 0;
}