//FormAI DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value);
void dequeue();
void display();

int main()
{
    int choice, value;
    printf("\nWelcome to artistic Queue implementation!\n");
    printf("***************************************\n");

    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n**********\n");
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueue(value);
                printf("\n%s %d %s", "Value", value, "is inserted in the Queue.\n");
                printf("\n**********\n");
                break;
                
            case 2:
                dequeue();
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                printf("\nThank you for using the artistic Queue implementation!\n");
                printf("*****************************************************\n");
                break;
                
            default:
                printf("\nInvalid choice. Please try again!\n");
        }
    } while (choice != 4);

    return 0;
}

void enqueue(int value)
{
    if(rear == SIZE-1)
    {
        printf("\n%s", "Queue Overflow!\n");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("\n%s", "Queue Underflow!\n");
    }
    else
    {
        printf("\n%s %d %s", "Value", queue[front], "is deleted from the Queue.\n");
        front++;
    }
}

void display()
{
    if(front == -1 || front > rear)
    {
        printf("\n%s", "Queue is empty!\n");
    }
    else
    {
        int i;
        printf("\n%s\n", "Elements in the Queue:");
        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}