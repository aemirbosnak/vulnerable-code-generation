//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#define N 10

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int processID) {
    if ((front == 0 && rear == N - 1) || (rear == front - 1)) {
        printf("\nQueue is Full!!");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = processID;
    } else if (rear == N - 1 && front!= 0) {
        rear = 0;
        queue[rear] = processID;
    } else {
        rear++;
        queue[rear] = processID;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("\nQueue is Empty!!");
    } else if (front == rear) {
        printf("\nDeleted processID: %d", queue[front]);
        front = rear = -1;
    } else if (front == N - 1) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    int i;
    if (front == -1 && rear == -1) {
        printf("\nQueue is Empty!!");
    } else {
        printf("\nProcess ID's in the Queue are: ");
        if (rear >= front) {
            for (i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (i = front; i < N; i++) {
                printf("%d ", queue[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
    }
}

int main() {
    int choice, processID;
    while (1) {
        printf("\n\n*********MENU*********");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the processID to be added: ");
            scanf("%d", &processID);
            enqueue(processID);
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
            printf("\nInvalid choice!! Please try again");
        }
    }
    return 0;
}