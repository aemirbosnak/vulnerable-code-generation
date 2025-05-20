//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

CircularQueue* createQueue() {
    CircularQueue *q = (CircularQueue *)malloc(sizeof(CircularQueue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFull(CircularQueue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

bool isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Halt! The queue is jam-packed.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Chugging!: Added %d to the queue\n", value);
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Alas! The queue is empty. Nothing to remove.\n");
        return -1;
    }
    int item = q->items[q->front];
    printf("Whirling away: Removed %d from the queue\n", item);
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return item;
}

void frontAndRear(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Alas! The queue stands empty.\n");
    } else {
        printf("Cheeky peek: Front is %d, Rear is %d\n", q->items[q->front], q->items[q->rear]);
    }
}

void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Nothing to display, queue is void!\n");
        return;
    }
    printf("Queue status: ");
    for (int i = 0; i < MAX; i++) {
        if (q->items[i]) {
            printf("%d ", q->items[i]);
        }
    }
    printf("\n");
}

void destroyQueue(CircularQueue *q) {
    free(q);
    printf("All done! Queue is dismantled.\n");
}

int main() {
    CircularQueue *q = createQueue();
    int choice, value;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Front and Rear\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Select your action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("What number shall I ensconce in this queue? ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                frontAndRear(q);
                break;
            case 4:
                displayQueue(q);
                break;
            case 5:
                printf("Retreating, till we meet again!\n");
                break;
            default:
                printf("Trickster! Not a valid option.\n");
                break;
        }
    } while (choice != 5);

    destroyQueue(q);
    return 0;
}