//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX], front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("Element %d has been added to the queue.\n", data);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Element %d has been removed from the queue.\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Elements in the queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        } 
        printf("\n");
    }
}

int main() {
    printf("Welcome to Sherlock's Queue Implementation program!\n");
    printf("Please choose an option:\n");
    printf("1. Add an element\n");
    printf("2. Remove an element\n");
    printf("3. Display the queue\n");
    printf("4. Quit\n");
    int choice, element;
    do {
        printf("Enter your option: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the element you want to add: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Goodbye! Thank you for using Sherlock's Queue Implementation program.\n");
                exit(0);
            default:
                printf("Invalid option! Please choose a valid option.\n");
        }
    } while (choice != 4);
    return 0;
}