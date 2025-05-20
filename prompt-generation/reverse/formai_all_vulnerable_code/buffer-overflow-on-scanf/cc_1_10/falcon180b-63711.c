//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear == front - 1)) {
        printf("\nQueue is Full!!");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = value;
    } else {
        rear++;
        queue[rear] = value;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty!!");
    } else {
        printf("\nThe deleted element is %d", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty!!");
    } else {
        printf("\nThe elements in the queue are: ");
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (int i = front; i <= MAX - 1; i++) {
                printf("%d ", queue[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the value to be enqueued: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice!!");
        }
    }
    return 0;
}