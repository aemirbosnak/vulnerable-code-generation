//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->next = NULL;

    if (rear == NULL)
        front = rear = newnode;
    else
        rear->next = newnode;

    rear = newnode;
}

void dequeue()
{
    struct node *temp = front;

    if (front == NULL)
        printf("\nQueue is empty");
    else
    {
        printf("\nDeleted element is %d", front->data);
        front = front->next;
        free(temp);
    }

    if (front == NULL)
        rear = NULL;
}

void display()
{
    struct node *temp = front;

    if (front == NULL)
        printf("\nQueue is empty");
    else
    {
        printf("\nElements in the queue are: ");
        while (temp!= NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice, x;

    printf("\nMENU");
    printf("\n1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Display");
    printf("\n4. Exit");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the element to be added: ");
            scanf("%d", &x);
            enqueue(x);
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
            printf("\nInvalid choice");
        }
    }
}