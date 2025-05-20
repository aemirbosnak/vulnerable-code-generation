//FormAI DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int front = -1;
int rear = -1;
int queue[MAX_SIZE];

void enQueue(int value) {
    if((rear+1)%MAX_SIZE == front) {
        printf("Queue is full.\n");
    } else {
        if(front == -1) front = 0;
        rear = (rear+1)%MAX_SIZE;
        queue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

void deQueue() {
    if(front == -1 && rear == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Deleted %d from the queue.\n", queue[front]);
        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front+1)%MAX_SIZE;
        }
    }
}

void displayQueue() {
    int i;
    if(front == -1 && rear == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("The queue is: ");
        for(i=front; i!=rear; i=(i+1)%MAX_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {

    int choice, value;

    while(1) {

        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enQueue(value);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}