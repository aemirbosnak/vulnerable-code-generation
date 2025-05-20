//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 50

typedef struct queue {
    int data[MAX_QUEUE_SIZE];
    int front, rear, size;
} Queue;

void initialize(Queue *q) {
    q->front = q->rear = -1;
    q->size = 0;
}

int isFull(Queue *q) {
    return q->size == MAX_QUEUE_SIZE;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, int data) {
    if(isFull(q)) {
        printf("Queue is Full\n");
        return;
    }
    if(q->rear == MAX_QUEUE_SIZE - 1)
        q->rear = -1;
    q->data[++q->rear] = data;
    q->size++;
}

int dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    int data = q->data[++q->front];
    if(q->front == MAX_QUEUE_SIZE - 1)
        q->front = -1;
    q->size--;
    return data;
}

int main(void) {
    Queue q1, q2;
    initialize(&q1);
    initialize(&q2);
    int data, player = 1;
    printf("Welcome to the game!\n");
    printf("Player 1, enter your number (1-9): ");
    scanf("%d", &data);
    enqueue(&q1, data);
    while(1) {
        if(player == 1) {
            printf("Player 2, enter your number (1-9): ");
            scanf("%d", &data);
            if(!isEmpty(&q1) && data > q1.data[q1.rear]) {
                printf("%d is smaller than player 1's current number.\n", data);
                printf("Game Over! Player 2 loses.\n");
                break;
            }
            enqueue(&q2, data);
            player = 2;
        }
        else {
            printf("Player 1, enter your number (1-9): ");
            scanf("%d", &data);
            if(!isEmpty(&q2) && data < q2.data[q2.rear]) {
                printf("%d is greater than player 2's current number.\n", data);
                printf("Game Over! Player 1 loses.\n");
                break;
            }
            enqueue(&q1, data);
            player = 1;
        }
    }
    return 0;
}