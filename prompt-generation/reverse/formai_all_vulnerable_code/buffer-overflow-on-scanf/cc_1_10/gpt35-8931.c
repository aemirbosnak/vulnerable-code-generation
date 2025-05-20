//FormAI DATASET v1.0 Category: Queue ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

// define the queue structure
typedef struct queue {
    int arr[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// function prototypes
void initQueue(Queue *q);
void enqueue(Queue *q, int val);
void dequeue(Queue *q);
void printQueue(Queue q);
int isFull(Queue q);
int isEmpty(Queue q);

int main() {
    Queue q1;
    int menuChoice, val;

    initQueue(&q1);

    printf("\n**********************************************\n");
    printf("Welcome to the Amazing Queue Program\n");
    printf("**********************************************\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Enqueue a value\n");
        printf("2. Dequeue a value\n");
        printf("3. Print the queue\n");
        printf("4. Quit\n");
        printf("> ");
        scanf("%d", &menuChoice);

        switch(menuChoice) {
            case 1:
                if (isFull(q1)) {
                    printf("The queue is full!\n");
                } else {
                    printf("Please enter a value to enqueue: ");
                    scanf("%d", &val);
                    enqueue(&q1, val);
                }
                break;
            case 2:
                if (isEmpty(q1)) {
                    printf("The queue is empty!\n");
                } else {
                    dequeue(&q1);
                }
                break;
            case 3:
                printQueue(q1);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid menu choice. Please try again.\n");
                break;
        }
    } while (menuChoice != 4);

    return 0;
}

// initialize an empty queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// add a value to the rear of the queue
void enqueue(Queue *q, int val) {
    if (isFull(*q)) {
        printf("The queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = val;
    }
}

// remove a value from the front of the queue
void dequeue(Queue *q) {
    if (isEmpty(*q)) {
        printf("The queue is empty!\n");
    } else {
        printf("Dequeued %d\n", q->arr[q->front]);
        q->front++;
        if (q->front > q->rear) {
            initQueue(q);
        }
    }
}

// print the contents of the queue
void printQueue(Queue q) {
    if (isEmpty(q)) {
        printf("The queue is empty!\n");
    } else {
        printf("Queue contents: ");
        for (int i = q.front; i <= q.rear; i++) {
            printf("%d ", q.arr[i]);
        }
        printf("\n");
    }
}

// check if the queue is full
int isFull(Queue q) {
    if (q.rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

// check if the queue is empty
int isEmpty(Queue q) {
    if (q.front == -1 || q.front > q.rear) {
        return 1;
    } else {
        return 0;
    }
}