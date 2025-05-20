//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

void initQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

bool isEmpty(struct Queue* queue) {
    if (queue->front == NULL && queue->rear == NULL) {
        return true;
    } else {
        return false;
    }
}

bool isFull(struct Queue* queue) {
    if (queue->size == MAX_SIZE) {
        return true;
    } else {
        return false;
    }
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(0);
    }
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    struct Node* temp = queue->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initQueue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    display(&queue);
    printf("Size of the queue is %d\n", queue.size);
    int dequeuedData = dequeue(&queue);
    printf("Dequeued data is %d\n", dequeuedData);
    display(&queue);
    printf("Size of the queue is %d\n", queue.size);
    dequeue(&queue);
    dequeue(&queue);
    display(&queue);
    printf("Size of the queue is %d\n", queue.size);
    return 0;
}