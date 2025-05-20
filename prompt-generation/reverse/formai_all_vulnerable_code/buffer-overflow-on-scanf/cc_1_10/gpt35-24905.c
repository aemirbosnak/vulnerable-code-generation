//FormAI DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include<stdio.h>

#define MAX_QUEUE_SIZE 5

int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int element) {
    if ((front==0 && rear==MAX_QUEUE_SIZE-1) || rear==front-1) {
        printf("Queue Overflow!\n");
    } else if (front==-1 && rear==-1) {
        front = rear = 0;
        queue[rear] = element;
    } else if (rear==MAX_QUEUE_SIZE-1 && front!=0) {
        rear = 0;
        queue[rear] = element;
    } else {
        rear++;
        queue[rear] = element;
    }
}

int dequeue() {
    int element;
    if (front==-1 && rear==-1) {
        printf("Queue Underflow!\n");
        return -1;
    }
    element = queue[front];
    if (front==rear) {
        front = rear = -1;
    } else if (front==MAX_QUEUE_SIZE-1) {
        front = 0;
    } else {
        front++;
    }
    return element;
}

void printQueue() {
    int i;
    if (front==-1 && rear==-1) {
        printf("Queue Empty!\n");
        return;
    }
    printf("Front -> ");
    for (i=front; i!=rear; i=(i+1)%MAX_QUEUE_SIZE) {
        printf("%d ", queue[i]);
    }
    printf("%d ", queue[rear]);
    printf("<- Rear\n");
}

void clearQueue() {
    front = rear = -1;
}

int main() {
    int choice, element;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Clear Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                element = dequeue();
                if (element!=-1) {
                    printf("Dequeued element: %d\n", element);
                }
                break;
            case 3:
                printQueue();
                break;
            case 4:
                clearQueue();
                printf("Queue Cleared!\n");
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice!=0);

    return 0;
}