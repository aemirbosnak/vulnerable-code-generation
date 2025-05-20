//FormAI DATASET v1.0 Category: Queue ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data);
int dequeue();
int isFull();
int isEmpty();
void display();

int main()
{
    int choice, data;
    
    do
    {
        printf("\n\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                printf("\nDequeued %d", dequeue());
                break;
            case 3: 
                display();
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while (1);

    return 0;
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("\nQueue is full. Cannot enqueue.");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = data;

    printf("\nEnqueued %d", data);
}

int dequeue()
{
    if (isEmpty())
    {
        printf("\nQueue is empty. Cannot dequeue.");
        return -1;
    }

    int data = queue[front];
    front++;

    if (front > rear)
        front = rear = -1;

    return data;
}

int isFull()
{
    if (rear == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

void display()
{
    if (isEmpty())
    {
        printf("\nQueue is empty.");
        return;
    }

    printf("\nQueue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}