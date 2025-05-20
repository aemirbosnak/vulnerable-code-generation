//FormAI DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue();
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int val);
int dequeue(Queue *q);
void display(Queue *q);

int main() {
    Queue *q = createQueue();
    int choice, val;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter value to be enqueued: ");
                scanf("%d", &val);
                enqueue(q, val);
                break;
            
            case 2:
                val = dequeue(q);
                if(val != -1)
                    printf("\nThe dequeued value is: %d", val);
                break;
            
            case 3:
                display(q);
                break;

            case 4:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid choice!");
        }
    } while(choice != 4);

    return 0;
}

Queue* createQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;

    return q;
}

int isFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue *q, int val) {
    if(isFull(q)) {
        printf("\nQueue is full!");
        return;
    }

    if(q->front == -1)
        q->front = 0;

    q->rear++;
    q->arr[q->rear] = val;

    printf("\n%d has been enqueued to the queue!", val);
}

int dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("\nQueue is empty!");
        return -1;
    }

    int val = q->arr[q->front];
    q->front++;

    if(q->front > q->rear)
        q->front = q->rear = -1;

    return val;
}

void display(Queue *q) {
    if(isEmpty(q)) {
        printf("\nQueue is empty!");
        return;
    }
    
    printf("\nThe queue is: ");
    for(int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
}