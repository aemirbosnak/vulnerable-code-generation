//FormAI DATASET v1.0 Category: Queue ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Size of queue

int front = -1, rear = -1;
int queue[SIZE];

void enqueue(int element);
void dequeue();
void display();

int main()
{
    int choice, element;

    while (1)
    {
        printf("\n-----MENU-----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter the element to add: ");
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
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

void enqueue(int element)
{
    if (rear == SIZE - 1)
    {
        printf("\nQueue is full! Cannot insert any more elements.\n");
        return;
    }

    if (front == -1) // First element in the queue
        front = 0;

    rear++;
    queue[rear] = element;
    printf("\nElement %d enqueued successfully!\n", element);
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty! Cannot dequeue any elements.\n");
        return;
    }

    printf("\nElement %d dequeued successfully!\n", queue[front]);
    front++;

    if (front > rear)
        front = rear = -1;
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty! Nothing to display.\n");
        return;
    }

    printf("\nCurrent queue contents: ");

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}