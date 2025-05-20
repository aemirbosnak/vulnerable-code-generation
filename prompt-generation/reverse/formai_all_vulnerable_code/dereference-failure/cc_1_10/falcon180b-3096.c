//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }

    Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;

    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

void display(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
    } else {
        Node* temp = queue->front;
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    printf("Queue elements after enqueue:\n");
    display(&queue);

    int dequeuedElement = dequeue(&queue);
    printf("Dequeued element: %d\n", dequeuedElement);

    printf("Queue elements after dequeue:\n");
    display(&queue);

    return 0;
}