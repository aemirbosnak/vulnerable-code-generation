//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL,*temp,*newNode;

int main()
{
    int choice,data,pos;

    do
    {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                newNode=(struct node*)malloc(sizeof(struct node));
                newNode->data=data;
                newNode->next=head;
                head=newNode;
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d",&data);
                newNode=(struct node*)malloc(sizeof(struct node));
                newNode->data=data;
                temp=head;
                while(temp->next!=NULL)
                    temp=temp->next;
                temp->next=newNode;
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d",&pos);
                newNode=(struct node*)malloc(sizeof(struct node));
                newNode->data=data;
                temp=head;
                for(int i=0;i<pos-1;i++)
                    temp=temp->next;
                newNode->next=temp->next;
                temp->next=newNode;
                break;

            case 4:
                temp=head;
                if(temp==NULL)
                    printf("List is empty\n");
                else
                {
                    head=head->next;
                    free(temp);
                }
                break;

            case 5:
                temp=head;
                if(temp==NULL)
                    printf("List is empty\n");
                else
                {
                    while(temp->next!=NULL)
                        temp=temp->next;
                    head=temp->next;
                    free(temp);
                }
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d",&pos);
                temp=head;
                for(int i=0;i<pos-1;i++)
                    temp=temp->next;
                if(temp->next==NULL)
                    printf("Data not found\n");
                else
                {
                    temp->next=temp->next->next;
                    free(temp->next);
                }
                break;

            case 7:
                temp=head;
                while(temp!=NULL)
                {
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
                printf("\n");
                break;

            case 8:
                printf("Enter data to search: ");
                scanf("%d",&data);
                temp=head;
                while(temp!=NULL)
                {
                    if(temp->data==data)
                        printf("Data found at position %d\n",temp-head);
                    else
                        printf("Data not found\n");
                    temp=temp->next;
                }
                break;

            case 9:
                exit(0);
        }

    }while(choice!=9);

    return 0;
}