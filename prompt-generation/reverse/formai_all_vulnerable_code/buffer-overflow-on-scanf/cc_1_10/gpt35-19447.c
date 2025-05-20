//FormAI DATASET v1.0 Category: Linked list operations ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertAtBeginning(int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    new_node->data = data;
    new_node->next = NULL;
    if(head==NULL)
    {
        head = new_node;
        return;
    }
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void deleteFromBeginning()
{
    if(head==NULL)
    {
        printf("List is empty. Deletion failed!\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
}

void deleteFromEnd()
{
    if(head==NULL)
    {
        printf("List is empty. Deletion failed!\n");
        return;
    }
    struct node* temp = head;
    struct node* prev = NULL;
    if(head->next==NULL)
    {
        head = NULL;
        free(temp);
        return;
    }
    while(temp->next!=NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void display()
{
    struct node* temp = head;
    if(temp==NULL)
    {
        printf("List is empty. No elements to display!\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    printf("-----C Linked List Operations-----\n\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Delete from beginning\n");
    printf("4. Delete from end\n");
    printf("5. Display\n");
    int choice,data;
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter data: ");
                    scanf("%d",&data);
                    insertAtBeginning(data);
                    printf("Element inserted successfully at beginning!\n");
                    break;
            case 2: printf("Enter data: ");
                    scanf("%d",&data);
                    insertAtEnd(data);
                    printf("Element inserted successfully at end!\n");
                    break;
            case 3: deleteFromBeginning();
                    printf("Element deleted successfully from beginning!\n");
                    break;
            case 4: deleteFromEnd();
                    printf("Element deleted successfully from end!\n");
                    break;
            case 5: display();
                    break;
            default:printf("Invalid choice!\n");
                    break;
        }
    }
    return 0;
}