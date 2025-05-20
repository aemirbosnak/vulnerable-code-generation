//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// Function prototypes
CircularQueue* createQueue();
int isFull(CircularQueue* cq);
int isEmpty(CircularQueue* cq);
void enqueue(CircularQueue* cq, int value);
int dequeue(CircularQueue* cq);
void displayQueue(CircularQueue* cq);
void freeQueue(CircularQueue* cq);

int main() {
    CircularQueue* cq = createQueue();
    int option, value;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(cq, value);
                break;
            case 2:
                value = dequeue(cq);
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;
            case 3:
                displayQueue(cq);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 4);

    freeQueue(cq);
    return 0;
}

CircularQueue* createQueue() {
    CircularQueue* cq = (CircularQueue*) malloc(sizeof(CircularQueue));
    cq->front = -1;
    cq->rear = -1;
    return cq;
}

int isFull(CircularQueue* cq) {
    return (cq->rear + 1) % MAX_SIZE == cq->front;
}

int isEmpty(CircularQueue* cq) {
    return cq->front == -1;
}

void enqueue(CircularQueue* cq, int value) {
    if (isFull(cq)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(cq)) {
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % MAX_SIZE;
    cq->items[cq->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int value = cq->items[cq->front];
    if (cq->front == cq->rear) {
        cq->front = -1;
        cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % MAX_SIZE;
    }
    return value;
}

void displayQueue(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = cq->front;
    while (1) {
        printf("%d ", cq->items[i]);
        if (i == cq->rear)
            break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

void freeQueue(CircularQueue* cq) {
    free(cq);
}