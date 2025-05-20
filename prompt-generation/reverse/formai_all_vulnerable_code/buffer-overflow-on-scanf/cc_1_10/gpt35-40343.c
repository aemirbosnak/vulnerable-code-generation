//FormAI DATASET v1.0 Category: Data structures visualization ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->front = 0;
    newQueue->rear = -1;
    return newQueue;
}

void enqueue(Queue* q, int value) {
    if(q->rear == MAX_QUEUE_SIZE-1) {
        printf("Queue is full!\n");
    } else {
        q->rear++;
        q->data[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    if(q->front > q->rear) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int dequeuedValue = q->data[q->front];
        q->front++;
        return dequeuedValue;
    }
}

void displayQueue(Queue* q) {
    int i;
    printf("Front -> ");
    for(i=q->front;i<=q->rear;i++) {
        printf("%d ", q->data[i]);
    }
    printf("-> Rear\n");
}

int main() {
    Queue* queue = createQueue();
    int value, choice;
    do {
        printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                printf("Dequeued value: %d\n", dequeue(queue));
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);
    return 0;
}