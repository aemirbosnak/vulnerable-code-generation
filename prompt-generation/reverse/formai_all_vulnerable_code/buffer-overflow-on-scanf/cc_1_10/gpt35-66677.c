//FormAI DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int front;
    int rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

void enqueue(Queue* q, int item) {
    if(q->rear == MAX_QUEUE_SIZE-1) {
        printf("Queue is full, can't add any more items.\n");
        return;
    }
    q->rear++;
    q->items[q->rear] = item;
    printf("Item added to queue: %d\n", item);
}

int dequeue(Queue* q) {
    if(q->front == q->rear) {
        printf("Queue is empty, can't dequeue any more items.\n");
        return -1;
    }
    q->front++;
    int item = q->items[q->front];
    printf("Item dequeued from queue: %d\n", item);
    return item;
}

int main() {
    srand(time(NULL));
    printf("Welcome to the surreal queue implementation program.\n");
    Queue q;
    q.front = -1;
    q.rear = -1;
    int choice, item;
    do {
        printf("\nPlease select from the following options:\n");
        printf("1. Add an item to the queue.\n");
        printf("2. Remove an item from the queue.\n");
        printf("3. Quit.\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                item = rand() % 100; // randomly generate item between 0-99
                printf("Adding item %d to the queue.\n", item);
                enqueue(&q, item);
                break;
            case 2:
                item = dequeue(&q);
                if(item != -1) {
                    printf("Item removed from queue: %d\n", item);
                }
                break;
            case 3:
                printf("Goodbye. Thank you for using the surreal queue implementation program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);
    return 0;
}