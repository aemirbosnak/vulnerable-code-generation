//FormAI DATASET v1.0 Category: Linked list operations ; Style: automated
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void insert_beg()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}

void insert_end()
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}

void delete_beg()
{
    struct node *temp;
    if(head==NULL)
        printf("\nList is empty.");
    else
    {
        temp=head;
        head=temp->next;
        free(temp);
    }
}

void delete_end()
{
    struct node *temp,*prev;
    if(head==NULL)
        printf("\nList is empty.");
    else if(head->next==NULL)
    {
        temp=head;
        head=NULL;
        free(temp);
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    if(head==NULL)
        printf("\nList is empty.");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n\n----Menu----");
        printf("\n1.Insert at beginning\n2.Insert at end\n3.Delete from beginning\n4.Delete from end\n5.Display\n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert_beg();
                    break;
            case 2: insert_end();
                    break;
            case 3: delete_beg();
                    break;
            case 4: delete_end();
                    break;
            case 5: display();
                    break;
            case 6: exit(0);
            default: printf("\nInvalid choice!");
        }
    }
    return 0;
}