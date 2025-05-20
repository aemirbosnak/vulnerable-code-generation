//FormAI DATASET v1.0 Category: Queue ; Style: content
#include<stdio.h>
#include<stdlib.h>
#define size 5

int queue[size];
int front = -1, rear = -1;

void enqueue(int data) {
    // Check if queue is full
    if(rear == size-1) {
        printf("Queue is full. No more insertion possible.\n");
        return;
    }
    // If queue is empty
    if(front == -1 && rear == -1)
        front = rear = 0;
    else
        rear++;
    queue[rear] = data;
    printf("Inserted %d into the queue.\n",data);
}

void dequeue() {
    // Check if queue is empty
    if(front == -1) {
        printf("Queue is empty. No more deletion possible.\n");
        return;
    }
    printf("Deleted %d from the queue.\n",queue[front]);
    // If there is only one element in queue
    if(front == rear)
        front = rear = -1;
    else
        front++;
}

void display() {
    // Check if queue is empty
    if(front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements of queue are: ");
    for(int i = front; i <= rear; i++) {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;
    while(1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: {
                printf("Enter data to enqueue: ");
                scanf("%d",&data);
                enqueue(data);
                break;
            }
            case 2: {
                dequeue();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                printf("Exiting the program.\n");
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }
    return 0;
}