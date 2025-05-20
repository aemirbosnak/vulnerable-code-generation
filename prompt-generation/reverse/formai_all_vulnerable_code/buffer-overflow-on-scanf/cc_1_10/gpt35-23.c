//FormAI DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

// Define a structure for a node in the Linked List
struct Node
{
    int data;
    struct Node* next;
};

// Function to add element at front of the linked list
void add_at_front(struct Node** head, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to add element at end of the linked list
void add_at_end(struct Node** head, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    struct Node* temp = *head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
}

// Function to delete the first occurrence of a given element from the linked list
void delete_element(struct Node** head, int key)
{
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) 
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

    if(temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void display(struct Node* head)
{
    if(head == NULL)
    {
        printf("\nThe Linked List is empty\n\n");
        return;
    }

    struct Node* temp = head;

    printf("\nThe Linked List is:\n");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n\n");
}

// Driver program to test the linked list operations
int main()
{
    struct Node* head = NULL;
    int data, ch, key;

    do
    {
        printf("Choose an option:\n1. Add element at front\n2. Add element at end\n3. Delete an element\n4. Display the linked list\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter the element to be added at front: ");
                scanf("%d", &data);
                add_at_front(&head, data);
                display(head);
                break;

            case 2:
                printf("\nEnter the element to be added at end: ");
                scanf("%d", &data);
                add_at_end(&head, data);
                display(head);
                break;

            case 3:
                printf("\nEnter the element to be deleted: ");
                scanf("%d", &key);
                delete_element(&head, key);
                display(head);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("\nThanks for using the program!\n\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n\n");
        }

    }while(1);

    return 0;
}