//FormAI DATASET v1.0 Category: Queue ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int front = -1, rear = -1;
int queue[MAX_SIZE];

int isFull() {
    if ((front == rear + 1) || (front == 0 && rear == MAX_SIZE - 1)) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(int element) {
    if (isFull()) {
        printf("\n Queue is full!");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = element;
        printf("\n %d is added to the Queue", element);
    }
}

int dequeue() {
    int element;
    if (isEmpty()) {
        printf("\n Queue is empty!");
        element = -1;
    } else {
        element = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
    return element;
}

void display() {
    int i;
    if (isEmpty()) {
        printf("\n Queue is empty!");
    } else {
        printf("\n Front of the Queue: %d", front);
        printf("\n Items: ");
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d", queue[i]);
        printf("\n Rear of the Queue: %d", rear);
    }
}

int main() {
    int choice, element;
    printf("\n Welcome to the Queue program!");
    do {
        printf("\n\n ------- MENU ------- \n");
        printf("\n 1. Enqueue the element");
        printf("\n 2. Dequeue the element");
        printf("\n 3. Display the Queue");
        printf("\n 4. Exit");
        printf("\n ----------------------\n");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\n Enter the element to be added to the Queue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                element = dequeue();
                if (element != -1) {
                    printf("\n %d is removed from the Queue", element);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n Thank you for using the Queue program!");
                exit(0);
            default:
                printf("\n Invalid choice. Try again!");
        }
    } while(1);
    return 0;
}