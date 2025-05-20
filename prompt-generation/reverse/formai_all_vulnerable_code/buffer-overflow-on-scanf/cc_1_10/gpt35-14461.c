//FormAI DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int num)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = num;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    printf("Queue is : \n");
    for (i = front; i <= rear; i++)
    {
        printf("%d \t", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice, num;

    while (1)
    {
        printf("\n");
        printf("1.Enqueue an element\n");
        printf("2.Dequeue an element\n");
        printf("3.Display the queue\n");
        printf("4.Quit\n");
        printf("\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be enqueued : ");
            scanf("%d", &num);
            enqueue(num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}