//FormAI DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Queue implementation using C array
typedef struct queue {
    int* array;
    int front;
    int rear;
    int capacity;
    int size;
} Queue;

// Function to create a queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue -> front = 0;
    queue -> rear = capacity - 1;
    queue -> capacity = capacity;
    queue -> size = 0;
    queue -> array = (int*) malloc(queue -> capacity * sizeof(int));
    return queue;
}

// Function to check if queue is full
int isFull(Queue* queue) {
    return (queue -> size == queue -> capacity);
}

// Function to check if queue is empty
int isEmpty(Queue* queue) {
    return (queue -> size == 0);
}

// Function to enqueue element
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }

    queue -> rear = (queue -> rear + 1) % queue -> capacity;
    queue -> array[queue -> rear] = item;
    queue -> size++;
    printf("%d enqueued to queue\n", item);
}

// Function to dequeue element
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }

    int item = queue -> array[queue -> front];
    queue -> front = (queue -> front + 1) % queue -> capacity;
    queue -> size--;
    printf("%d dequeued from queue\n", item);
    return item;
}

// Function to get front element without dequeueing
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front element\n");
        return -1;
    }

    return queue -> array[queue -> front];
}

// Function to get rear element without dequeueing
int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No rear element\n");
        return -1;
    }

    return queue -> array[queue -> rear];
}

int main() {
    int capacity, choice, item;
    printf("Enter queue capacity: ");
    scanf("%d", &capacity);

    Queue* queue = createQueue(capacity);

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Rear\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;

            case 2:
                dequeue(queue);
                break;

            case 3:
                printf("Front: %d\n", front(queue));
                break;

            case 4:
                printf("Rear: %d\n", rear(queue));
                break;

            case 5:
                printf("Exiting..\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}