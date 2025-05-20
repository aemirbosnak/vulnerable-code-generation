//FormAI DATASET v1.0 Category: Queue ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue {
    int front;
    int rear;
    int size;
    int array[MAX_QUEUE_SIZE];
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

int isFull(Queue* queue) {
    return (queue->size == MAX_QUEUE_SIZE);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Error: Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    return item;
}

int main() {
    printf("Welcome to the C Queue program!\n");

    Queue* queue = createQueue();

    printf("How many numbers would you like to enqueue? ");
    int n;
    scanf("%d", &n);

    printf("Please enter the numbers to enqueue: ");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(queue, x);
    }

    printf("Queue: ");
    while (!isEmpty(queue)) {
        int item = dequeue(queue);
        printf("%d ", item);
    }
    printf("\n");

    printf("Thanks for using the program!");

    return 0;
}