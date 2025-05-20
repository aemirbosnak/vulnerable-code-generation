//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define MAX 100

int arr[MAX];
int front = -1, rear = -1;

void enqueue(int element)
{
    if (rear == MAX - 1)
        printf("\nQueue Overflow");
    else if (front == -1)
        front = 0;
    rear++;
    arr[++rear] = element;
}

void dequeue()
{
    if (front == -1 || front > rear)
        printf("\nQueue Underflow");
    else
        front++;
}

void display()
{
    printf("\n\nThe elements in the queue are:");
    if (front <= rear)
        for (int i = front; i <= rear; i++)
            printf("\t%d", arr[i]);
    else
        for (int i = front; i <= MAX - 1; i++)
            printf("\t%d", arr[i]);
    for (int i = 0; i <= rear; i++)
        printf("\t%d", arr[i]);
}

void main()
{
    int choice, element;

    printf("\n\nMENU");
    printf("\n1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Display");
    printf("\n4. Exit");

    do
    {
        printf("\n\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter the element to be added to the queue:");
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
                printf("\n\nInvalid choice. Please try again. ");
        }
    } while (choice!= 4);
}