//FormAI DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Maximum size of the queue

// Queue structure
struct Queue {
    int front, rear, size;
    int arr[MAX_SIZE];
};

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == MAX_SIZE);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("\nQueue is full.");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = item;
    queue->size++;
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nQueue is empty.");
        return -1;
    }
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return item;
}

// Function to print the queue
void display(struct Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("\nQueue is empty.");
        return;
    }
    printf("\n\nThe elements of the queue are:\n");
    for (i = queue->front; i <= queue->rear; i++)
        printf("%d  ", queue->arr[i]);
}

int main() {
    struct Queue queue;

    // Initializing the queue
    queue.front = 0;
    queue.rear = -1;
    queue.size = 0;

    int choice, item;

    // Displaying the menu
    printf("\n-----QUEUE MENU-----\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display the queue\n");
    printf("4. Exit");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to be enqueued: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice.");
        }
    } while (choice != 4);

    return 0;
}