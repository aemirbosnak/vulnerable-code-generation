//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 5

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = INITIAL_CAPACITY;
    return queue;
}

int isFull(Queue *queue) {
    return queue->size == queue->capacity;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

void resizeQueue(Queue *queue) {
    int newCapacity = queue->capacity * 2;
    int *newData = (int*)malloc(newCapacity * sizeof(int));

    for (int i = 0; i < queue->size; i++) {
        newData[i] = queue->data[(queue->front + i) % queue->capacity];
    }

    free(queue->data);
    queue->data = newData;
    queue->front = 0;
    queue->rear = queue->size - 1;
    queue->capacity = newCapacity;
}

void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        resizeQueue(queue);
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = value;
    if (queue->front == -1) {
        queue->front = queue->rear;
    }
    queue->size++;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    if (isEmpty(queue)) {
        queue->front = queue->rear = -1;
    }
    return value;
}

void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->data[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

void freeQueue(Queue *queue) {
    free(queue->data);
    free(queue);
}

int main() {
    Queue *queue = createQueue();
    int choice, value;

    do {
        printf("\n=== Circular Queue Menu ===\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                printf("%d enqueued.\n", value);
                break;

            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("%d dequeued.\n", value);
                }
                break;

            case 3:
                displayQueue(queue);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeQueue(queue);
    return 0;
}