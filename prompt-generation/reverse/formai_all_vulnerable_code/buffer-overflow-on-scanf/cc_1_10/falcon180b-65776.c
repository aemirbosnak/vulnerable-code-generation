//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

Node *createNode(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

Node *insertNode(Node *head, int data)
{
    Node *newnode = createNode(data);
    newnode->next = head;
    return newnode;
}

void printList(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int searchNode(Node *head, int data)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        if(temp->data == data)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{
    Node *head = NULL;
    int choice, data;

    while(1)
    {
        printf("\nEnter your choice:\n1. Insert Node\n2. Search Node\n3. Print List\n4. Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the data to be inserted: ");
                scanf("%d",&data);
                head = insertNode(head,data);
                break;

            case 2:
                printf("\nEnter the data to be searched: ");
                scanf("%d",&data);
                if(searchNode(head,data))
                {
                    printf("\nNode found!\n");
                }
                else
                {
                    printf("\nNode not found!\n");
                }
                break;

            case 3:
                printf("\nList of nodes:\n");
                printList(head);
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice! Please enter again.\n");
        }
    }

    return 0;
}