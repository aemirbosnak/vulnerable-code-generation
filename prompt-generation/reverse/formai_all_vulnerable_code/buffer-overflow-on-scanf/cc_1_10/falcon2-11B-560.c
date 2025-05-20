//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: mathematical
//A simple linked list program in C
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Function to create a new node
struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display linked list
void display(struct node* head)
{
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to insert a new node at the beginning of the list
void insert(struct node** head_ref, int new_data)
{
    struct node* new_node = createNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to insert a new node at the end of the list
void append(struct node** head_ref, int new_data)
{
    struct node* new_node = createNode(new_data);
    struct node* temp = *head_ref;
    while(temp->next!= NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to delete a node from the list
void delete(struct node** head_ref, int data)
{
    struct node* temp = *head_ref;
    if(temp->data == data)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp->next!= NULL && temp->next->data!= data)
    {
        temp = temp->next;
    }
    if(temp->next == NULL)
    {
        printf("Data not found in list");
    }
    else
    {
        temp->next = temp->next->next;
    }
}

// Function to search a node in the list
int search(struct node* head, int data)
{
    struct node* temp = head;
    while(temp!= NULL && temp->data!= data)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    struct node* head = NULL;
    int choice, data, flag;

    printf("1. Create a new node\n2. Display linked list\n3. Insert a new node at the beginning\n4. Append a new node at the end\n5. Delete a node from the list\n6. Search a node in the list\n7. Exit\n\n");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter data for new node: ");
                        scanf("%d", &data);
                        insert(&head, data);
                        break;
            case 2: display(head);
                        break;
            case 3: printf("Enter data for new node: ");
                        scanf("%d", &data);
                        append(&head, data);
                        break;
            case 4: printf("Enter data for new node: ");
                        scanf("%d", &data);
                        append(&head, data);
                        break;
            case 5: printf("Enter data to delete: ");
                        scanf("%d", &data);
                        delete(&head, data);
                        break;
            case 6: printf("Enter data to search: ");
                        scanf("%d", &data);
                        flag = search(head, data);
                        if(flag == 1)
                        {
                            printf("%d found in list\n", data);
                        }
                        else
                        {
                            printf("%d not found in list\n", data);
                        }
                        break;
            case 7: printf("Exiting...\n");
                        exit(0);
                        break;
            default: printf("Invalid choice\n");
                        break;
        }
    } while(choice!= 7);
    return 0;
}