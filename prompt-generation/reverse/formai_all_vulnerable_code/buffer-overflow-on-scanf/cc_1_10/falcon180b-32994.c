//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
    int data;
    struct node *next;
};

void addNode(struct node **head, int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
        return;
    }

    struct node *temp = *head;

    while(temp->next!= NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

void printList(struct node *head)
{
    struct node *temp = head;

    while(temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void timeTravel(struct node *head, int pos, int year)
{
    if(head == NULL)
        return;

    if(pos == 0)
    {
        printf("\nYou have reached the beginning of time (%d)!\n", year);
        return;
    }

    pos--;
    timeTravel(head, pos, year);
}

int main()
{
    struct node *head = NULL;
    int choice, data, pos, year;

    do
    {
        printf("\n1. Add element\n2. Print list\n3. Time travel\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;

            case 2:
                printf("List: ");
                printList(head);
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter year: ");
                scanf("%d", &year);
                timeTravel(head, pos, year);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }while(choice!= 4);

    return 0;
}