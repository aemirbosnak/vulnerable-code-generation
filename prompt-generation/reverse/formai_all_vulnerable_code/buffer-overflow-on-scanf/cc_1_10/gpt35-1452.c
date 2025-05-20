//FormAI DATASET v1.0 Category: Queue Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct queue {
    int items[SIZE];
    int front;
    int rear;
};

struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(struct queue* q) {
    if (q->rear == SIZE - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(struct queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Added %d to the queue\n", value);
    }
}

void dequeue(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Removed %d from the queue\n", q->items[q->front]);
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
}

void display(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue contains: ");
        for (int i = q->front; i < q->rear + 1; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct queue* q = createQueue();

    printf("Welcome to the queue program!\n");
    printf("You can add items up to 5 in the queue.\n");

    int choice = 0;
    int item;
    while (choice != 4) {
        printf("\nWhat would you like to do?\n");
        printf("1. Enqueue an item.\n");
        printf("2. Dequeue an item.\n");
        printf("3. Display the items in the queue.\n");
        printf("4. Exit.\n");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item you would like to enqueue: ");
                scanf("%d", &item);
                enqueue(q, item);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}