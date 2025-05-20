//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
/* PROGRAM NAME: C Queue Implementation Example
 * AUTHOR: Donald Knuth
 * DESCRIPTION: This program implements a queue using a circular array.
 * DATE CREATED: 28/04/2021
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int front, rear;
    int arr[MAX_SIZE];
} Queue;

Queue createQueue() {
    Queue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

int isFull(Queue q) {
    return ((q.rear+1)%MAX_SIZE == q.front);
}

int isEmpty(Queue q) {
    return (q.front == -1 && q.rear == -1);
}

void enqueue(Queue *q, int data) {
    if(isFull(*q)) {
        printf("Queue is Full! Cannot enqueue new data.\n");
        return;
    }
    if(isEmpty(*q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear+1)%MAX_SIZE;
    }
    q->arr[q->rear] = data;
}

int dequeue(Queue *q) {
    int data;
    if(isEmpty(*q)){
        printf("Queue is empty! Cannot dequeue data.\n");
        return -1;
    } else if(q->front == q->rear) {
        data = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
    } else {
        data = q->arr[q->front];
        q->front = (q->front+1)%MAX_SIZE;
    }
    return data;
}

void display(Queue q) {
    if(isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }
    int i = q.front;
    printf("Queue: ");
    while(i != q.rear){
        printf("%d ", q.arr[i]);
        i = (i+1)%MAX_SIZE;
    }
    printf("%d\n", q.arr[i]);
}

int main() {
    printf("Welcome to Donald Knuth's C Queue Implementation Example!\n");
    Queue q = createQueue();
    int choice, data;

    while(1) {
        printf("\n1. Enqueue data\n2. Dequeue data\n3. Display Queue\n4. Quit\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                if(data != -1) {
                    printf("Dequeued data: %d\n", data);
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Quitting Program! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid Choice! Please try again.\n");
        }
    }

    return 0;
}