//FormAI DATASET v1.0 Category: Queue Implementation ; Style: mathematical
// Mathematical Style Implementation of a Queue in C
// Using a Circular Linked List

#include <stdio.h>
#include <stdlib.h>

// Define a struct for the Queue node
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// Define a struct for the Queue
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Function to create a new QueueNode
QueueNode* createQueueNode(int data) {
    QueueNode* newNode = (QueueNode*) malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new Queue
Queue* createQueue() {
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

// Function to check if the Queue is empty
int isQueueEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Function to add (enqueue) a new element to the Queue
void enqueue(Queue* queue, int data) {
    QueueNode* newNode = createQueueNode(data);
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->rear->next = queue->front;
}

// Function to remove (dequeue) an element from the Queue
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue underflow!\n");
        return 0;
    } else {
        int data = queue->front->data;
        QueueNode* temp = queue->front;
        if (queue->front == queue->rear) {
            queue->front = NULL;
            queue->rear = NULL;
        } else {
            queue->front = queue->front->next;
            queue->rear->next = queue->front;
        }
        free(temp);
        return data;
    }
}

// Function to print the Queue elements
void printQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        QueueNode* currentNode = queue->front;
        do {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        } while (currentNode != queue->front);
        printf("\n");
    }
}

// Main function
int main() {
    Queue* queue = createQueue();
    int choice, data;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                if (data) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                printf("Queue: ");
                printQueue(queue);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}