//FormAI DATASET v1.0 Category: Queue ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 10

int front = -1, rear = -1;

int queue[MAX_QUEUE_SIZE];

//Queue Operations
void enqueue(int x) {
    if(front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    }
    else if((rear + 1) % MAX_QUEUE_SIZE == front) {
        printf("Queue is full.\n");
    }
    else {
        rear = (rear+1) % MAX_QUEUE_SIZE;
        queue[rear] = x;
    }
}

int dequeue() {
    int x;
    if(front == -1 && rear == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    else if(front == rear) {
        x = queue[front];
        front = rear = -1;
    }
    else {
        x = queue[front];
        front = (front+1) % MAX_QUEUE_SIZE;
    }
    return x;
}

void display() {
    if(front == -1 && rear == -1) {
        printf("Queue is empty.\n");
    }
    else {
        printf("The Queue is: ");
        for(int i=front; i!=rear; i=(i+1)%MAX_QUEUE_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[rear]);
    }
}

//Main function
int main() {
    int choice, x, flag=1;
    printf("[1] Enqueue\n[2] Dequeue\n[3] Display\n[4] Exit\n");
    while(flag) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                printf("The dequeued element is %d.\n", dequeue());
                break;
            case 3:
                display();
                break;
            case 4:
                flag = 0;
                break;
            default:
                printf("Invalid choice.");
        }
    }
    return 0;
}