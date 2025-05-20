//FormAI DATASET v1.0 Category: Queue Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

struct queue {
    int front, rear;
    int arr[MAX_SIZE];
};

void enqueue(struct queue *q, int val) {
    if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
        q->arr[q->rear] = val;
        printf("%d has been enqueued to the queue.\n", val);
        return;
    } 
    else if ((q->rear + 1) % MAX_SIZE == q->front) {
        printf("Queue overflow! Cannot enqueue any more elements.\n");
        return;
    }
    else {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->arr[q->rear] = val;
        printf("%d has been enqueued to the queue.\n", val);
    }
}

void dequeue(struct queue *q) {
    if (q->front == -1 && q->rear == -1) {
        printf("Queue underflow! Cannot dequeue any element.\n");
        return;
    } else if (q->front == q->rear) {
        printf("%d has been dequeued from the queue.\n", q->arr[q->front]);
        q->front = q->rear = -1;
    } else {
        printf("%d has been dequeued from the queue.\n", q->arr[q->front]);
        q->front = (q->front + 1) % MAX_SIZE;
    }
}

void display(struct queue *q) {
    if (q->front == -1 && q->rear == -1) {
        printf("The queue is empty.\n");
        return;
    } else {
        int i = q->front;
        printf("The queue is: ");
        while (i != q->rear) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d ", q->arr[i]);
        printf("\n");
    }
}

int main() {
    struct queue q;
    q.front = q.rear = -1;
    int choice, val;
    while (1) {
        printf("Enter 1 to enqueue an element.\nEnter 2 to dequeue an element.\nEnter 3 to display the queue.\nEnter 4 to exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice! Choose again.\n");
        }
    }
    return 0;
}