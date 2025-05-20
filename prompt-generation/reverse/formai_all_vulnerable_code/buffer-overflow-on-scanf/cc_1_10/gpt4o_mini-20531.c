//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFull(struct Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

bool isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return a sentinel value if empty
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Reset queue when it is empty
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued: %d\n", item);
    return item;
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    if (q->rear >= q->front) {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
    } else {
        for (int i = q->front; i < MAX; i++) {
            printf("%d ", q->items[i]);
        }
        for (int i = 0; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
    }
    printf("\n");
}

void freeQueue(struct Queue* q) {
    free(q);
    printf("Queue memory freed!\n");
}

int main() {
    struct Queue* myQueue = createQueue();
    int choice, value;

    printf("Welcome to the Retro Queue Implementation!\n");
    while (true) {
        printf("\nSelect an operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(myQueue, value);
                break;
            case 2:
                dequeue(myQueue);
                break;
            case 3:
                display(myQueue);
                break;
            case 4:
                freeQueue(myQueue);
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}