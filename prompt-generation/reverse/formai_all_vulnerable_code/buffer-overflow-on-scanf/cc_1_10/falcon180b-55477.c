//Falcon-180B DATASET v1.0 Category: Data mining ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insertNode(struct node* head, int data)
{
    struct node* newNode = createNode(data);
    struct node* temp = head;
    if(head == NULL)
    {
        head = newNode;
        return head;
    }
    while(temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(struct node* head)
{
    struct node* temp = head;
    while(temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n, i, data;
    struct node* head = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &data);
        head = insertNode(head, data);
    }
    printf("The list is: ");
    printList(head);
    return 0;
}