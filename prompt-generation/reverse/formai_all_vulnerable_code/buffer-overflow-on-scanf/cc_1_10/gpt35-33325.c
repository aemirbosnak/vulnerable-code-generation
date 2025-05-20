//FormAI DATASET v1.0 Category: Queue Implementation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void insert()
{
    int item;
    printf("Enter a puzzle piece to add to the queue: ");
    scanf("%d",&item);
    if (rear == MAX - 1)
        printf("Queue Overflow!\n");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
        printf("Item inserted successfully!\n");
    }
}

void delete()
{
    if (front == -1 || front > rear)
        printf("Queue Underflow!\n");
    else
    {
        printf("Puzzle piece %d removed from the queue\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty!\n");
    else
    {
        printf("Current puzzle pieces in the queue: ");
        for (i=front; i<=rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice;
    printf("This program represents a puzzle queue\n\n");
    printf("1) Add a puzzle piece to the queue\n");
    printf("2) Remove next puzzle piece from the queue\n");
    printf("3) View current puzzle pieces in the queue\n");
    printf("4) Exit\n");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 4);
    return 0;
}