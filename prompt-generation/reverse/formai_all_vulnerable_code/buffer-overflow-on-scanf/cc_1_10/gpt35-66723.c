//FormAI DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int is_empty() {
    if (front == -1 || front > rear) {
        return 1;
    }
    return 0;
}

int is_full() {
    if (rear == SIZE - 1) {
        return 1;
    }
    return 0;
}

void enqueue(int data) {
    if (is_full()) {
        printf("Queue is full!\n");
        return;
    }
    rear++;
    queue[rear] = data;
    if (front == -1) {
        front = 0;
    }
}

int dequeue() {
    int data;
    if (is_empty()) {
        printf("Queue is empty!\n");
        return -1;
    }
    data = queue[front];
    front++;
    return data;
}

int main() {
    int choice, item;
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if (item != -1) {
                    printf("Item dequeued: %d\n", item);
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}