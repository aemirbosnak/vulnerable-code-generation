//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MAX 100

int front = -1, rear = -1;
int queue[MAX];

void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear == front - 1))
        printf("\nQueue Overflow");
    else if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("\nQueue Underflow");
    else
        printf("\nDeleted element is %d", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void display() {
    int i;
    if (front == -1)
        printf("\nQueue is Empty");
    else {
        printf("\nElements in the Queue are: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

int main() {
    int ch, value;
    while (1) {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("\nEnter the value to be inserted: ");
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
            printf("\nInvalid choice");
        }
    }
    return 0;
}