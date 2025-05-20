//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;

Node* head = NULL;

void enqueue(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(head == NULL)
    {
        head = newNode;
        head->data = data;
        head->next = NULL;
    }
    else
    {
        Node* temp = head;
        while(temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->data = data;
        newNode->next = NULL;
    }
}

int dequeue()
{
    if(head == NULL)
    {
        return -1;
    }
    else
    {
        Node* temp = head;
        head = head->next;
        free(temp);
        return temp->data;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements to be enqueued: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        enqueue(i);
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ",dequeue());
    }
    return 0;
}