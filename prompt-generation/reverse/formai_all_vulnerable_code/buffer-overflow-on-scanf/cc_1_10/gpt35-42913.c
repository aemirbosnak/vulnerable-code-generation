//FormAI DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>

#define MAX_QUEUE_SIZE 10

int queue[MAX_QUEUE_SIZE];
int front = 0, rear = -1;

void enqueue(int data) {
    rear++;
    if(rear == MAX_QUEUE_SIZE) {
        printf("Queue is full!\n");
        rear--;
        return;
    }

    queue[rear] = data;
    printf("Enqueued successfully!\n");
}

void dequeue() {
    if(rear < front) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Dequeued: %d\n", queue[front]);
    front++;
}

void display() {
    if(rear < front) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue contents: ");
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    printf("Welcome to the unique queue implementation program!\n");
    printf("Here you will experience a new way of queueing.\n");

    int choice = 0;
    while (choice != 4) {
        printf("1. Insert element into queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display all elements in the queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter element to insert: ");
                int data;
                scanf("%d", &data);
                enqueue(data);
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
            case 4: {
                printf("Thanks for using the unique queue implementation program.\n");
                break;
            }
            default: {
                printf("Invalid choice! Please try again.\n");
                break;
            }
        }
    }

    return 0;
}