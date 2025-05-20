//FormAI DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

// queue structure
typedef struct {
    int *items;
    int front;
    int rear;
    int size;
} queue;

// creates a queue of given size
queue *create_queue() {
    queue *q = (queue*) malloc(sizeof(queue));
    q->items = (int*) malloc(MAX_QUEUE_SIZE * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

// checks if queue is full
int is_full(queue *q) {
    return q->rear == MAX_QUEUE_SIZE-1;
}

// checks if queue is empty
int is_empty(queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// adds an item to the rear of the queue
void enqueue(queue *q, int data) {
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    }

    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = data;
    q->size++;
}

// removes an item from the front of the queue
int dequeue(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = q->items[q->front];
    q->front++;
    q->size--;
    return data;
}

// prints the current queue
void print_queue(queue *q) {
    int i = q->front;
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    queue *q = create_queue();
    int option, data;

    do {
        printf("Choose an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print queue\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                print_queue(q);
                break;
            case 4:
                printf("Exiting..\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while(option != 4);

    return 0;
}