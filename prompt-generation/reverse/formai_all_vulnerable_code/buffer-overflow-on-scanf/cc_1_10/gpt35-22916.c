//FormAI DATASET v1.0 Category: Memory management ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create_node(int data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
}

void display(struct node** head)
{
    struct node* temp = *head;
    printf("The list is: ");
    while(temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void insert(struct node** head, int data)
{
    struct node* new_node = create_node(data);
    if(*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        new_node -> next = *head;
        *head = new_node;
    }
}

void delete_node(struct node** head, int data)
{
    if(*head == NULL)
    {
        printf("List is empty. Deletion not possible.\n");
    }
    else
    {
        struct node* temp = *head;
        struct node* prev = *head;
        while(temp != NULL && temp -> data != data)
        {
            prev = temp;
            temp = temp -> next;
        }
        if(temp == NULL)
        {
            printf("Element not found in the list. Deletion not possible.\n");
        }
        else if(temp == *head)
        {
            *head = (*head) -> next;
            free(temp);
            temp = NULL;
        }
        else
        {
            prev -> next = temp -> next;
            free(temp);
            temp = NULL;
        }
    }
}

int main()
{
    struct node* head = NULL;
    int ch, data;
    while(1)
    {
        printf("\n1. Insert element\n2. Delete element\n3. Display list\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                printf("Enter element to be deleted: ");
                scanf("%d", &data);
                delete_node(&head, data);
                break;
            case 3:
                display(&head);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}