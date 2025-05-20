//FormAI DATASET v1.0 Category: Data structures visualization ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100    // Maximum size of Queue

typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// Initialize Queue
Queue initializeQueue() {
    Queue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

// Check if the Queue is empty
bool isQueueEmpty(Queue q) {
    return (q.front == -1 && q.rear == -1);
}

// Check if the Queue is full
bool isQueueFull(Queue q) {
    return (q.rear == MAX_QUEUE_SIZE - 1);
}

// Insert element into Queue
void insert(Queue *q, int element) {
    if (isQueueFull(*q)) {
        printf("Queue is full. Overflow condition!\n");
        return;
    } else if (isQueueEmpty(*q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = q->rear + 1;
    }
    q->data[q->rear] = element;
}

// Delete element from Queue
int delete(Queue *q) {
    int element;
    if (isQueueEmpty(*q)) {
        printf("Queue is empty. Underflow condition!\n");
        return -1;
    } else if (q->front == q->rear) {
        element = q->data[q->front];
        q->front = -1;
        q->rear = -1;
    } else {
        element = q->data[q->front];
        q->front = q->front + 1;
    }
    return element;
}

// Display Queue
void display(Queue q) {
    int i;
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        for (i = q.front; i <= q.rear; i++) {
            printf("%d ", q.data[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q = initializeQueue();
    int choice, element;
    while (1) {
        printf("*********************\n");
        printf("Queue Operations Menu\n");
        printf("*********************\n");
        printf("1. Insert element into Queue\n");
        printf("2. Delete element from Queue\n");
        printf("3. Display the Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &element);
                insert(&q, element);
                break;
            case 2:
                element = delete(&q);
                if (element != -1) {
                    printf("Deleted element is: %d\n", element);
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}