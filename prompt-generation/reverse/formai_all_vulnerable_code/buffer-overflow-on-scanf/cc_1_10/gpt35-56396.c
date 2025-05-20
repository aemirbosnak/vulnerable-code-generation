//FormAI DATASET v1.0 Category: Queue ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Defining the struct for the queue
struct Queue {
    int front, rear, size;
    int *arr;
};

// Function to create a new queue
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->arr = (int*) malloc(size * sizeof(int));
    return queue;
}

// Function to check if queue is empty or not
int isEmpty(struct Queue* queue) {
    if (queue->front == -1 && queue->rear == -1)
        return 1;
    else
        return 0;
}

// Function to check if queue is full or not
int isFull(struct Queue* queue) {
    if ((queue->rear+1)%queue->size == queue->front)
        return 1;
    else
        return 0;
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int element) {
    if (isFull(queue))
        printf("Queue is full.");
    else if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
        queue->arr[queue->rear] = element;
    } else {
        queue->rear = (queue->rear+1)%queue->size;
        queue->arr[queue->rear] = element;
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue is empty.");
        return -1;
    } else if (queue->front == queue->rear) {
        element = queue->arr[queue->front];
        queue->front = -1;
        queue->rear = -1;
        return element;
    } else {
        element = queue->arr[queue->front];
        queue->front = (queue->front+1)%queue->size;
        return element;
    }
}

// Function to display the queue
void display(struct Queue* queue) {
    int i;
    if (isEmpty(queue))
        printf("Queue is empty.");
    else {
        for (i=queue->front; i<=queue->rear; i++)
            printf("%d ", queue->arr[i]);
    }
}

// The main function
int main() {
    int size, choice, element;
    printf("Enter size of queue: ");
    scanf("%d", &size);
    struct Queue* queue = createQueue(size);
    while (1) {
        printf("\n1 - Enqueue");
        printf("\n2 - Dequeue");
        printf("\n3 - Display");
        printf("\n4 - Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(queue, element);
                break;
            case 2:
                element = dequeue(queue);
                if (element != -1)
                    printf("%d dequeued from queue.", element);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.");
        }
    }
    return 0;
}