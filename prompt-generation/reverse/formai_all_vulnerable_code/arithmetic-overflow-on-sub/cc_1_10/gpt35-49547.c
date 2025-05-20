//FormAI DATASET v1.0 Category: Linked list operations ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create_list(struct node **head, int n);
void display(struct node *head);
void insert_beginning(struct node **head, int data);
void insert_end(struct node **head, int data);
void insert_middle(struct node **head, int data, int position);
void delete_node(struct node **head, int key);
void search(struct node *head, int data);

int main()
{
    struct node *head = NULL;
    int n, choice;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    create_list(&head, n);
    printf("\nLinked List: ");
    display(head);
    while(1)
    {
        printf("\n\n1. Insert at beginning\n2. Insert at end\n3. Insert at middle\n4. Delete a node\n5. Search\n6. Display\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                {
                    int data;
                    printf("Enter data: ");
                    scanf("%d", &data);
                    insert_beginning(&head, data);
                    printf("\nLinked List after insertion: ");
                    display(head);
                    break;
                }
            case 2:
                {
                    int data;
                    printf("Enter data: ");
                    scanf("%d", &data);
                    insert_end(&head, data);
                    printf("\nLinked List after insertion: ");
                    display(head);
                    break;
                }
            case 3:
                {
                    int data, position;
                    printf("Enter data and position: ");
                    scanf("%d%d", &data, &position);
                    insert_middle(&head, data, position);
                    printf("\nLinked List after insertion: ");
                    display(head);
                    break;
                }
            case 4:
                {
                    int key;
                    printf("Enter the element to be deleted: ");
                    scanf("%d", &key);
                    delete_node(&head, key);
                    printf("\nLinked List after deletion: ");
                    display(head);
                    break;
                }
            case 5:
                {
                    int data;
                    printf("Enter the element to be searched: ");
                    scanf("%d", &data);
                    search(head, data);
                    break;
                }
            case 6:
                {
                    printf("\nLinked List: ");
                    display(head);
                    break;
                }
            case 7:
                {
                    exit(0);
                }
            default:
                {
                    printf("\nInvalid choice!!!");
                }
        }
    }
    return 0;
}

void create_list(struct node **head, int n)
{
    int i, data;
    struct node *newnode, *temp;
    for(i=1;i<=n;i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        if(newnode == NULL)
        {
            printf("\nMemory cannot be allocated.");
            exit(0);
        }
        printf("Enter the element: ");
        scanf("%d", &data);
        newnode->data = data;
        if(*head == NULL)
        {
            *head = newnode;
            (*head)->next = NULL;
        }
        else
        {
            temp = *head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
        }
    }
}

void display(struct node *head)
{
    struct node *temp;
    if(head == NULL)
    {
        printf("\nThe list is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void insert_beginning(struct node **head, int data)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("\nMemory cannot be allocated.");
        exit(0);
    }
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}

void insert_end(struct node **head, int data)
{
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("\nMemory cannot be allocated.");
        exit(0);
    }
    newnode->data = data;
    newnode->next = NULL;
    if(*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insert_middle(struct node **head, int data, int position)
{
    struct node *newnode, *temp;
    int i;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("\nMemory cannot be allocated.");
        exit(0);
    }
    newnode->data = data;
    temp = *head;
    for(i=1;i<position-1;i++)
    {
        if(temp->next == NULL)
        {
            printf("\nThe position is out of range.");
            return;
        }
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_node(struct node **head, int key)
{
    struct node *temp, *prev;
    if(*head == NULL)
    {
        printf("\nThe list is empty.");
        return;
    }
    temp = *head;
    if(temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("\nThe element is not found.");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void search(struct node *head, int data)
{
    struct node *temp;
    int flag = 0, pos = 0;
    temp = head;
    while(temp != NULL)
    {
        pos++;
        if(temp->data == data)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if(flag == 1)
    {
        printf("\nThe element %d is found at position %d.", data, pos);
    }
    else
    {
        printf("\nThe element is not found.");
    }
}