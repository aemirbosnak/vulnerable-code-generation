//FormAI DATASET v1.0 Category: Linked list operations ; Style: retro
#include<stdio.h>
#include<stdlib.h>

//structure for the linked list node
typedef struct Node 
{
    int data;
    struct Node *next;
}Node;

//function to add a node at the beginning of the linked list
void insertAtBeginning(Node **head, int newData)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = (*head);
    (*head) = newNode;
}

//function to add a node at the end of the linked list
void insertAtEnd(Node **head, int newData)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    Node *tail = *head;
    newNode->data = newData;
    newNode->next = NULL;
    
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    while(tail->next!=NULL)
    {
        tail = tail->next;
    }
    
    tail->next = newNode;
}

//function to delete a node from the beginning of the linked list
void deleteFromBeginning(Node **head)
{
    if(*head == NULL)
    {
        printf("\nList is empty! Cannot delete.\n");
        return;
    }
    
    Node *temp = *head;
    *head = (*head)->next;
    printf("\nDeleted node with data: %d\n",temp->data);
    free(temp);
}

//function to delete a node from the end of the linked list
void deleteFromEnd(Node **head)
{
    if(*head == NULL)
    {
        printf("\nList is empty! Cannot delete.\n");
        return;
    }
    
    Node *temp = *head;
    Node *prev = NULL;
    while(temp->next!=NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    
    if(prev == NULL)
    {
        *head = NULL;
    }
    else
    {
        prev->next = NULL;
    }
    printf("\nDeleted node with data: %d\n",temp->data);
    free(temp);
}

//function to display the linked list
void display(Node *head)
{
    if(head==NULL)
    {
         printf("\nList is empty!\n");
         return;
    }
    
    printf("\nLinked List: ");
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}

//main function
int main()
{
    Node *head = NULL;
    int choice = 0, data = 0;
    printf("\n******** Retro Linked List Operations *********\n");
    do
    {
        printf("\n******** Menu *********\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                printf("\nEnter data to be inserted at beginning: ");
                scanf("%d",&data);
                insertAtBeginning(&head,data);
                break;
            
            case 2:
                printf("\nEnter data to be inserted at end: ");
                scanf("%d",&data);
                insertAtEnd(&head,data);
                break;
                
            case 3:
                deleteFromBeginning(&head);
                break;
            
            case 4:
                deleteFromEnd(&head);
                break;
            
            case 5:
                display(head);
                break;
            
            case 6:
                printf("\nExiting program...\n");
                exit(0);
                break;
            
            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
                break;
        }
        
    }while(1);
    
    return 0;
}