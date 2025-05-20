//FormAI DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* queue);
int isQueueEmpty(Queue* queue);
int isQueueFull(Queue* queue);
void enqueue(Queue* queue, int item);
int dequeue(Queue* queue);
void printQueue(Queue* queue);

int main() {
    Queue queue;
    initQueue(&queue);

    int option, item;

    do {
        printf("\n\n*********** MENU ***********");
        printf("\n1. Enqueue an item");
        printf("\n2. Dequeue an item");
        printf("\n3. Print queue");
        printf("\n4. Exit");

        printf("\n\nEnter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                printf("\nItem enqueued successfully!");
                break;
            case 2:
                item = dequeue(&queue);
                if (item == -1) {
                    printf("\nQueue is empty!");
                } else {
                    printf("\nDequeued item: %d", item);
                }
                break;
            case 3:
                printQueue(&queue);
                break;
            case 4:
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid option! Try again.");
        }

    } while (1);

    return 0;
}

void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isQueueFull(Queue* queue) {
    return (queue->rear == MAX_QUEUE_SIZE - 1);
}

void enqueue(Queue* queue, int item) {
    if (isQueueFull(queue)) {
        printf("\nQueue is full! Cannot enqueue item.");
    } else {
        if (isQueueEmpty(queue)) {
            queue->front = 0;
            queue->rear = 0;
        } else {
            queue->rear++;
        }
        queue->items[queue->rear] = item;
    }
}

int dequeue(Queue* queue) {
    int item = -1;
    if (isQueueEmpty(queue)) {
        return item;
    } else {
        item = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
        return item;
    }
}

void printQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("\nQueue is empty!");
    } else {
        printf("\nQueue: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
    }
}