//FormAI DATASET v1.0 Category: Queue Implementation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10    

int cqueue[MAX_SIZE], front = -1, rear = -1;

void insert(int element);
int delete();
void display();

int main()
{
    int choice, element;
    while(1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice(1-4) : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert(element);
                break;
            case 2:
                printf("Element deleted is %d\n", delete());
                break;
            case 3:
                printf("Elements in the circular queue are: \n");
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void insert(int element)
{
    if((front == 0 && rear == MAX_SIZE-1) || (front == rear+1))
    {
        printf("Queue overflow\n");
        return;
    }

    if(front == -1) 
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if(rear == MAX_SIZE-1) 
            rear = 0;
        else
            rear = rear+1;
    }
    cqueue[rear] = element;
}

int delete()
{
    if(front == -1)
    {
        printf("Queue underflow\n");
        return -1;
    }

    int element = cqueue[front];
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if(front == MAX_SIZE-1)
            front = 0;
        else
            front = front+1;
    }
    return element;
}

void display()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    int i;
    if(front <= rear)
    {
        for(i = front; i <= rear; i++)
            printf("%d ",cqueue[i]);
    }
    else
    {
        for(i = front; i < MAX_SIZE; i++)
            printf("%d ", cqueue[i]);
        for(i = 0; i <= rear; i++)
            printf("%d ", cqueue[i]);
    }
    printf("\n");
}