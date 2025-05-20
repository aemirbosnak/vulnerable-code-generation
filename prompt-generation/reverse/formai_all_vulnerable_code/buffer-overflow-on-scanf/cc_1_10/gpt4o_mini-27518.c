//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 5

typedef struct {
    int items[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isFull(Queue* q) {
    return (q->rear + 1) % QUEUE_SIZE == q->front;
}

bool isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! The wise owl says it's not the right time to add more wisdom!\n");
        return;
    }
    if (q->front == -1) { // First element
        q->front = 0;
    }
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->items[q->rear] = value;
    printf("The lion roars: %d added to the queue!\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! The nervous rabbit is too afraid to hop on!\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % QUEUE_SIZE;
    }
    printf("The wise old tortoise slowly takes out: %d from the queue!\n", item);
    return item;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("The majestic eagle sees no one in the queue!\n");
        return;
    }
    
    printf("The queue holds the following treasures: ");
    int i = q->front;
    while (true) {
        printf("%d ", q->items[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % QUEUE_SIZE;
    }
    printf("\n");
}

void menu() {
    printf("\n+++ Magical Creature Queue Management +++\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("4. Exit\n");
    printf("Choose your adventure: ");
}

int main() {
    Queue q;
    initializeQueue(&q);
    int choice, value;

    while (true) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to add to the queue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("The joyful monkey carried away: %d!\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("The magical creatures bid you farewell!\n");
                exit(0);
            default:
                printf("The mystical numbers fail you! Please choose 1 to 4.\n");
        }
    }
    return 0;
}