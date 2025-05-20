//FormAI DATASET v1.0 Category: Queue Implementation ; Style: portable
#include<stdio.h>
#define MAXSIZE 5

int queue[MAXSIZE], front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAXSIZE - 1) {
        printf("The queue is full.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("%d inserted to the queue.\n", data);
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("The queue is empty.\n");
        return -1;
    } else {
        int item = queue[front];
        front++;
        printf("%d removed from queue.\n", item);
        return item;
    }
}

void display() {
    if (front == -1) {
        printf("The queue is empty.\n");
    } else {
        printf("The elements in the queue are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;

    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}