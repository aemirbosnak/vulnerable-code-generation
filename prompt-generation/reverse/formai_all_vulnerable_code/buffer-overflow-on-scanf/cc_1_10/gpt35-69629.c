//FormAI DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Define the Queue data structure
typedef struct {
    int front, rear;
    int arr[SIZE];
} Queue;

// Function to initialize the Queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the Queue is empty
int isEmpty(Queue *q) {
    if (q->rear == -1)
        return 1;
    return 0;
}

// Function to check if the Queue is full
int isFull(Queue *q) {
    if (q->rear == SIZE - 1)
        return 1;
    return 0;
}

// Function to add a new item to the Queue
void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Sir Knight, the Queue is already full. You cannot add anymore!\n");
        return;
    }
    if (isEmpty(q))
        q->front = 0;
    q->rear++;
    q->arr[q->rear] = data;
    printf("Sir Knight, %d has been added to the Queue!\n", data);
}

// Function to remove an item from the Queue
int dequeue(Queue *q) {
    int data;
    if (isEmpty(q)) {
        printf("Sir Knight, the Queue is already empty. You cannot dequeue anymore!\n");
        return -1;
    }
    data = q->arr[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    printf("Sir Knight, %d has been dequeued from the Queue!\n", data);
    return data;
}

// Function to display the Queue
void display(Queue *q) {
    int i;
    if (isEmpty(q)) {
        printf("Sir Knight, the Queue is empty. Nothing to display!\n");
        return;
    }
    printf("Here are the items in the Queue: ");
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    int choice, data;

    initQueue(&q);

    printf("Greetings Sir Knight, welcome to The Knight's Queue!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1 - Enqueue an item\n");
        printf("2 - Dequeue an item\n");
        printf("3 - Display the Queue\n");
        printf("4 - Exit the program\n");
        printf("Your choice? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("What item would you like to add to the Queue? ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Fare thee well Sir Knight. May your journey be safe!");
                exit(0);
        }
    }

    return 0;
}