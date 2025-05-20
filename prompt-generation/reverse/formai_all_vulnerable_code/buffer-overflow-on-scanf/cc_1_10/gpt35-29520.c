//FormAI DATASET v1.0 Category: Queue ; Style: innovative
/* Queue implementation using Circular Array */
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % MAX_SIZE == front)
    {
        printf("Error: Queue is full!\n");
        return;
    }
    if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX_SIZE;
    queue[rear] = value;
    printf("Element %d has been enqueued to the queue!\n", value);
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Error: Queue is empty!\n");
        return;
    }
    int temp = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;
    printf("Element %d has been dequeued from the queue!\n", temp);
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Error: Queue is empty!\n");
        return;
    }
    printf("Elements of the queue are:\n");
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main()
{
    int choice, value;
    do
    {
        printf("\n");
        printf("***Circular Queue Operations***\n");
        printf("1. Enqueue Element\n");
        printf("2. Dequeue Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("--------------------------------\n");
        printf("Enter your choice(1-4): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exit!\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
        printf("\n");
    } while (choice != 4);
    return 0;
}