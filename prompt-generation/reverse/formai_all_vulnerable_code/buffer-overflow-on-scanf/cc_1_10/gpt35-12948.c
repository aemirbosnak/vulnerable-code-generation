//FormAI DATASET v1.0 Category: Linked list operations ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
}node;

node *create_linked_list(node *head, int n)
{
    node *new_node, *temp;
    int i;

    for(i=1;i<=n;i++)
    {
        new_node=(node*)malloc(sizeof(node));
        printf("Enter the data for node number %d: ",i);
        scanf("%d",&new_node->data);
        new_node->next=NULL;

        if(head==NULL)
        {
            head=temp=new_node;
        }
        else
        {
            temp->next=new_node;
            temp=new_node;
        }
    }
    return head;
}

void display_linked_list(node *head)
{
    printf("\n\n");
    while(head)
    {
        printf("%d --> ",head->data);
        head=head->next;
    }
    printf("NULL\n\n");
}

node *insert_at_beginning(node *head)
{
    node *new_node;
    new_node=(node*)malloc(sizeof(node));
    printf("Enter the data for the new node: ");
    scanf("%d",&new_node->data);
    new_node->next=head;
    head=new_node;
    return head;
}

node *insert_at_end(node *head)
{
    node *new_node, *temp;
    new_node=(node*)malloc(sizeof(node));
    printf("Enter the data for the new node: ");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    return head;    
}

node *delete_at_beginning(node *head)
{
    node *temp;
    if(head==NULL)
    {
        printf("\n\nList is Empty!!!\n\n");
        return head;
    }
    else
    {
        temp=head;
        head=temp->next;
        free(temp);
    }
    return head;    
}

node *delete_at_end(node *head)
{
    node *temp, *temp1;
    if(head==NULL)
    {
        printf("\n\nList is Empty!!!\n\n");
        return head;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        free(temp);
    }
    return head;    
}

int main()
{
    int n, choice;
    node *head=NULL;

    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    head=create_linked_list(head, n);

    while(1)
    {
        printf("1. Display Linked List\n");
        printf("2. Insert a node at the beginning of the Linked List\n");
        printf("3. Insert a node at the end of the Linked List\n");
        printf("4. Delete a node from the beginning of the Linked List\n");
        printf("5. Delete a node from the end of the Linked List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                display_linked_list(head);
                break;

            case 2:
                head=insert_at_beginning(head);
                display_linked_list(head);
                break;

            case 3:
                head=insert_at_end(head);
                display_linked_list(head);
                break;

            case 4:
                head=delete_at_beginning(head);
                display_linked_list(head);
                break;

            case 5:
                head=delete_at_end(head);
                display_linked_list(head);
                break;    

            case 6:
                exit(0);

            default:
                printf("\n\nInvalid Choice!!!\n\n");
                break;                    
        }
    }
    return 0;
}