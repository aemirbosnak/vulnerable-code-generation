//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void insert(struct node** head, int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

void delete(struct node** head, int key)
{
    struct node* temp = *head;
    struct node* prev = NULL;
    while(temp!=NULL && temp->data!= key)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
        printf("Element not found in the Linked List");
    else
    {
        if(prev == NULL)
            *head = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }
}

void print(struct node* head)
{
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node* head = NULL;
    int key;
    printf("Enter the element to be inserted: ");
    scanf("%d",&key);
    insert(&head,key);
    printf("Linked List is:\n");
    print(head);
    printf("\nEnter the element to be deleted: ");
    scanf("%d",&key);
    delete(&head,key);
    printf("Linked List after deletion is:\n");
    print(head);
    return 0;
}