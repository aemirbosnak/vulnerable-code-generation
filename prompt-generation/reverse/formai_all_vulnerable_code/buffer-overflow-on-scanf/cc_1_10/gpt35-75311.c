//FormAI DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

void insert(int element)
{
    if(rear == MAX_SIZE - 1)
    {
        printf("\nQueue is full. Cannot insert %d\n", element);
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
        rear++;
    queue[rear] = element;
    printf("\n%d inserted into queue\n", element);
}

void delete()
{
    int element;
    if(front == -1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    element = queue[front];
    if(front == rear)
        front = rear = -1;
    else
        front++;
    printf("\n%d deleted from queue\n", element);
}

void display()
{
    int i;
    if(front == -1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nElements in queue are:\n");
    for(i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main()
{
    int choice, element;
    do
    {
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n********** C QUEUE IMPLEMENTATION **********\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &element);
                insert(element);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
        }
    }while(choice != 4);
    return 0;
}