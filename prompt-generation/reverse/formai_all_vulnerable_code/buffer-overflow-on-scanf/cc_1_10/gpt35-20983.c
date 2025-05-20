//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// define Queue structure
typedef struct queue {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// function prototypes
void enqueue(Queue *queue, int value);
void dequeue(Queue *queue);
void display(Queue *queue);
int isFull(Queue *queue);
int isEmpty(Queue *queue);

int main() {
    Queue player1, player2;
    player1.front = -1;
    player1.rear = -1;
    player2.front = -1;
    player2.rear = -1;
    int turn = 1;
    int choice, value;
    
    printf("Welcome to the C Queue Implementation game!\n");
    printf("-------------------------------------------\n");
    
    while (1) {
        // display turn
        printf("\nIt's Player %d's turn.\n", turn);
        
        // display queue status
        printf("Player 1's queue: ");
        display(&player1);
        printf("\n");
        printf("Player 2's queue: ");
        display(&player2);
        printf("\n");
        
        // menu
        printf("Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1: // enqueue
                printf("Enter a value: ");
                scanf("%d", &value);
                if (turn == 1) {
                    enqueue(&player1, value);
                    if (isFull(&player1)) {
                        printf("Player 1 wins!\n");
                        exit(0);
                    }
                    turn = 2;
                } else {
                    enqueue(&player2, value);
                    if (isFull(&player2)) {
                        printf("Player 2 wins!\n");
                        exit(0);
                    }
                    turn = 1;
                }
                break;
            case 2: // dequeue
                if (turn == 1) {
                    dequeue(&player2);
                    turn = 2;
                } else {
                    dequeue(&player1);
                    turn = 1;
                }
                break;
            case 3: // exit
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

// helper function to check if queue is full
int isFull(Queue *queue) {
    if (queue->front == 0 && queue->rear == MAX_SIZE - 1) {
        return 1;
    }
    if (queue->front == queue->rear + 1) {
        return 1;
    }
    return 0;
}

// helper function to check if queue is empty
int isEmpty(Queue *queue) {
    if (queue->front == -1) {
        return 1;
    }
    return 0;
}

// function to add item to queue
void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = value;
    }
}

// function to remove item from queue
void dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
    }
}

// function to display queue
void display(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        int i;
        for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue->items[i]);
        }
        printf("%d", queue->items[i]);
    }
}