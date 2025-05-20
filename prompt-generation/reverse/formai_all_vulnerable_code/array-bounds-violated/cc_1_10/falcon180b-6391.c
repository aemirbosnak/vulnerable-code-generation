//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
#define MAX 50

int front = -1, rear = -1;
int queue[MAX];

void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear == front - 1))
        printf("\nQueue Overflow");
    else if (front == -1)
        front = 0;
    else if (rear == -1)
        rear = 0;
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;

    queue[rear] = value;
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("\nQueue Underflow");
    else if (front == rear)
        front = rear = -1;
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;
}

void display() {
    int i;
    if (front == -1)
        printf("\nEmpty Queue");
    else {
        printf("\nElements in the Queue are: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

int main() {
    int choice, value;

    srand(time(NULL));
    for (int i = 0; i < N; i++)
        enqueue(rand() % 100);

    do {
        system("clear");
        printf("\n\t\tTRAFFIC FLOW SIMULATION\n");
        printf("\n1. Enqueue an element\n2. Dequeue an element\n3. Display the Queue\n4. Exit");
        printf("\n\nEnter your choice: ");
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
            printf("\nInvalid Choice!");
        }
    } while (1);

    return 0;
}