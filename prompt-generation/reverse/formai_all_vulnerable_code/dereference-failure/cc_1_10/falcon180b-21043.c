//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

int isFull(Queue* queue) {
    return (queue->size == MAX_SIZE);
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
    int data = -1;

    if (!isEmpty(queue)) {
        Node* temp = queue->front;
        data = temp->data;
        queue->front = temp->next;
        free(temp);
        queue->size--;
    }

    return data;
}

void display(Queue* queue) {
    Node* temp = queue->front;

    printf("Queue: ");

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
    printf("Dequeued data: %d\n", dequeuedData);

    display(queue);

    dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);

    display(queue);

    dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);

    display(queue);

    dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);

    display(queue);

    return 0;
}