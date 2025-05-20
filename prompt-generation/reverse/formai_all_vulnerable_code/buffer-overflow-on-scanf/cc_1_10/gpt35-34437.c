//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/* Structure for queue */
typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

/* Initializes queue */
void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

/* Checks if queue is empty */
int isEmpty(Queue *q) {
    return q->front == -1;
}

/* Checks if queue is full */
int isFull(Queue *q) {
    return q->rear == MAX_SIZE-1;
}

/* Adds an element to the queue */
void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert element!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = data;
}

/* Removes an element from the queue */
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot remove element!\n");
        return;
    }
    int data = q->arr[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
}

/* Displays the elements of the queue */
void display(Queue *q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing to display!\n");
        return;
    }
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

/* Driver function */
int main() {
    Queue q;
    init(&q);
    int choice, data;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
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
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}