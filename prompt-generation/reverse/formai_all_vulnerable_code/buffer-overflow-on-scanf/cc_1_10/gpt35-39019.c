//FormAI DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int front = -1, rear = -1;
int queue[MAX_SIZE];

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = value;
        return;
    }
    rear++;
    queue[rear] = value;
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty!\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
        return;
    }
    front++;
}

int get_front() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue[front];
}

int is_empty() {
    if (front == -1 && rear == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Elements in Queue are:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    do {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Get Front\n");
        printf("4.Is Empty?\n");
        printf("5.Display\n");
        printf("0.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("The element at front is: %d\n", get_front());
                break;
            case 4:
                if (is_empty()) {
                    printf("Queue is empty!\n");
                }
                else {
                    printf("Queue is not empty!\n");
                }
                break;    
            case 5:
                display();
                break;
            case 0:
                exit(0);    
            default:
                printf("Invalid choice!\n");        
        }
    } while (choice != 0);

    return 0;
}