//FormAI DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

// declare array as a global variable
int queue[QUEUE_SIZE];

// globals for the queue
int front = -1, rear = -1;

// function prototypes
void enqueue(int);
int dequeue();
int is_empty();
int is_full();
void display();

int main() {
    int choice, item;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if (item != -1)
                    printf("Dequeued item: %d\n", item);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}

void enqueue(int item) {
    if (is_full()) {
        printf("Error: Queue is full, can't enqueue.\n");
        return;
    } else if (is_empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % QUEUE_SIZE;
    }
    queue[rear] = item;
}

int dequeue() {
    int item;
    if (is_empty()) {
        printf("Error: Queue is empty, can't dequeue.\n");
        return -1;
    } else if (front == rear) {
        item = queue[front];
        front = rear = -1;
    } else {
        item = queue[front];
        front = (front + 1) % QUEUE_SIZE;
    }
    return item;
}

int is_empty() {
    return front == -1 && rear == -1;
}

int is_full() {
    return (rear + 1) % QUEUE_SIZE == front;
}

void display() {
    if (is_empty()) {
        printf("Queue is empty, nothing to display.\n");
        return;
    }
    int i;
    printf("Queue Elements: ");
    for (i = front; i != rear; i = (i + 1) % QUEUE_SIZE) {
        printf("%d ", queue[i]);
    }
    printf("%d", queue[rear]);
}