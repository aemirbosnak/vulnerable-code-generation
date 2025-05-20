//FormAI DATASET v1.0 Category: Queue ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 5

int queue[MAXQUEUE], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAXQUEUE - 1) {
        printf("Sorry! Queue Overflow.\n");
    } else {
        if (front == -1) {
            front = 0;
        }

        rear++;
        queue[rear] = value;
        printf("%d enqueued to the queue!\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Sorry! Queue Underflow.\n");
    } else {
        printf("%d dequeued from the queue!\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Elements in the Queue are : ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Surprise Queue!\n");
    printf("This Queue has a capacity of %d elements.\n", MAXQUEUE);

    int userChoice;
    do {
        printf("\nWhat do you want to do?\n");
        printf("1. Enqueue an element\n");
        printf("2. Dequeue an element\n");
        printf("3. Display the Queue\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1: {
                int element;
                printf("\nEnter the element to be enqueued: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            }
            case 2: {
                dequeue();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4:
                printf("Thank you for using the Surprise Queue!\n");
                break;
            default:
                printf("Invalid input, Please try again!\n");
                break;
        }
    } while (userChoice != 4);

    return 0;
}