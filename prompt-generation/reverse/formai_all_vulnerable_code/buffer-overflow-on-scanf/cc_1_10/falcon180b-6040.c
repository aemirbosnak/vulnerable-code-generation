//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int queue[MAX];
int front = -1, rear = -1;
int n;

void enqueue(int value) {
    if (front == 0 || rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = value;
    } else if (rear == MAX - 1 && front!= 0) {
        rear = 0;
        queue[rear] = value;
    } else {
        rear++;
        queue[rear] = value;
    }
}

void dequeue() {
    if (front == -1 || rear == -1) {
        printf("Queue is empty\n");
        return;
    } else if (front == rear) {
        printf("Deleted element is %d\n", queue[front]);
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        printf("Deleted element is %d\n", queue[front]);
        front = 0;
    } else {
        printf("Deleted element is %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Elements in the queue are: ");
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (int i = front; i < MAX; i++) {
                printf("%d ", queue[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
    }
}

int main() {
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        enqueue(value);
    }
    printf("Elements in the queue are: ");
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}