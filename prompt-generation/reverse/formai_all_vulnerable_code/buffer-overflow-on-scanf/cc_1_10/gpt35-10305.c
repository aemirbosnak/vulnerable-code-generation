//FormAI DATASET v1.0 Category: Queue ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

int front = -1, rear = -1;
int queue[MAXSIZE];

void enqueue(int data) {
    if (rear == MAXSIZE - 1) {
        printf("Overflow\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("%d Enqueued into queue\n", data);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
        return;
    }
    else {
        printf("%d Dequeued from the queue\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("No elements in Queue to display\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int menu() {
    int choice;
    printf("************QUEUE OPERATIONS************\n");
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display Queue\n");
    printf("4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

int main() {
    int choice, data;
    while (1) {
        choice = menu();
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Thank you for using the program!\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}