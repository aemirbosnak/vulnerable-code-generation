//FormAI DATASET v1.0 Category: Queue ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE 5

// Defining the structure of the Queue
typedef struct queue {
    int data[MAX_QUEUE];
    int front, rear;
} Queue;

// Initiate the Queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    if(q->front == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Check if the queue is full
int isFull(Queue *q) {
    if(q->rear == MAX_QUEUE-1) {
        return 1;
    } else {
        return 0;
    }
}

// Add elements to the queue
void enqueue(Queue *q, int value) {
    if(isFull(q)) {
        printf("Queue Overflow\n");
    } else {
        if(q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->data[q->rear] = value;
        printf("%d added to the queue\n", value);
    }
}

// Remove elements from the queue
void dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue Underflow\n");
    } else {
        printf("%d removed from the queue\n", q->data[q->front]);
        q->front++;
        if(q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
}

// Display the elements in the queue
void display(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is Empty\n");
    } else {
        printf("The current elements in the queue are: ");
        for(int i=q->front;i<=q->rear;i++) {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

// Main Function
int main() {
    Queue q;
    int choice, value;

    initQueue(&q);

    while(1) {
        printf("\n");
        printf("------------ C Queue Example Program ------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to be added: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("\nExiting the program!!\n\n");
                exit(0);
            default:
                printf("\nInvalid Choice. Please try again!!\n");
        }
    }
    return 0;
}