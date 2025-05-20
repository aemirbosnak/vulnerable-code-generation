//FormAI DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow! Cannot Insert %d\n", data);
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = data;
    printf("Inserted %d into Queue.\n", data);
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int deleted = queue[front];
    front++;
    printf("Deleted element: %d\n", deleted);
    return deleted;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, data;
    printf("C Queue Implementation Example Program\n");
    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
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
                printf("Exiting Program...\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}