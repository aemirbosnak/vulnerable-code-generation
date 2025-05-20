//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_CAPACITY 100

int queue_arr[QUEUE_CAPACITY];
int front = -1, rear = -1;

bool isFull() {
    if ((front == 0 && rear == QUEUE_CAPACITY - 1) || front == rear + 1) {
        return true;
    }
    return false;
}

bool isEmpty() {
    if (front == -1) {
        return true;
    }
    return false;
}

void insert(int item) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % QUEUE_CAPACITY;
    queue_arr[rear] = item;
}

int delete() {
    int item;
    if (isEmpty()) {
        printf("Underflow\n");
        exit(1);
    }
    item = queue_arr[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % QUEUE_CAPACITY;
    }
    return item;
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Empty Queue\n");
        return;
    }
    printf("Front: %d\n", front);
    printf("Items: ");
    for (i = front; i != rear; i = (i + 1) % QUEUE_CAPACITY) {
        printf("%d, ", queue_arr[i]);
    }
    printf("%d\n", queue_arr[i]);
    printf("Rear: %d\n", rear);
}

int main() {
    int choice, item;
    while (1) {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                item = delete();
                printf("Deleted item: %d\n", item);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}