//FormAI DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure representing the Queue
typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
} Queue;

// Function to create a Queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->arr = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if Queue is empty
bool isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Function to check if Queue is full
bool isFull(Queue *queue) {
    return ((queue->rear + 1) % queue->capacity) == queue->front;
}

// Function to add an item to the Queue
void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
        queue->arr[queue->rear] = item;
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->arr[queue->rear] = item;
    }
}

// Function to remove an item from the Queue
void dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
}

// Function to print the items in the Queue
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Items in Queue: ");
    int i = queue->front;
    while (true) {
        printf("%d ", queue->arr[i]);
        if (i == queue->rear) break;
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}

int main() {
    int capacity, choice, item;
    printf("Enter the capacity of Queue: ");
    scanf("%d", &capacity);
    Queue *queue = createQueue(capacity);

    while (true) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter an item to add to the Queue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}