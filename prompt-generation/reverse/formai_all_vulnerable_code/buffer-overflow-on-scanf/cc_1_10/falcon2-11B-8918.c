//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct linkedlist
{
    node *head;
    node *tail;
}linkedlist;

void insert_node(linkedlist *ll, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (ll->head == NULL)
    {
        ll->head = new_node;
        ll->tail = new_node;
    }
    else
    {
        ll->tail->next = new_node;
        ll->tail = new_node;
    }
}

void display(linkedlist *ll)
{
    node *temp = ll->head;

    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    linkedlist *ll = (linkedlist *)malloc(sizeof(linkedlist));
    int n, data;
    char choice;

    printf("Linked List Operations\n");
    printf("1. Insert a node\n");
    printf("2. Display Linked List\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice!= 3)
    {
        switch (choice)
        {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insert_node(ll, data);
                break;
            case 2:
                display(ll);
                break;
            case 3:
                printf("Thank you for using our program!\n");
                break;
            default:
                printf("Invalid input, please try again!\n");
        }
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}