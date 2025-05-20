//FormAI DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

bool isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Your majesty, the queue is full, we can't add any more people.\n");
        return;
    }
    else if (isEmpty(q)) {
        q->front = q->rear = 0;
    }
    else {
        q->rear++;
    }

    q->items[q->rear] = value;
    printf("Good news your highness, %d has joined the queue to the land of King Arthur.\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("My humble apologies, your grace, the queue is empty, no one to remove.\n");
        return -1;
    }
    
    int removedValue = q->items[q->front];
    
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else {
        q->front++;
    }
    printf("%d has been removed from the queue, heading towards the kingdom.\n", removedValue);
    return removedValue;
}

int main() {
    Queue q;
    initialize(&q);

    int choice, value;

    do {
        printf("\nWhat would you like to do your majesty?\n");
        printf("1. Add to queue\n");
        printf("2. Remove from queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the number of people joining the queue: ");
                scanf("%d", &value);
                for (int i=0; i<value; i++) {
                    int new_person = rand()%100 + 1;
                    enqueue(&q, new_person);
                }
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                printf("\nGoodbye, my lord!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please choose wisely.\n");
        }
    } while (choice != 3);

    return 0;
}