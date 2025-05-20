//FormAI DATASET v1.0 Category: Queue Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the Queue struct
typedef struct {
    int front;
    int rear;
    int size;
    int* arr;
} Queue;

// Function to create a Queue
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->arr = (int*)malloc(size * sizeof(int));
    return queue;
}

// Function to check if Queue is full
int isFull(Queue* queue) {
    return queue->rear == queue->size - 1;
}

// Function to check if Queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to add element to Queue
void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }
    queue->arr[++queue->rear] = data;
    if (queue->front == -1) {
        queue->front = 0;
    }
}

// Function to remove element from Queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = queue->arr[queue->front++];
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return data;
}

// Function to print Queue
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int size, choice, data;
    printf("Enter size of Queue: ");
    scanf("%d", &size);
    Queue* queue = createQueue(size);
    while (1) {
        printf("\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &data);
            enqueue(queue, data);
            break;
        case 2:
            data = dequeue(queue);
            if (data != -1) {
                printf("Dequeued element: %d\n", data);
            }
            break;
        case 3:
            printQueue(queue);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}