//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueFull(Queue *q) {
    return (q->rear == MAX_SIZE-1);
}

int isQueueEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

void enQueue(Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full! Cannot insert value.\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->data[q->rear] = value;
}

void deQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty! Cannot delete value.\n");
        return;
    }
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}

void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty! Cannot display values.\n");
        return;
    }
    printf("Queue values are:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initializeQueue(&q);
    int option, value;

    printf("Welcome to Cyberpunk Queue Implementation!\n");
    do {
        printf("Menu:\n");
        printf("1. Insert value into queue\n");
        printf("2. Delete value from queue\n");
        printf("3. Display values in queue\n");
        printf("4. Quit program\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enQueue(&q, value);
                printf("Value %d inserted into queue.\n", value);
                break;
            case 2:
                deQueue(&q);
                printf("Value deleted from queue.\n");
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option! Please enter again.\n");
                break;
        }

    } while(option != 4);

    return 0;
}