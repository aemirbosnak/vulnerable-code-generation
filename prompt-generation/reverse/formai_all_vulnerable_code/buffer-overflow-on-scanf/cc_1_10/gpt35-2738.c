//FormAI DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;
Node *head=NULL;

void insert(int x)
{
    if(head==NULL)
    {
        head=(Node*)malloc(sizeof(Node));
        head->data=x;
        head->next=NULL;
        printf("Element inserted\n");
        return;
    }
    if (x<head->data)
    {
        Node* temp=(Node*)malloc(sizeof(Node));
        temp->data=x;
        temp->next=head;
        head=temp;
        printf("Element inserted\n");
        return;
    }
    else
    {
        Node* current=head;
        while (current->next!=NULL && current->next->data<=x)
        {
            current=current->next;
        }
        Node* temp=(Node*)malloc(sizeof(Node));
        temp->data=x;
        temp->next=current->next;
        current->next=temp;
        printf("Element inserted\n");
        return;
    }
}

void delete()
{
    int x;
    if (head==NULL)
    {
        printf("Queue underflow\n");
        return;
    }
    Node* temp=head;
    x=temp->data;
    head=head->next;
    free(temp);
    printf("%d deleted\n",x);
    return;
}

int main()
{
    int choice, x;
    printf("Enter choice\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter element to be inserted\n");
                scanf("%d",&x);
                insert(x);
                main();
        case 2: delete();
                main();
        case 3: printf("Exiting program\n");
                break;
        default: printf("Invalid choice\n");
                 main();
    }
    return 0;
}