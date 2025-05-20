//FormAI DATASET v1.0 Category: Queue ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

int isFull()
{
    return (rear == MAX_QUEUE_SIZE - 1);
}

int isEmpty()
{
    return (front == -1 || front > rear);
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue Overflow!\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = data;
}

int dequeue()
{
    int data;

    if (isEmpty())
    {
        printf("Queue Underflow!\n");
        return -1;
    }

    data = queue[front];
    front++;

    return data;
}

void display()
{
    int i;

    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue contents: ");
    
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            data = dequeue();
            if (data != -1)
                printf("Dequeued element: %d\n", data);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}