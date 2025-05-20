//FormAI DATASET v1.0 Category: Queue ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int front;
    int rear;
    int queue[MAX_QUEUE_SIZE];
} Queue;

// Function declarations
void enqueue(Queue *q, int item);
int dequeue(Queue *q);
void display(Queue q);

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;

    printf("Welcome to my unique C Queue program!\n\n");

    int choice, item;
    do {
        printf("MENU:\n");
        printf("1. Enqueue an element.\n");
        printf("2. Dequeue an element.\n");
        printf("3. Display the queue.\n");
        printf("4. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("Enter the element to be enqueued: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2:
                item = dequeue(&q);
                if(item != -1)
                    printf("Dequeued element: %d\n", item);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting program. Bye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 4);

    return 0;
}

void enqueue(Queue *q, int item) {
    if(q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }
    if(q->front == -1) // If queue is initially empty
        q->front = 0;
    q->rear++;
    q->queue[q->rear] = item;
    printf("Enqueued element: %d\n", item);
}

int dequeue(Queue *q) {
    if(q->front == -1 || q->front > q->rear) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1; // Error condition
    }
    int item = q->queue[q->front];
    q->front++;
    return item;
}

void display(Queue q) {
    if(q.front == -1) {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }
    printf("Elements in the queue are: ");
    for(int i=q.front;i<=q.rear;i++)
        printf("%d ", q.queue[i]);
    printf("\n");
}