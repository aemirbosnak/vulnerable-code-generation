//FormAI DATASET v1.0 Category: Queue ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

int front = -1, rear = -1;
int queue[MAXSIZE];

void enqueue(int value) {
    if (rear == MAXSIZE - 1) {
        printf("Error: Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued element: %d\n", value);
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int value = queue[front];
    front++;
    printf("Dequeued element: %d\n", value);
    return value;
}

int main() {
    int choice, value;
    while(1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter element to be enqueued: ");
                    scanf("%d", &value);
                    enqueue(value);
                    break;
            case 2: dequeue();
                    break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}