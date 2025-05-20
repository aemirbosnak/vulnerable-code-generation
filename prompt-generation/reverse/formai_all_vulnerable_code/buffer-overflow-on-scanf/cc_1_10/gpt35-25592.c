//FormAI DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (rear == SIZE - 1)
    {
        printf("Sorry! Queue overflow.\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = data;
    }
}

int dequeue()
{
    int data;
    if (front == -1 || front > rear)
    {
        printf("Sorry! Queue underflow.\n");
        return -1;
    }
    else
    {
        data = queue[front];
        front++;
        return data;
    }
}

void display()
{
    int i;
    if (front == -1 || front > rear)
    {
        printf("Sorry! Queue is empty.\n");
    }
    else
    {
        printf("Queue elements are: ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, data;

    printf("Welcome to the immersive Queue Program!\n");

    do
    {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
            {
                printf("Dequeued element is: %d\n", data);
            }
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Thank you for using the program!\n");
            break;

        default:
            printf("Sorry! Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}