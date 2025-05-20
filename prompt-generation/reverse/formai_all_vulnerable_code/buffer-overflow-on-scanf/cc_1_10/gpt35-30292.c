//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

int front = -1, rear = -1;
int queue[MAX_QUEUE_SIZE];

void enqueue(int element) {
    if (rear == MAX_QUEUE_SIZE-1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) 
        front = 0;
    rear++;
    queue[rear] = element;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    int dequeue_element = queue[front];
    front++;
    return dequeue_element;
}

int peek() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front];
}

int isEmpty() {
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue Element(s): ");
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("\n---------------- Queue Menu ----------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("---------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &element);
                enqueue(element);
                display();
                break;
            case 2:
                element = dequeue();
                if (element != -1)
                    printf("Dequeued Element: %d\n", element);
                display();
                break;
            case 3:
                element = peek();
                if (element != -1)
                    printf("Front of Queue Element: %d\n", element);
                else
                    printf("Queue is Empty\n");
                break;
            case 4:
                if (isEmpty())
                    printf("Queue is Empty\n");
                else
                    printf("Queue is Not Empty\n");
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try Again.\n");
        }
    }
    return 0;
}