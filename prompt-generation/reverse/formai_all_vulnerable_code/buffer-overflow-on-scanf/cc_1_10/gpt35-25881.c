//FormAI DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5 // maximum size of queue array

// declare queue data structure
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// function to check if queue is full
int isFull(struct Queue* queue) {
    if ((queue->rear + 1) % MAX_SIZE == queue->front)
        return 1;
    else
        return 0;
}

// function to check if queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->front == -1)
        return 1;
    else
        return 0;
}

// function to add element to queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = value;
        printf("Enqueued %d to queue.\n", value);
    }
}

// function to remove element from queue
int dequeue(struct Queue* queue) {
    int value;
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    else {
        value = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        }
        else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        printf("Dequeued %d from queue.\n", value);
        return value;
    }
}

int main() {
    int choice, value;
    struct Queue* queue = createQueue();
    printf("Welcome to our irregular style C queue program!\n");
    while (1) {
        printf("\n<<<< MENU >>>>\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be added to queue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}