//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    if (queue->front == NULL && queue->rear == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    if (queue->size == MAX_QUEUE_SIZE) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = data;
    node->next = NULL;
    if (isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    }
    else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    int data;
    QueueNode* node = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    else {
        data = node->data;
        queue->front = node->next;
        free(node);
        queue->size--;
        return data;
    }
}

// Function to print the elements of the queue
void printQueue(Queue* queue) {
    QueueNode* node = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    }
    else {
        printf("Queue elements are:\n");
        while (node!= NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    Queue* queue = createQueue();
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print queue\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue:\n");
                scanf("%d", &data);
                enqueue(queue, data);
                printf("Data enqueued successfully!\n");
                break;
            case 2:
                data = dequeue(queue);
                if (data!= -1) {
                    printf("Data dequeued successfully: %d\n", data);
                }
                break;
            case 3:
                printQueue(queue);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    free(queue);
    return 0;
}