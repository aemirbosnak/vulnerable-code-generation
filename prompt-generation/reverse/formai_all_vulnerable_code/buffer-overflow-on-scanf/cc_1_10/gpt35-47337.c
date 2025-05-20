//FormAI DATASET v1.0 Category: Queue Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int head = -1;
int tail = -1;

void enqueue(int value);
int dequeue();
int peek();
int isFull();
int isEmpty();

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n");
        printf("1 - Enqueue\n");
        printf("2 - Dequeue\n");
        printf("3 - Peek\n");
        printf("4 - Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                if (!isFull())
                {
                    enqueue(value);
                    printf("\nValue enqueued successfully!\n");
                }
                else
                {
                    printf("\nQueue is full, cannot enqueue value!\n");
                }
                break;
            }
            case 2:
            {
                if (!isEmpty())
                {
                    int value = dequeue();
                    printf("\nValue dequeued: %d", value);
                }
                else
                {
                    printf("\nQueue is empty, cannot dequeue value!\n");
                }
                break;
            }
            case 3:
            {
                if (!isEmpty())
                {
                    int value = peek();
                    printf("\nThe value at the front of the queue is: %d", value);
                }
                else
                {
                    printf("\nQueue is empty, cannot peek value!\n");
                }
                break;
            }
            case 4:
            {
                printf("\nExiting program...\n");
                exit(0);
            }
            default:
            {
                printf("\nInvalid choice, please try again!\n");
                break;
            }
        }
    }
}

void enqueue(int value)
{
    if (head == -1)
    {
        head = 0;
    }
    tail = (tail + 1) % MAX_SIZE;
    queue[tail] = value;
}

int dequeue()
{
    int value = queue[head];
    if (head == tail)
    {
        head = -1;
        tail = -1;
    }
    else
    {
        head = (head + 1) % MAX_SIZE;
    }
    return value;
}

int peek()
{
    int value = queue[head];
    return value;
}

int isFull()
{
    if ((tail + 1) % MAX_SIZE == head)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (head == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}